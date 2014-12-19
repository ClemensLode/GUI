#if defined(_FMOD_SOUND) || defined(_SDL_MIXER_SOUND)
#define MUSIC_TRANSITION_DURATION 2000

#ifdef _FMOD_SOUND
#include <fmod.hpp>
#include <fmod_errors.h>
#endif

#include "soundprocessor.hpp"
#include <misc/exceptions.hpp>
#include <misc/log.hpp>
#include <misc/ids.hpp>

#include <lang/text_storage.hpp>

#define MUSIC_TRANSITION_DURATION 2000

SoundProcessor::SoundProcessor(const boost::shared_ptr<const SoundConfiguration> soundConfiguration):
	soundConfiguration(soundConfiguration),
	soundInitialized(false)
#ifdef _FMOD_SOUND
	,soundEngine(NULL),
	musicChannel(NULL)
#endif
{
	// ------ INIT SOUND ENGINE -------
	if(soundConfiguration->isSound() || soundConfiguration->isMusic())
	{		
		try {
			initSoundEngine();
			soundInitialized = true;
		} catch(SDLException e) {
			toDebugLog("Could not initialize sound engine.");
			soundInitialized = false;
		}
	} else {
		toInfoLog(TextStorage::instance().get(IDS::START_INIT_NOSOUND_TEXT_ID)->getText());
	}
	// ------ END INIT SOUND ENGINE -------
	printSoundInformation();
}


SoundProcessor::~SoundProcessor() {
	releaseSoundEngine();
}



#ifdef _SDL_MIXER_SOUND

void transitionMusic(void)
{
	SoundProcessor::transitionMusic();
}

void soundChannelDone(int channel)
{
	SoundProcessor::soundChannelDone(channel);
}

// callback function
void SoundProcessor::transitionMusic(void)
{
	if(currentMusic != NULL)
	{
		Mix_HaltMusic(); // Just in case there was a misunderstanding, halt the music
		Mix_FreeMusic(currentMusic);
		currentMusic = nextMusic;
		nextMusic = NULL;
		if(currentMusic != NULL)
		{
			int success = Mix_FadeInMusic(currentMusic, -1, MUSIC_TRANSITION_DURATION/2);
			if(success != 0) {
				std::ostringstream os;
				os << "ERROR (SoundProcessor::playMusic()): " << Mix_GetError();
				throw SDLException(os.str());
			}
		}
	}
}

void SoundProcessor::soundChannelDone(int channel)
{
	for(std::list<int>::iterator i = soundChannel.begin(); i != soundChannel.end();)
	{
		if(*i == channel) {
			i = soundChannel.erase(i);
		}
		else ++i;
	}
}

#endif


void SoundProcessor::initSoundEngine()
{
	// TODO start a 'watchdog' thread (FMOD waits indefinitely if the sound is currently used!)
	toInfoLog(TextStorage::instance().get(IDS::START_INIT_SOUND_TEXT_ID)->getText());

#ifdef _FMOD_SOUND
	unsigned int version;

	if(!ERRCHECK(FMOD::System_Create(&soundEngine))) { 
		throw SDLException(TextStorage::instance().get(IDS::START_INIT_FMOD_SYSTEM_CREATE_ERROR_TEXT_ID)->getText());
	}

	BOOST_ASSERT(soundEngine);
	if(!ERRCHECK(soundEngine->getVersion(&version))) {
		throw SDLException(TextStorage::instance().get(IDS::START_INIT_FMOD_GET_VERSION_ERROR_TEXT_ID)->getText());
	}

	if (version < FMOD_VERSION)
	{
		std::ostringstream os;
		os << TextStorage::instance().get(IDS::START_INIT_FMOD_VERSION_ERROR_TEXT_ID)->getText() << "[" << version << " < " << FMOD_VERSION << "]";
		throw SDLException(os.str());
	}

	printSoundInformation();

	if(!ERRCHECK(soundEngine->init(32, FMOD_INIT_NORMAL, 0))) {
		throw SDLException(TextStorage::instance().get(IDS::START_INIT_FMOD_SYSTEM_INIT_ERROR_TEXT_ID)->getText());
	}
#elif _SDL_MIXER_SOUND
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048)==-1) 
	{
		std::ostringstream os;
		os << "ERROR (SoundProcessor::initSoundEngine()): " << Mix_GetError();
		throw SDLException(os.str());
	}		
	Mix_ChannelFinished(::soundChannelDone);
	
	/*
	int flags = MIX_INIT_MP3; // TODO MOD!
	int initted = Mix_Init(flags);
	if(initted&flags != flags) {
		std::ostringstream os;
		os << "ERROR (SoundProcessor::initSoundEngine()): " << Mix_GetError();
		throw SDLException(os.str());
	}*/

