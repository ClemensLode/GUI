#ifndef _GUICORE_FIXTURE_FONTTYPEFIXTURE_HPP
#define _GUICORE_FIXTURE_FONTTYPEFIXTURE_HPP

#pragma warning(push, 0)  
#include <boost/shared_ptr.hpp>
#pragma warning(pop)

#include <guicore/fonttype.hpp>
#include "font_fixture.hpp"
#include <map>

struct FontType_Fixture
{
	Font_Fixture test_fontFixture;
	Font_Fixture test_boldFontFixture;
	Font_Fixture test_shadowFontFixture;
	Font_Fixture test_underlinedFontFixture;
	Font_Fixture test_shadowBoldFontFixture;
	Font_Fixture test_shadowUnderlinedFontFixture;
	Font_Fixture test_underlinedBoldFontFixture;
	Font_Fixture test_shadowUnderlinedBoldFontFixture;

	const boost::shared_ptr<const FontType> test_fonttype;

	FontType_Fixture();	
	~FontType_Fixture();
private:
	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const FontType> > test_fonttypeMap;
	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const FontType> > init_fonttypemap_helper();
};

#endif // _GUICORE_FIXTURE_FONTTYPEFIXTURE_HPP
