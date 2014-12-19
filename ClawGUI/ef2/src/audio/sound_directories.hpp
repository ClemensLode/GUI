#ifndef _SOUND_STORAGES_SOUNDDIRECTORIES_HPP
#define _SOUND_STORAGES_SOUNDDIRECTORIES_HPP

#include <string>

class SoundDirectories
{
public:
	static void init();
	static void initTemp(const std::string prefixDirectory); // for tests
};

#endif // _SOUND_STORAGES_SOUNDDIRECTORIES_HPP