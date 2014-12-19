#ifndef _SOUND_SOUNDPROCESSOR_HPP
#define _SOUND_SOUNDPROCESSOR_HPP

#include "sound.hpp"
#include "music.hpp"

#include <list>

#include "soundconfiguration.hpp"

class SoundProcessor
{
public:
		SoundProcessor(const boost::shared_ptr<const SoundConfiguration> soundConfiguration);
		~SoundProcessor();

		void setSoundConfiguration(const boost::shared_ptr<const SoundConfiguration> soundConfiguration);

		static float calculatePosition(const signed x, const unsigned int resolutionX);

// ------------------ SOUND AND MUSIC START -----------------------
		void setMusicVolume(const unsigned int musicVolume);
		void setSoundVolume(const unsigned int soundVolume);

		void playSound(boost::shared_ptr<const Sound> playSound, float position);
		void playMusic(boost::shared_ptr<const Music> playMusic, const bool loop = true);

		void stopMusic();
		void releaseSoundEngine();

#ifdef _SDL_MIXER_SOUND
		static void transitionMusic(void);
		static void soundChannelDone(int channel);
#endif

		void process();

// ------------------ SOUND AND MUSIC END -----------------------
private:
		boost::shared_ptr<const SoundConfiguration> soundConfiguration;

	
// ------------------ SOUND AND MUSIC BEGIN -----------------------

		void initSoundEngine();

		void printSoundInformation() const;
		void clearSoundsToPlay();
		void clearSoundChannels();
	
		bool soundInitialized;
		std::list<std::pair<boost::shared_ptr<const Sound>, float> > soundsToPlay;


#ifdef _FMOD_SOUND
		static FMOD::Channel* musicChannel;
		static FMOD::System* soundEngine;
		static std::list<FMOD::Channel*> soundChannel;
#elif _SDL_MIXER_SOUND
		// need to be static because of callback functions!
		static Mix_Music* currentMusic;
		static Mix_Music* nextMusic;
		static std::list<int> soundChannel;
#endif
};

#endif // _SOUND_SOUNDPROCESSOR_HPP