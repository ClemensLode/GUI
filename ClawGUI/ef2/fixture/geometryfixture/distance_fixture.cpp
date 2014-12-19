#include <misc/randomgenerator.hpp>

#include "distance_fixture.hpp"


Distance_Fixture::Distance_Fixture() :
	test_width(RandomGenerator::instance().rnd()),
	test_height(RandomGenerator::instance().rnd()),
	test_distance(new Distance(test_width, test_height))
{ }

Distance_Fixture::~Distance_Fixture() 
{ }