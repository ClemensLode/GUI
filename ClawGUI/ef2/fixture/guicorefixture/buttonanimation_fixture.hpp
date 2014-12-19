#ifndef _GUICORE_FIXTURE_BUTTONANIMATIONFIXTURE_HPP
#define _GUICORE_FIXTURE_BUTTONANIMATIONFIXTURE_HPP

#pragma warning(push, 0)  
#include <boost/shared_ptr.hpp>
#pragma warning(pop)

#include <guicore/buttonanimation.hpp>
#include "brush_fixture.hpp"
#include "color_fixture.hpp"
#include "pen_fixture.hpp"
#include "bitmap_fixture.hpp"
#include <map>

struct ButtonAnimation_Fixture
{
	const Brush_Fixture startBrushFixture;
	const Brush_Fixture endBrushFixture;
	const Color_Fixture startTextColorFixture;
	const Color_Fixture endTextColorFixture;
	const Pen_Fixture startBorderPenFixture;
	const Pen_Fixture endBorderPenFixture;
	const Bitmap_Fixture bitmapFixture;

	const boost::shared_ptr<const ButtonAnimation> test_buttonanimation;

	ButtonAnimation_Fixture();	
	~ButtonAnimation_Fixture();

private:
	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const ButtonAnimation> > test_buttonanimationMap;
	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const ButtonAnimation> > init_buttonanimationmap_helper();
};

#endif // _GUICORE_FIXTURE_BUTTONANIMATIONFIXTURE_HPP