#endif
	soundInitialized = true;
}

void SoundProcessor::setSoundConfiguration(const boost::shared_ptr<const SoundConfiguration> soundConfiguration)
{
	this->soundConfiguration = soundConfiguration;

	// ------ SOUND ENGINE -------
	if((soundConfiguration->isSound() || soundConfiguration->isMusic()) && (!soundInitialized))
	{
		try {
			initSoundEngine();
		} catch(SDLException e) {
			soundInitialized = false;
			toInfoLog(TextStorage::instance().get(IDS::START_INIT_NOSOUND_TEXT_ID)->getText());
		}
	} else if(!soundConfiguration->isSound() && !soundConfiguration->isMusic() && soundInitialized) {
		// sound was deactivated
		releaseSoundEngine();
	} else 
		if(!soundInitialized) {
			if(!soundConfiguration->isMusic()) {
				stopMusic();
			}

			if(soundConfiguration->isSound()) {
				process();
			} else {
				clearSoundChannels();
			}
#ifdef _FMOD_SOUND
			soundEngine->update();
#endif
		}
		clearSoundsToPlay();
}

void SoundProcessor::process() {
#ifdef _FMOD_SOUND
	for(std::list<FMOD::Channel*>::iterator i = soundChannel.begin(); i!=soundChannel.end();)
	{
		bool is_playing = false;
		(*i)->isPlaying(&is_playing);
		if(!is_playing) {
			i = soundChannel.erase(i);
		}
		else ++i;
	}
	for(std::list<std::pair<Sound*, float> >::iterator i = soundsToPlay.begin(); i != soundsToPlay.end(); ++i)
		if((soundChannel.size() < getSoundChannels()))
		{
			FMOD::Channel* mychannel = NULL;
			soundEngine->playSound(FMOD_CHANNEL_FREE, i->first->getData(), 0, &mychannel);
			mychannel->setPan(i->second);
			mychannel->setVolume((float)(getSoundVolume()/100.0));
			soundChannel.push_back(mychannel);
		}
#elif _SDL_MIXER_SOUND
	for(std::list<std::pair<boost::shared_ptr<const Sound>, float> >::iterator i = soundsToPlay.begin(); i != soundsToPlay.end(); ++i)
		if((soundChannel.size() < soundConfiguration->getSoundChannels()))
		{
			int mychannel = -1;
			mychannel = Mix_PlayChannel(-1, i->first->getData(), 0);
			if(mychannel == -1) {
				std::ostringstream os;
				os << "ERROR (SoundProcessor::process()): " << Mix_GetError();
				throw SDLException(os.str());
			} else
			soundChannel.push_back(mychannel);
			int rightVolume = static_cast<int>(254.0 * i->second);
			Mix_SetPanning(mychannel, static_cast<Uint8>(254 - rightVolume), static_cast<Uint8>(rightVolume));
			// Mix_SetDistance TODO
			// int Mix_SetPosition(int channel, Sint16 angle, Uint8 distance)  TODO
		}
#endif
		soundsToPlay.clear();
		// ------ END SOUND ENGINE -------
}



// ------------------ SOUND AND MUSIC BEGIN -----------------------

#ifdef _FMOD_SOUND
bool ERRCHECK(FMOD_RESULT result)
{
	if (result != FMOD_OK)
	{
		std::ostringstream os;
		os << "FMOD error! ( "<< result << ") " << FMOD_ErrorString(result);
		toErrorLog(os.str());
		return false;
	}
	return true;
}
#endif



void SoundProcessor::releaseSoundEngine()
{
#ifdef _FMOD_SOUND
	if(musicChannel) {
		musicChannel->stop();
	}

	if(soundEngine) {
		toInfoLog("* " + TextStorage::instance().get(IDS::END_CLOSING_SOUND_ENGINE_TEXT_ID)->getText());
		soundEngine->close();
		toInfoLog("* " + TextStorage::instance().get(IDS::END_RELEASING_SOUND_ENGINE_TEXT_ID)->getText());
		soundEngine->release();
		delete soundEngine;
		soundEngine = NULL;
	}
#elif _SDL_MIXER_SOUND
	Mix_HaltMusic();
	toInfoLog("* " + TextStorage::instance().get(IDS::END_CLOSING_SOUND_ENGINE_TEXT_ID)->getText());
	Mix_CloseAudio();
#endif
	soundInitialized = false;
}





void SoundProcessor::stopMusic()
{
	playMusic(boost::shared_ptr<const Music>(), false);
}

void SoundProcessor::clearSoundChannels() {
	soundChannel.clear();
}

void SoundProcessor::clearSoundsToPlay() {
	soundsToPlay.clear();
}


