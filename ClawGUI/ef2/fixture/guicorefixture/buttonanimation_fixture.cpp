#include <misc/randomgenerator.hpp>

#include "buttonanimation_fixture.hpp"
#include <guicore/buttonanimation_storage.hpp>
#include <guicore/guicore_directories.hpp>

ButtonAnimation_Fixture::ButtonAnimation_Fixture() :
	startBrushFixture(),
	endBrushFixture(),
	startTextColorFixture(),
	endTextColorFixture(),
	startBorderPenFixture(),
	endBorderPenFixture(),
	bitmapFixture(),

	test_buttonanimation(new ButtonAnimation(startBrushFixture.test_brush, endBrushFixture.test_brush, startTextColorFixture.test_color, endTextColorFixture.test_color, startBorderPenFixture.test_pen, endBorderPenFixture.test_pen, bitmapFixture.test_bitmap1)),
	test_buttonanimationMap(init_buttonanimationmap_helper())
{ 
	GuiCoreDirectories::initTemp("temp");	

	ButtonAnimationStorage::instance(test_buttonanimationMap);
}

ButtonAnimation_Fixture::~ButtonAnimation_Fixture() 
{ 
	GuiCoreDirectories::initTemp("temp");

	ButtonAnimationStorage::clear();
	
	GuiCoreDirectories::init();
}

const std::map<const boost::uuids::uuid, const boost::shared_ptr<const ButtonAnimation> > ButtonAnimation_Fixture::init_buttonanimationmap_helper() {
	std::map<const boost::uuids::uuid, const boost::shared_ptr<const ButtonAnimation> > buttonanimationMap;
	buttonanimationMap.insert(std::pair<const boost::uuids::uuid, const boost::shared_ptr<const ButtonAnimation> >(test_buttonanimation->getId(), test_buttonanimation));
	return buttonanimationMap;
}