#ifndef _GEOMETRY_FIXTURE_POINTFIXTURE_HPP
#define _GEOMETRY_FIXTURE_POINTFIXTURE_HPP

#pragma warning(push, 0)  
#include <boost/shared_ptr.hpp>
#pragma warning(pop)

#include <geometry/point.hpp>


struct Point_Fixture
{
	const Sint16 test_x;
	const Sint16 test_y;

	const boost::shared_ptr<const Point> test_point;

	const Sint16 test_target_x;
	const Sint16 test_target_y;

	const boost::shared_ptr<const Point> test_target_point;

	Point_Fixture();
	virtual ~Point_Fixture();
};

#endif // _GEOMETRY_FIXTURE_POINTFIXTURE_HPP