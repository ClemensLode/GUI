#ifndef _GEOMETRY_FIXTURE_DISTANCEFIXTURE_HPP
#define _GEOMETRY_FIXTURE_DISTANCEFIXTURE_HPP

#pragma warning(push, 0)  
#include <boost/shared_ptr.hpp>
#pragma warning(pop)

#include <geometry/distance.hpp>

struct Distance_Fixture
{
	const unsigned int test_width;
	const unsigned int test_height;

	const boost::shared_ptr<const Distance> test_distance;

	Distance_Fixture();
	virtual ~Distance_Fixture();
};

#endif // _GEOMETRY_FIXTURE_DISTANCEFIXTURE_HPP