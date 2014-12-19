#ifndef _GUICORE_STORAGES_GUICOREDIRECTORIES_HPP
#define _GUICORE_STORAGES_GUICOREDIRECTORIES_HPP

#include <string>

class GuiCoreDirectories
{
public:
	static void init();
	static void initTemp(const std::string prefixDirectory); // for tests
};

#endif // _GUICORE_STORAGES_GUICOREDIRECTORIES_HPP