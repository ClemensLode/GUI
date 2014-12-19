#ifndef _GUICORE_FIXTURE_WINDOWCOLORSFIXTURE_HPP
#define _GUICORE_FIXTURE_WINDOWCOLORSFIXTURE_HPP

#pragma warning(push, 0)  
#include <boost/shared_ptr.hpp>
#pragma warning(pop)

#include <guicore/windowcolors.hpp>

#include "font_fixture.hpp"
#include "color_fixture.hpp"
#include "brush_fixture.hpp"
#include "pen_fixture.hpp"
#include <map>

struct WindowColors_Fixture
{
	Font_Fixture fontFixture;
	Color_Fixture textColorFixture;
	Brush_Fixture backgroundBrushFixture;
	Pen_Fixture borderPenFixture;
	Pen_Fixture outerBorderPenFixture;
	Pen_Fixture highlightedBorderPenFixture;

	const boost::shared_ptr<const WindowColors> test_windowcolors;

	WindowColors_Fixture();	
	~WindowColors_Fixture();
private:
	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const WindowColors> > test_windowcolorsMap;
	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const WindowColors> > init_windowcolorsmap_helper();
};

#endif // _GUICORE_FIXTURE_WINDOWCOLORSFIXTURE_HPP
