#ifndef _GUICORE_FIXTURE_BUTTONCOLORSFIXTURE_HPP
#define _GUICORE_FIXTURE_BUTTONCOLORSFIXTURE_HPP

#pragma warning(push, 0)  
#include <boost/shared_ptr.hpp>
#pragma warning(pop)

#include <guicore/buttoncolors.hpp>

#include "buttonanimation_fixture.hpp"
#include "font_fixture.hpp"
#include <map>

struct ButtonColors_Fixture
{
	const Font_Fixture test_fontFixture; 
	const unsigned int test_speed; // 100 = 100 steps for full animation
	const eButtonAnimationType test_animationType;

	const ButtonAnimation_Fixture buttonAnimationDisabledFixture;
	const ButtonAnimation_Fixture buttonAnimationNormalFixture;
	const ButtonAnimation_Fixture buttonAnimationPressedFixture;
	const ButtonAnimation_Fixture buttonAnimationHighlightFixture;
	const ButtonAnimation_Fixture buttonAnimationPressedHighlightedFixture;

	const std::vector<boost::shared_ptr<const ButtonAnimation> > test_buttonAnimation;

	const boost::shared_ptr<const ButtonColors> test_buttoncolors;

	ButtonColors_Fixture();	
	~ButtonColors_Fixture();

private:
	const std::vector<boost::shared_ptr<const ButtonAnimation> > init_buttonanimation_helper() const;

	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const ButtonColors> > test_buttoncolorsMap;
	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const ButtonColors> > init_buttoncolorsmap_helper();
};

#endif // _GUICORE_FIXTURE_BUTTONCOLORSFIXTURE_HPP
