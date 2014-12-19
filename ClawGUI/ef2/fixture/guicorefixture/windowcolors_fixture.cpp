#include <misc/randomgenerator.hpp>

#include "windowcolors_fixture.hpp"
#include <guicore/windowcolors_storage.hpp>
#include <guicore/guicore_directories.hpp>

WindowColors_Fixture::WindowColors_Fixture() :
	fontFixture(),
	textColorFixture(),
	backgroundBrushFixture(),
	borderPenFixture(),
	outerBorderPenFixture(),
	highlightedBorderPenFixture(),
	test_windowcolors(new WindowColors(fontFixture.test_font, textColorFixture.test_color, backgroundBrushFixture.test_brush, borderPenFixture.test_pen, outerBorderPenFixture.test_pen, highlightedBorderPenFixture.test_pen)),
	test_windowcolorsMap(init_windowcolorsmap_helper())
{ 
	GuiCoreDirectories::initTemp("temp");	

	WindowColorsStorage::instance(test_windowcolorsMap);
}

WindowColors_Fixture::~WindowColors_Fixture() 
{ 
	GuiCoreDirectories::initTemp("temp");

	WindowColorsStorage::clear();
	
	GuiCoreDirectories::init();
}

const std::map<const boost::uuids::uuid, const boost::shared_ptr<const WindowColors> > WindowColors_Fixture::init_windowcolorsmap_helper() {
	std::map<const boost::uuids::uuid, const boost::shared_ptr<const WindowColors> > windowColorsMap;
	windowColorsMap.insert(std::pair<const boost::uuids::uuid, const boost::shared_ptr<const WindowColors> >(test_windowcolors->getId(), test_windowcolors));
	return windowColorsMap;
}
