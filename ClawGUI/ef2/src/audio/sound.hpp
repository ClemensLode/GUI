#ifndef _SOUND_SOUND_HPP
#define _SOUND_SOUND_HPP

#if defined(_FMOD_SOUND) || defined(_SDL_MIXER_SOUND)

#include "export.hpp"

#pragma warning(push, 0)  
#ifdef _FMOD_SOUND
#include <fmod.hpp>
#elif _SDL_MIXER_SOUND
#include <SDL_mixer.h>
#endif
#pragma warning(pop)

#include <misc/uuid.hpp>


class Sound : public UUID<Sound>
{
	public:
		Sound(const boost::uuids::uuid id, const std::string& fileName);
		Sound(const std::string& fileName);
		~Sound();

		const std::string& getFileName() const; 

#ifdef _FMOD_SOUND
	    Sound(FMOD::Sound* t);
		FMOD::Sound* getData() const;	
#elif _SDL_MIXER_SOUND
		Sound(Mix_Chunk* t);
		Mix_Chunk* getData() const;	
#endif
	private:
		const std::string fileName;
#ifdef _FMOD_SOUND
		(FMOD::Sound)* sound;
#elif _SDL_MIXER_SOUND
		Mix_Chunk* sound;
#endif
		void loadSound(const std::string& fileName); 
		static const std::string SOUND_DIRECTORY;
};


inline const std::string& Sound::getFileName() const {
	return fileName;
}

#ifdef _FMOD_SOUND
	inline FMOD::Sound* Sound::getData() const {
		return sound;
	}
#elif _SDL_MIXER_SOUND
	inline Mix_Chunk* Sound::getData() const {
		return sound;
	}
#endif


#endif

#endif // _SOUND_SOUND_HPP