#include <misc/randomgenerator.hpp>

#include "coordinate_fixture.hpp"


Coordinate_Fixture::Coordinate_Fixture():
	test_x(RandomGenerator::instance().rnd()),
	test_y(RandomGenerator::instance().rnd()),
	test_coordinate(new Coordinate(test_x, test_y))
{ }

Coordinate_Fixture::~Coordinate_Fixture() 
{ }