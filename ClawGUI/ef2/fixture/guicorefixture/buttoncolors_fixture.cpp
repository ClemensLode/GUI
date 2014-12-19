#include <misc/randomgenerator.hpp>

#include "buttoncolors_fixture.hpp"
#include <guicore/buttoncolors_storage.hpp>
#include <guicore/guicore_directories.hpp>

#pragma warning(push, 0) 
#include <boost/assign/list_of.hpp>
#pragma warning(pop)

ButtonColors_Fixture::ButtonColors_Fixture() :
	test_speed(RandomGenerator::instance().rnd()),
	test_animationType(static_cast<eButtonAnimationType>(RandomGenerator::instance().rnd()%MAX_BUTTON_ANIMATION_TYPES)),
	buttonAnimationDisabledFixture(),
	buttonAnimationNormalFixture(),
	buttonAnimationPressedFixture(),
	buttonAnimationHighlightFixture(),
	buttonAnimationPressedHighlightedFixture(),
	test_buttonAnimation(init_buttonanimation_helper()),
	test_buttoncolors(new ButtonColors(test_fontFixture.test_font, test_speed, test_animationType, test_buttonAnimation)),
	test_buttoncolorsMap(init_buttoncolorsmap_helper())
{ 
	GuiCoreDirectories::initTemp("temp");	

	ButtonColorsStorage::instance(test_buttoncolorsMap);
}

ButtonColors_Fixture::~ButtonColors_Fixture() 
{ 
	GuiCoreDirectories::initTemp("temp");

	ButtonColorsStorage::clear();
	
	GuiCoreDirectories::init();
}


const std::map<const boost::uuids::uuid, const boost::shared_ptr<const ButtonColors> > ButtonColors_Fixture::init_buttoncolorsmap_helper() {
	std::map<const boost::uuids::uuid, const boost::shared_ptr<const ButtonColors> > buttoncolorsMap;
	buttoncolorsMap.insert(std::pair<const boost::uuids::uuid, const boost::shared_ptr<const ButtonColors> >(test_buttoncolors->getId(), test_buttoncolors));
	return buttoncolorsMap;
}


const std::vector<boost::shared_ptr<const ButtonAnimation> > ButtonColors_Fixture::init_buttonanimation_helper() const {
	std::vector<boost::shared_ptr<const ButtonAnimation> > temp_vector;
	
	temp_vector.push_back(buttonAnimationDisabledFixture.test_buttonanimation);
	temp_vector.push_back(buttonAnimationNormalFixture.test_buttonanimation);
	temp_vector.push_back(buttonAnimationPressedFixture.test_buttonanimation);
	temp_vector.push_back(buttonAnimationHighlightFixture.test_buttonanimation);
	temp_vector.push_back(buttonAnimationPressedHighlightedFixture.test_buttonanimation);

	return temp_vector;
}