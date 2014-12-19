#include <misc/randomgenerator.hpp>

#include "zrect_fixture.hpp"

ZRect_Fixture::ZRect_Fixture() :
	test_rect(static_cast<Sint16>(RandomGenerator::instance().rnd()), static_cast<Sint16>(RandomGenerator::instance().rnd()), static_cast<Uint16>(RandomGenerator::instance().rnd()), static_cast<Uint16>(RandomGenerator::instance().rnd())),
	test_z(RandomGenerator::instance().rnd()),
	test_zrect(new ZRect(test_rect, test_z))
{ }

ZRect_Fixture::~ZRect_Fixture() 
{ }