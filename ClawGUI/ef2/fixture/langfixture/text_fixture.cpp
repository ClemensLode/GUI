#include <misc/randomgenerator.hpp>

#include "text_fixture.hpp"
#include <lang/text_storage.hpp>

#include <misc/miscellaneous.hpp>
#include <string>
#include <lang/language_directories.hpp>

Text_Fixture::Text_Fixture():
	languageFixture(),
	test_text1_string("Test string 1"),
	test_text2_string("2 Test string"),
	test_stringMap(init_stringmap_helper()),
	test_text(new Text(test_stringMap)),
	test_textMap(init_textmap_helper())
{ 
	LanguageDirectories::initTemp("temp");

	TextStorage::instance(test_textMap);
}

Text_Fixture::~Text_Fixture() 
{ 
	LanguageDirectories::initTemp("temp");

	TextStorage::clear();

	LanguageDirectories::init();
}

const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Text> > Text_Fixture::init_textmap_helper() const {
	std::map<const boost::uuids::uuid, const boost::shared_ptr<const Text> > textmap;

	textmap.insert(std::pair<const boost::uuids::uuid, const boost::shared_ptr<const Text> >(test_text->getId(), test_text));

	return textmap;
}

const std::map<const boost::uuids::uuid, const std::string> Text_Fixture::init_stringmap_helper() const {
	std::map<const boost::uuids::uuid, const std::string> stringmap;

	stringmap.insert(std::pair<const boost::uuids::uuid, const std::string>(languageFixture.TEST_LANGUAGE1_ID, test_text1_string));
	stringmap.insert(std::pair<const boost::uuids::uuid, const std::string>(languageFixture.TEST_LANGUAGE2_ID, test_text2_string));

	return stringmap;
}
