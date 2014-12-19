#ifndef _GUICORE_FIXTURE_FONTFIXTURE_HPP
#define _GUICORE_FIXTURE_FONTFIXTURE_HPP

#pragma warning(push, 0)  
#include <boost/shared_ptr.hpp>
#pragma warning(pop)

#include <guicore/font.hpp>
#include <map>

struct Font_Fixture
{
	const std::string test_fileName;
	const Uint16 test_size;
	const bool test_underlined;
	const bool test_shadow;

	boost::shared_ptr<const Font> test_font;

	Font_Fixture();	
	~Font_Fixture();
private:
	boost::shared_ptr<const Font> createTestFont(std::string test_fileName, Uint16 test_size, bool test_underlined, bool test_shadow);
	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Font> > test_fontMap;
	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Font> > init_fontmap_helper();
};

#endif // _GUICORE_FIXTURE_FONTFIXTURE_HPP
