#include <misc/randomgenerator.hpp>

#include "rect_fixture.hpp"


Rect_Fixture::Rect_Fixture() :
	test_topLeftCorner(static_cast<Sint16>(RandomGenerator::instance().rnd()), static_cast<Sint16>(RandomGenerator::instance().rnd())),
	test_bottomRightCorner(test_topLeftCorner + Size(static_cast<Uint16>(RandomGenerator::instance().rnd()), static_cast<Uint16>(RandomGenerator::instance().rnd()))),
	test_rectSize(test_bottomRightCorner - test_topLeftCorner),
	test_rect1(new Rect(test_topLeftCorner, test_bottomRightCorner)),
	test_rect2(new Rect(test_topLeftCorner, test_rectSize)),
	test_rect3(new Rect(test_topLeftCorner.getX(), test_topLeftCorner.getY(), test_rectSize.getWidth(), test_rectSize.getHeight()))
{ }

Rect_Fixture::~Rect_Fixture() 
{ }