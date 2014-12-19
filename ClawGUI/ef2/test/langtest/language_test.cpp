#ifndef WIN32
#define BOOST_TEST_DYN_LINK
#endif
#define BOOST_TEST_MODULE Language
#pragma warning(push, 0) 
#include <boost/test/unit_test.hpp>
#pragma warning(pop)

#include <langfixture/text_fixture.hpp>
#include <langfixture/language_fixture.hpp>
#include <langfixture/text_fixture_helper.hpp>

#include <lang/language_storage.hpp>
#include <lang/text_storage.hpp>

#include <lang/language_directories.hpp>

BOOST_FIXTURE_TEST_SUITE( Language_test, Language_Fixture )

	BOOST_AUTO_TEST_CASE (Language_constructor)
{
	Text_Fixture_Helper testFixtureHelper1(test_language1_text);
	Text_Fixture_Helper testFixtureHelper2(test_language2_text);

	TextStorage::updateLanguage(TEST_LANGUAGE1_ID);
	BOOST_CHECK_EQUAL(testFixtureHelper1.getText(), test_language1_text1_string);
	BOOST_CHECK_EQUAL(testFixtureHelper2.getText(), test_language1_text2_string);
	TextStorage::updateLanguage(TEST_LANGUAGE2_ID);
	BOOST_CHECK_EQUAL(testFixtureHelper1.getText(), test_language2_text1_string);
	BOOST_CHECK_EQUAL(testFixtureHelper2.getText(), test_language2_text2_string);
}

	BOOST_AUTO_TEST_CASE (Language_simple_constructor)
{
	Language test_language(test_language1_text);
	BOOST_CHECK_EQUAL(test_language.getName()->getId(), TEST_LANGUAGE1_TEXT_ID);
}

BOOST_AUTO_TEST_CASE (Language_storage)
{
	Text_Fixture_Helper testFixtureHelper1(TextStorage::instance().get(TEST_LANGUAGE1_TEXT_ID));
	Text_Fixture_Helper testFixtureHelper2(TextStorage::instance().get(TEST_LANGUAGE2_TEXT_ID));

	TextStorage::updateLanguage(TEST_LANGUAGE1_ID);
	BOOST_CHECK_EQUAL(testFixtureHelper1.getText(), test_language1_text1_string);
	BOOST_CHECK_EQUAL(testFixtureHelper2.getText(), test_language1_text2_string);
	
	TextStorage::updateLanguage(TEST_LANGUAGE2_ID);
	BOOST_CHECK_EQUAL(testFixtureHelper1.getText(), test_language2_text1_string);
	BOOST_CHECK_EQUAL(testFixtureHelper2.getText(), test_language2_text2_string);

	TextStorage::saveToXML();
	LanguageStorage::saveToXML();
	TextStorage::reset();
	LanguageStorage::reset();

	Text_Fixture_Helper testFixtureHelper3(TextStorage::instance().get(TEST_LANGUAGE1_TEXT_ID));
	Text_Fixture_Helper testFixtureHelper4(TextStorage::instance().get(TEST_LANGUAGE2_TEXT_ID));

	TextStorage::updateLanguage(TEST_LANGUAGE1_ID);
	BOOST_CHECK_EQUAL(testFixtureHelper3.getText(), test_language1_text1_string);
	BOOST_CHECK_EQUAL(testFixtureHelper4.getText(), test_language1_text2_string);

	TextStorage::updateLanguage(TEST_LANGUAGE2_ID);
	BOOST_CHECK_EQUAL(testFixtureHelper3.getText(), test_language2_text1_string);
	BOOST_CHECK_EQUAL(testFixtureHelper4.getText(), test_language2_text2_string);
}


BOOST_AUTO_TEST_SUITE_END( )


BOOST_FIXTURE_TEST_SUITE( Text_test, Text_Fixture )

	BOOST_AUTO_TEST_CASE (Text_constructor)
{
	Text_Fixture_Helper testFixtureHelper(test_text);

	test_text->updateLanguage(languageFixture.TEST_LANGUAGE2_ID);
	BOOST_CHECK_EQUAL(testFixtureHelper.getText(), test_text2_string);
	test_text->updateLanguage(languageFixture.TEST_LANGUAGE1_ID);
	BOOST_CHECK_EQUAL(testFixtureHelper.getText(), test_text1_string);
}

	BOOST_AUTO_TEST_CASE (Text_simple_constructor)
{
	Text test_text(test_stringMap);
	BOOST_CHECK_EQUAL(test_text.getTextMap().find(languageFixture.TEST_LANGUAGE1_ID)->second, test_text1_string);
	BOOST_CHECK_EQUAL(test_text.getTextMap().find(languageFixture.TEST_LANGUAGE2_ID)->second, test_text2_string);
}

BOOST_AUTO_TEST_SUITE_END( )

