#include "sound.hpp"

#include <misc/exceptions.hpp>
#include <misc/io.hpp>
#include <misc/log.hpp>
#include <sstream>

#pragma warning(push, 0)  
#include <boost/lexical_cast.hpp>
#pragma warning(pop)


Sound::Sound(const boost::uuids::uuid id, const std::string& fileName):
UUID<Sound>(id),
	fileName(fileName),
	sound(NULL)
{
	loadSound(SOUND_DIRECTORY + fileName);
}

Sound::Sound(const std::string& fileName):
UUID<Sound>(),
	fileName(fileName),
	sound(NULL)
{ 
	loadSound(SOUND_DIRECTORY + fileName);
}

void Sound::loadSound(const std::string& fileName) 
{

#ifdef _FMOD_SOUND
	FMOD_RESULT result;
	result = sound->createSound(fileName.c_str(), FMOD_SOFTWARE, 0, &sound);
	if(!ERRCHECK(result))
	{
		throw SDLException("ERROR (Sound::lookUpSound()): Could not load " + fileName + " [" + FMOD_ErrorString(result) + "].");
	}
#elif _SDL_MIXER_SOUND
	sound = Mix_LoadWAV(fileName.c_str());
	if(!sound) 
	{
		std::ostringstream os;
		os << "ERROR (Sound::lookUpSound()): Could not load " << fileName << " : " << boost::lexical_cast<std::string>(Mix_GetError());
		throw SDLException(os.str());
	}
#endif	
}

Sound::~Sound()
{
#ifdef _FMOD_SOUND
	sound->release();
#elif _SDL_MIXER_SOUND
	Mix_FreeChunk(sound);
#endif
}


const std::string Sound::SOUND_DIRECTORY = IO::getDirectory(boost::assign::list_of("data")("sounds"));