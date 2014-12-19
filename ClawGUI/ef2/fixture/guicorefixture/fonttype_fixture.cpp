#include <misc/randomgenerator.hpp>

#include "fonttype_fixture.hpp"
#include <guicore/fonttype_storage.hpp>
#include <guicore/guicore_directories.hpp>

FontType_Fixture::FontType_Fixture() :
test_fontFixture(),
	test_boldFontFixture(),
	test_shadowFontFixture(),
	test_underlinedFontFixture(),
	test_shadowBoldFontFixture(),
	test_shadowUnderlinedFontFixture(),
	test_underlinedBoldFontFixture(),
	test_shadowUnderlinedBoldFontFixture(),

	test_fonttype(new FontType(test_fontFixture.test_font, 
	test_boldFontFixture.test_font, 
	test_shadowFontFixture.test_font, 
	test_underlinedFontFixture.test_font, 
	test_shadowBoldFontFixture.test_font, 
	test_shadowUnderlinedFontFixture.test_font, 
	test_underlinedBoldFontFixture.test_font, 
	test_shadowUnderlinedBoldFontFixture.test_font)),
	test_fonttypeMap(init_fonttypemap_helper())
{ 
	GuiCoreDirectories::initTemp("temp");	

	FontTypeStorage::instance(test_fonttypeMap);
}

FontType_Fixture::~FontType_Fixture() 
{ 
	GuiCoreDirectories::initTemp("temp");

	FontTypeStorage::clear();
	
	GuiCoreDirectories::init();
}


const std::map<const boost::uuids::uuid, const boost::shared_ptr<const FontType> > FontType_Fixture::init_fonttypemap_helper() {
	std::map<const boost::uuids::uuid, const boost::shared_ptr<const FontType> > fonttypeMap;
	fonttypeMap.insert(std::pair<const boost::uuids::uuid, const boost::shared_ptr<const FontType> >(test_fonttype->getId(), test_fonttype));
	return fonttypeMap;
}