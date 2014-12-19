#include "music.hpp"

#include <misc/exceptions.hpp>
#include <misc/io.hpp>
#include <sstream>
#include <lang/text_storage.hpp>
#include <misc/log.hpp>

Music::Music(const boost::uuids::uuid id, const std::string& fileName):
	UUID<Music>(id),
	fileName(fileName),
	music(NULL)
{ 
	loadMusicFile(MUSIC_DIRECTORY + fileName);	
}

Music::Music(const std::string& fileName):
	UUID<Music>(),
	fileName(fileName),
	music(NULL)
{ 
	loadMusicFile(MUSIC_DIRECTORY + fileName);	
}

void Music::loadMusicFile(const std::string& fileName) {
#ifdef _FMOD_SOUND
	BOOST_ASSERT(fmodEngine != NULL);
	FMOD_RESULT result = fmodEngine->createSound(fileName.c_str(), FMOD_LOOP_NORMAL | FMOD_SOFTWARE, 0, &music);
	if(!ERRCHECK(result)) {
		throw SDLException("ERROR (Music::Music()): Could not load music file " + fileName + " via FMOD [" + FMOD_ErrorString(result) + "].");
	}
#elif _SDL_MIXER_SOUND
	music = Mix_LoadMUS(fileName.c_str());
	if(!music) 
	{
		std::ostringstream os;
		os << "ERROR (Music::Music()): Could not load music file " << fileName << " [" << Mix_GetError() << "] via SDL Mixer";
		throw SDLException(os.str());
	}
#endif	
}

Music::~Music()
{
#ifdef _FMOD_SOUND
		music->release();
#elif _SDL_MIXER_SOUND
		Mix_FreeMusic(music);
#endif
}


const std::string Music::MUSIC_DIRECTORY = IO::getDirectory(boost::assign::list_of("data")("music"));