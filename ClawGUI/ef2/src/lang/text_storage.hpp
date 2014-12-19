#ifndef _LANG_STORAGES_TEXT_HPP
#define _LANG_STORAGES_TEXT_HPP

#include <misc/singlestorage.hpp>

#include "text.hpp"

class TextStorage : public SingleStorage<Text>
{ 
public:
	static void updateLanguage(const boost::uuids::uuid languageId);
	static boost::uuids::uuid getCurrentLanguageId();

private:
	static boost::uuids::uuid currentLanguageId;
};

inline boost::uuids::uuid TextStorage::getCurrentLanguageId() {
	return currentLanguageId;
}

#endif // _LANG_STORAGES_TEXT_HPP
