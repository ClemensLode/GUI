#include <misc/randomgenerator.hpp>

#include "theme_fixture.hpp"
#include <guicore/theme_storage.hpp>
#include <guicore/guicore_directories.hpp>

Theme_Fixture::Theme_Fixture() :
	primaryColorFixture(),
	secondaryColorFixture(),
	test_name("test theme"),
	test_theme(new Theme(test_name, primaryColorFixture.test_color, secondaryColorFixture.test_color)),
	test_themeMap(init_thememap_helper())
{ 
	GuiCoreDirectories::initTemp("temp");	

	ThemeStorage::instance(test_themeMap);
}

Theme_Fixture::~Theme_Fixture() 
{ 
	GuiCoreDirectories::initTemp("temp");

	ThemeStorage::clear();
	
	GuiCoreDirectories::init();
}

const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Theme> > Theme_Fixture::init_thememap_helper() {
	std::map<const boost::uuids::uuid, const boost::shared_ptr<const Theme> > themeMap;
	themeMap.insert(std::pair<const boost::uuids::uuid, const boost::shared_ptr<const Theme> >(test_theme->getId(), test_theme));
	return themeMap;
}