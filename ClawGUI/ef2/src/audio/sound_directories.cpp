#include "sound_directories.hpp"

#include <misc/singlestorage.hpp>
#include <misc/io.hpp>
#include <lang/language_directories.hpp>

#include "soundconfiguration.hpp"
#include "sound.hpp"
#include "music.hpp"

void SoundDirectories::init() {
	SingleStorage<SoundConfiguration>::DATA_FILE_NAME = SingleStorage<SoundConfiguration>::DATA_FILE_NAME_BASE;
	SingleStorage<Sound>::DATA_FILE_NAME = SingleStorage<Sound>::DATA_FILE_NAME_BASE;
	SingleStorage<Music>::DATA_FILE_NAME = SingleStorage<Music>::DATA_FILE_NAME_BASE;

	LanguageDirectories::init();
}

void SoundDirectories::initTemp(const std::string prefixDirectory) {
	SingleStorage<SoundConfiguration>::DATA_FILE_NAME = IO::getDirectory(boost::assign::list_of(prefixDirectory)) + SingleStorage<SoundConfiguration>::DATA_FILE_NAME_BASE;
	SingleStorage<Sound>::DATA_FILE_NAME = IO::getDirectory(boost::assign::list_of(prefixDirectory)) + SingleStorage<Sound>::DATA_FILE_NAME_BASE;
	SingleStorage<Music>::DATA_FILE_NAME = IO::getDirectory(boost::assign::list_of(prefixDirectory)) + SingleStorage<Music>::DATA_FILE_NAME_BASE;

	LanguageDirectories::init();
}