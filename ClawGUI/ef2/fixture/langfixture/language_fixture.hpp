#ifndef _LANG_FIXTURE_LANGUAGEFIXTURE_HPP
#define _LANG_FIXTURE_LANGUAGEFIXTURE_HPP

#pragma warning(push, 0)  
#include <boost/smart_ptr.hpp>
#pragma warning(pop)

#include <lang/language.hpp>
#include <lang/text.hpp>

struct Language_Fixture
{
	const boost::uuids::uuid TEST_LANGUAGE1_ID;
	const boost::uuids::uuid TEST_LANGUAGE2_ID;

	const boost::uuids::uuid TEST_LANGUAGE1_TEXT_ID;
	const boost::uuids::uuid TEST_LANGUAGE2_TEXT_ID;

	const std::string test_language1_text1_string;
	const std::string test_language1_text2_string;
	const std::string test_language2_text1_string;
	const std::string test_language2_text2_string;

	const boost::shared_ptr<const Text> test_language1_text;
	const boost::shared_ptr<const Text> test_language2_text;

	const boost::shared_ptr<const Language> test_language1;
	const boost::shared_ptr<const Language> test_language2;

	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Text> > test_textMap;
	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Language> > test_languageMap;
	
	Language_Fixture();	
	~Language_Fixture();

private:
	const std::map<const boost::uuids::uuid, const std::string> init_textmap1_helper() const;
	const std::map<const boost::uuids::uuid, const std::string> init_textmap2_helper() const;

	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Text> > init_textmap_helper() const;
	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Language> > init_languagemap_helper() const;

};

#endif // _LANG_FIXTURE_LANGUAGEFIXTURE_HPP