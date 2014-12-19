#include <misc/randomgenerator.hpp>

#include "point_fixture.hpp"


Point_Fixture::Point_Fixture() :
	test_x(static_cast<Sint16>(RandomGenerator::instance().rnd())),
	test_y(static_cast<Sint16>(RandomGenerator::instance().rnd())),
	test_point(new Point(test_x, test_y)),

	test_target_x(static_cast<Sint16>(RandomGenerator::instance().rnd())),
	test_target_y(static_cast<Sint16>(RandomGenerator::instance().rnd())),
	test_target_point(new Point(test_target_x, test_target_y))
{ }

Point_Fixture::~Point_Fixture() 
{ }