float SoundProcessor::calculatePosition(const signed x, const unsigned int resolutionX) {
	return static_cast<float>(static_cast<float>(x)/static_cast<float>(resolutionX));
}

void SoundProcessor::playSound(boost::shared_ptr<const Sound> playSound, float position)
{
#ifdef _FMOD_SOUND
	BOOST_ASSERT(soundEngine);
#endif
	soundsToPlay.push_back(std::pair<boost::shared_ptr<const Sound>, float>(playSound, position));
}
// TODO volume! (z)



void SoundProcessor::playMusic(boost::shared_ptr<const Music> play_music, const bool loop)
{

#ifdef _FMOD_SOUND
	BOOST_ASSERT(soundEngine);

	if(musicChannel) {
		musicChannel->stop();
	}
	soundEngine->playSound(FMOD_CHANNEL_FREE, play_music->getData(), 0, &musicChannel);

#elif _SDL_MIXER_SOUND

	bool success = false;

	// music currently playing?
	if(currentMusic != NULL)
	{
		// new music?
		if(play_music != NULL) {
			if(loop) {
				nextMusic = currentMusic;
			} else {
				nextMusic = NULL;
			}
			// transition between both music plays
			Mix_HookMusicFinished(::transitionMusic);
			success = (Mix_FadeOutMusic(MUSIC_TRANSITION_DURATION/2) == 1);
		} else 
			// empty music => Stop music, just fade out
		{
			success = (Mix_FadeOutMusic(MUSIC_TRANSITION_DURATION) == 1);
		}
	} else 
		// no music was playing
	{
		if(play_music != NULL)
		{
			currentMusic = play_music->getData();
			if(loop) {
				nextMusic = currentMusic;
			} else {
				nextMusic = NULL;
			}

			Mix_HookMusicFinished(::transitionMusic);
			success = (Mix_FadeInMusic(currentMusic, -1, MUSIC_TRANSITION_DURATION) == 0);
		} else {
			// no music played, no music to play
			success = true;
		}
	}

	if(!success) {
		std::ostringstream os;
		os << "ERROR (SoundProcessor::playMusic()): " << Mix_GetError() << "[" << play_music->getFileName() << "]";
		toErrorLog(os.str());
	}
#endif
}



void SoundProcessor::printSoundInformation() const
{
#ifdef _FMOD_SOUND
	FMOD_RESULT result;
	int driver_num;
	result = soundEngine->getNumDrivers(&driver_num);
	ERRCHECK(result);

	std::ostringstream os; os << "* Available sound drivers: ";
	for(unsigned int i = driver_num; i--;)
	{
		char driver_name[256];
		result = soundEngine->getDriverInfo(i, driver_name, 256, 0);
		ERRCHECK(result);
		os << driver_name << " ";
	}
	toInfoLog(os.str());
	os.str("");
	int current_driver;
	result = soundEngine->getDriver(&current_driver);
	ERRCHECK(result);

	os << "* Driver used: ";
	if(current_driver == -1)
	{
		os << "Primary or main sound device as selected by the operating system settings";
		if(driver_num == 1)
		{
			char driver_name[256];
			result = soundEngine->getDriverInfo(current_driver, driver_name, 256, 0);
			ERRCHECK(result);
			os << "(probably '" << driver_name << "')";
		}
	}
	else
	{
		char driver_name[256];
		result = soundEngine->getDriverInfo(current_driver, driver_name, 256, 0);
		ERRCHECK(result);
		os << driver_name;
	}
	toInfoLog(os.str());
#elif _SDL_MIXER_SOUND
	int audio_rate, audio_channels;
	Uint16 audio_format;
	int success = Mix_QuerySpec(&audio_rate, &audio_format, &audio_channels);
	
	if(!success) {
		std::ostringstream os;
		os << "ERROR (SoundProcessor::printSoundInformation()): " << Mix_GetError();
		throw SDLException(os.str());
	}
	int bits = audio_format & 0xFF;
	std::ostringstream os; 
	os << "* Opened audio at " << audio_rate << "Hz " << bits << "bit " << ((audio_channels>1)?"stereo":"mono");// << ", " << audio_buffers << " bytes audio buffer";
	toInfoLog(os.str());
#endif
}


#ifdef _FMOD_SOUND
		FMOD::Channel* SoundProcessor::musicChannel;
		FMOD::System* SoundProcessor::soundEngine;
		std::list<FMOD::Channel*> SoundProcessor::soundChannel;
#elif _SDL_MIXER_SOUND
		// need to be static because of callback functions!
		Mix_Music* SoundProcessor::currentMusic;
		Mix_Music* SoundProcessor::nextMusic;
		std::list<int> SoundProcessor::soundChannel;
#endif

#endif



// ------------------ SOUND AND MUSIC END -----------------------



	
