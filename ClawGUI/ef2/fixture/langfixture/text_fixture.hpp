#ifndef _LANG_FIXTURE_TEXTFIXTURE_HPP
#define _LANG_FIXTURE_TEXTFIXTURE_HPP

#pragma warning(push, 0)  
#include <boost/smart_ptr.hpp>
#pragma warning(pop)

#include <lang/text.hpp>
#include "language_fixture.hpp"

struct Text_Fixture
{
	Language_Fixture languageFixture;

	const std::string test_text1_string;
	const std::string test_text2_string;

	const std::map<const boost::uuids::uuid, const std::string> test_stringMap;

	const boost::shared_ptr<const Text> test_text;
	Text_Fixture();	
	~Text_Fixture();

private:
	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Text> > test_textMap;
	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Text> > init_textmap_helper() const;
	const std::map<const boost::uuids::uuid, const std::string> init_stringmap_helper() const;
};


#endif // _LANG_FIXTURE_TEXTFIXTURE_HPP