#ifndef _GEOMETRY_FIXTURE_RECTFIXTURE_HPP
#define _GEOMETRY_FIXTURE_RECTFIXTURE_HPP

#pragma warning(push, 0)  
#include <boost/shared_ptr.hpp>
#pragma warning(pop)

#include <geometry/rect.hpp>


struct Rect_Fixture
{
	const Point test_topLeftCorner;
	const Point test_bottomRightCorner;
	const Size test_rectSize;

	const boost::shared_ptr<const Rect> test_rect1;
	const boost::shared_ptr<const Rect> test_rect2;
	const boost::shared_ptr<const Rect> test_rect3;

	Rect_Fixture();
	virtual ~Rect_Fixture();
};

#endif // _GEOMETRY_FIXTURE_RECTFIXTURE_HPP