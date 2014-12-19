#ifndef _LANG_STORAGES_LANGUAGEDIRECTORIES_HPP
#define _LANG_STORAGES_LANGUAGEDIRECTORIES_HPP

#include <string>

class LanguageDirectories
{
public:
	static void init();
	static void initTemp(const std::string prefixDirectory); // for tests
};

#endif // _LANG_STORAGES_LANGUAGEDIRECTORIES_HPP