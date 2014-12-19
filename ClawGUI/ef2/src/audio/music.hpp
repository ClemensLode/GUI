#ifndef _SOUND_MUSIC_HPP
#define _SOUND_MUSIC_HPP

#if defined(_FMOD_SOUND) || defined(_SDL_MIXER_SOUND)

#pragma warning(push, 0)  
#ifdef _FMOD_SOUND
#include <fmod.hpp>
#elif _SDL_MIXER_SOUND
#include <SDL_mixer.h>
#endif
#pragma warning(pop)

#include <misc/uuid.hpp>
#include "export.hpp"

class Music : public UUID<Music>
{

	public:
		Music(const boost::uuids::uuid id, const std::string& fileName);
		Music(const std::string& fileName);

		~Music();

#ifdef _FMOD_SOUND
		FMOD::Sound* getData() const;
#elif _SDL_MIXER_SOUND
		Mix_Music* getData() const;
#endif
		const std::string& getFileName() const;
	private:
		const std::string fileName;
#ifdef _FMOD_SOUND
		FMOD::Sound* music;
		static TODO
#elif _SDL_MIXER_SOUND
		Mix_Music* music;
#endif

		void loadMusicFile(const std::string& fileName); 

		static const std::string MUSIC_DIRECTORY;
};




inline const std::string& Music::getFileName() const {
	return fileName;
}

#ifdef _FMOD_SOUND
	inline FMOD::Sound* Music::getData() const {
		return music;
	}
#elif _SDL_MIXER_SOUND
	inline Mix_Music* Music::getData() const {
		return music;
	}
#endif


#endif
#endif // _SOUND_MUSIC_HPP