#include <misc/randomgenerator.hpp>

#include "language_fixture.hpp"
#include <lang/language_storage.hpp>

#include <lang/language_directories.hpp>

Language_Fixture::Language_Fixture():
	TEST_LANGUAGE1_ID(Misc::uuid("{e0962fd0-3201-11e0-bc8e-0800200c9a66}")),
	TEST_LANGUAGE2_ID(Misc::uuid("{e3b06820-3201-11e0-bc8e-0800200c9a66}")),

	TEST_LANGUAGE1_TEXT_ID(Misc::uuid("{e63a6e60-3201-11e0-bc8e-0800200c9a66}")),
	TEST_LANGUAGE2_TEXT_ID(Misc::uuid("{e87f2e40-3201-11e0-bc8e-0800200c9a66}")),

	test_language1_text1_string("Deutsch"),
	test_language1_text2_string("Englisch"),
	test_language2_text1_string("German"),
	test_language2_text2_string("English"),

	test_language1_text(new Text(TEST_LANGUAGE1_TEXT_ID, init_textmap1_helper())),
	test_language2_text(new Text(TEST_LANGUAGE2_TEXT_ID, init_textmap2_helper())),
	test_language1(new Language(TEST_LANGUAGE1_ID, test_language1_text)),
	test_language2(new Language(TEST_LANGUAGE2_ID, test_language2_text)),

	test_textMap(init_textmap_helper()),
	test_languageMap(init_languagemap_helper())
{ 
	LanguageDirectories::initTemp("temp");

	TextStorage::instance(test_textMap);
	LanguageStorage::instance(test_languageMap);	
}

Language_Fixture::~Language_Fixture() 
{
	LanguageDirectories::initTemp("temp");

	TextStorage::clear();
	LanguageStorage::clear();

	LanguageDirectories::init(); // reset to normal
}

const std::map<const boost::uuids::uuid, const std::string> Language_Fixture::init_textmap1_helper() const {
	std::map<const boost::uuids::uuid, const std::string> textmap;

	textmap.insert(std::pair<const boost::uuids::uuid, const std::string>(TEST_LANGUAGE1_ID, test_language1_text1_string));
	textmap.insert(std::pair<const boost::uuids::uuid, const std::string>(TEST_LANGUAGE2_ID, test_language2_text1_string));

	return textmap;
}

const std::map<const boost::uuids::uuid, const std::string> Language_Fixture::init_textmap2_helper() const {
	std::map<const boost::uuids::uuid, const std::string> textmap;

	textmap.insert(std::pair<const boost::uuids::uuid, const std::string>(TEST_LANGUAGE1_ID, test_language1_text2_string));
	textmap.insert(std::pair<const boost::uuids::uuid, const std::string>(TEST_LANGUAGE2_ID, test_language2_text2_string));

	return textmap;
}

const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Text> > Language_Fixture::init_textmap_helper() const {
	std::map<const boost::uuids::uuid, const boost::shared_ptr<const Text> > textmap;
	textmap.insert(std::pair<const boost::uuids::uuid, const boost::shared_ptr<const Text> >(test_language1_text->getId(), test_language1_text));
	textmap.insert(std::pair<const boost::uuids::uuid, const boost::shared_ptr<const Text> >(test_language2_text->getId(), test_language2_text));
	return textmap;
}

const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Language> > Language_Fixture::init_languagemap_helper() const {
	std::map<const boost::uuids::uuid, const boost::shared_ptr<const Language> > languagemap;
	languagemap.insert(std::pair<const boost::uuids::uuid, const boost::shared_ptr<const Language> >(test_language1->getId(), test_language1));
	languagemap.insert(std::pair<const boost::uuids::uuid, const boost::shared_ptr<const Language> >(test_language2->getId(), test_language2));
	return languagemap;
}