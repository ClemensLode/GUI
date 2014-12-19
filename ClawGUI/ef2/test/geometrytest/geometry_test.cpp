#ifndef WIN32
#define BOOST_TEST_DYN_LINK
#endif
#define BOOST_TEST_MODULE Geometry
#pragma warning(push, 0) 
#include <boost/test/unit_test.hpp>
#pragma warning(pop)

#include <geometryfixture/coordinate_fixture.hpp>
#include <geometryfixture/distance_fixture.hpp>
#include <geometryfixture/point_fixture.hpp>
#include <geometryfixture/rect_fixture.hpp>
#include <geometryfixture/size_fixture.hpp>
#include <geometryfixture/objectsize_fixture.hpp>
#include <geometryfixture/resolution_fixture.hpp>
#include <geometryfixture/zrect_fixture.hpp>
#include <geometryfixture/layoutmanager_fixture.hpp>
#include <geometryfixture/objectsize_fixture_helper.hpp>

#include <geometry/objectsize_storage.hpp>
#include <geometry/resolution_storage.hpp>


#include <misc/randomgenerator.hpp>

// -- Coordinate

BOOST_FIXTURE_TEST_SUITE( Coordinate_test, Coordinate_Fixture)

	BOOST_AUTO_TEST_CASE (Coordinate_constructor)
{
	BOOST_CHECK_EQUAL(test_coordinate->getX(), test_x);
	BOOST_CHECK_EQUAL(test_coordinate->getY(), test_y);
}

BOOST_AUTO_TEST_CASE (Coordinate_assignment_constructor)
{
	Coordinate temp_coordinate(*test_coordinate);

	BOOST_CHECK_EQUAL(temp_coordinate.getX(), test_x);
	BOOST_CHECK_EQUAL(temp_coordinate.getY(), test_y);
}

BOOST_AUTO_TEST_CASE (Coordinate_assignment_operator)
{
	Coordinate temp_coordinate = *test_coordinate;

	BOOST_CHECK_EQUAL(temp_coordinate.getX(), test_x);
	BOOST_CHECK_EQUAL(temp_coordinate.getY(), test_y);
}

BOOST_AUTO_TEST_CASE (Coordinate_comparison_operator)
{
	Coordinate temp_coordinate(test_x, test_y);
	Coordinate temp_coordinate2(test_x, test_y + 1);
	Coordinate temp_coordinate3(test_x + 1, test_y + 1);

	BOOST_CHECK(temp_coordinate == *test_coordinate); 
	BOOST_CHECK(temp_coordinate2 != *test_coordinate); 

	BOOST_CHECK(temp_coordinate3 > temp_coordinate);
	BOOST_CHECK(temp_coordinate < temp_coordinate3);
	BOOST_CHECK(temp_coordinate2 >= temp_coordinate);
	BOOST_CHECK(temp_coordinate <= temp_coordinate2);
}

BOOST_AUTO_TEST_CASE (Coordinate_movement)
{
	Coordinate temp_coordinate(test_x, test_y);

	temp_coordinate += Distance(1, 1);

	BOOST_CHECK_EQUAL(temp_coordinate.getX(), test_x + 1);
	BOOST_CHECK_EQUAL(temp_coordinate.getY(), test_y + 1);

	temp_coordinate -= Distance(0, 2);

	BOOST_CHECK_EQUAL(temp_coordinate.getX(), test_x + 1);
	BOOST_CHECK_EQUAL(temp_coordinate.getY(), test_y - 1);
}

BOOST_AUTO_TEST_CASE (Coordinate_distance)
{
	Coordinate temp_coordinate(test_x + 10, test_y + 12);

	Distance temp_distance = temp_coordinate - *test_coordinate;

	BOOST_CHECK_EQUAL(temp_distance.getWidth(), 10);
	BOOST_CHECK_EQUAL(temp_distance.getHeight(), 12);
}

BOOST_AUTO_TEST_CASE (Coordinate_arithmetic)
{
	Coordinate temp_coordinate(test_x, test_y);
	Coordinate temp_coordinate2 = temp_coordinate + temp_coordinate;

	BOOST_CHECK_EQUAL(temp_coordinate2.getX(), 2*test_x);
	BOOST_CHECK_EQUAL(temp_coordinate2.getY(), 2*test_y);

	temp_coordinate2 = temp_coordinate2 + Distance(1,1);

	BOOST_CHECK_EQUAL(temp_coordinate2.getX(), 2*test_x+1);
	BOOST_CHECK_EQUAL(temp_coordinate2.getY(), 2*test_y+1);

	temp_coordinate2 = temp_coordinate2 - Distance(1,1);

	BOOST_CHECK_EQUAL(temp_coordinate2.getX(), 2*test_x);
	BOOST_CHECK_EQUAL(temp_coordinate2.getY(), 2*test_y);

	Coordinate temp_coordinate3 = temp_coordinate * 3;

	BOOST_CHECK_EQUAL(temp_coordinate3.getX(), 3*test_x);
	BOOST_CHECK_EQUAL(temp_coordinate3.getY(), 3*test_y);
}

BOOST_AUTO_TEST_SUITE_END( )



	// --- DISTANCE ---

	BOOST_FIXTURE_TEST_SUITE( Distance_test, Distance_Fixture )

	BOOST_AUTO_TEST_CASE (Distance_constructor)
{
	BOOST_CHECK_EQUAL(test_distance->getWidth(), test_width);
	BOOST_CHECK_EQUAL(test_distance->getHeight(), test_height);

	std::ostringstream os;
	os << (test_width) << "x" << (test_height);
	BOOST_CHECK_EQUAL(test_distance->toString(), os.str());
}

BOOST_AUTO_TEST_CASE (Distance_set)
{
	Distance test_distance2(test_width, test_height);
	test_distance2.setWidth(test_width*2);
	BOOST_CHECK_EQUAL(test_distance2.getWidth(), test_width*2);

	test_distance2.setHeight(test_height*2);
	BOOST_CHECK_EQUAL(test_distance2.getHeight(), test_height*2);		
}

BOOST_AUTO_TEST_CASE (Distance_copy_constructor)
{
	Distance temp_distance(*test_distance);

	BOOST_CHECK_EQUAL(temp_distance.getWidth(), test_width);
	BOOST_CHECK_EQUAL(temp_distance.getHeight(), test_height);
}

BOOST_AUTO_TEST_CASE (Distance_assignment_operator)
{
	Distance temp_distance = *test_distance;

	BOOST_CHECK_EQUAL(temp_distance.getWidth(), test_width);
	BOOST_CHECK_EQUAL(temp_distance.getHeight(), test_height);
}

BOOST_AUTO_TEST_CASE (Distance_compare_operator)
{
	Distance temp_distance(test_width, test_height);

	BOOST_CHECK(temp_distance == *test_distance);

	Distance temp_distance2(test_width + 1, test_height);
	Distance temp_distance3(test_width + 1, test_height + 1);

	BOOST_CHECK(!(temp_distance2 < *test_distance));
	BOOST_CHECK(!(*test_distance > temp_distance2));
	BOOST_CHECK(temp_distance3 > *test_distance);
	BOOST_CHECK(*test_distance < temp_distance3);

	BOOST_CHECK(!(temp_distance != *test_distance));
}

BOOST_AUTO_TEST_CASE (Distance_modification_operator)
{
	Distance temp_distance(test_width, test_height);
	Distance temp_distance2(test_width + 1, test_height);
	Distance temp_distance3 = temp_distance + temp_distance2;

	BOOST_CHECK_EQUAL(temp_distance3.getWidth(), test_width+test_width + 1);
	BOOST_CHECK_EQUAL(temp_distance3.getHeight(), test_height+test_height);

	Distance temp_distance4 = temp_distance2 - temp_distance;

	BOOST_CHECK_EQUAL(temp_distance4.getWidth(), 1);
	BOOST_CHECK_EQUAL(temp_distance4.getHeight(), 0);

	Distance temp_distance5 = (temp_distance + temp_distance)/2;

	BOOST_CHECK_EQUAL(temp_distance.getWidth(), test_width);
	BOOST_CHECK_EQUAL(temp_distance.getHeight(), test_height);

}

BOOST_AUTO_TEST_CASE (Distance_Length)
{
	BOOST_CHECK_EQUAL(test_distance->getLength(), static_cast<unsigned int>(sqrt(static_cast<float>(test_width * test_width + test_height * test_height))));
}

BOOST_AUTO_TEST_SUITE_END()

	// --- DISTANCE END ---


	// --- SIZE ---

	BOOST_FIXTURE_TEST_SUITE( Size_test, Size_Fixture )

	BOOST_AUTO_TEST_CASE (Size_constructor)
{
	BOOST_CHECK_EQUAL(test_size->getWidth(), test_width);
	BOOST_CHECK_EQUAL(test_size->getHeight(), test_height);

	std::ostringstream os;
	os << (test_width) << "x" << (test_height);
	BOOST_CHECK_EQUAL(test_size->toString(), os.str());
}

BOOST_AUTO_TEST_CASE (Size_set)
{
	Distance test_size2(test_width, test_height);
	test_size2.setWidth(test_width*2);
	BOOST_CHECK_EQUAL(test_size2.getWidth(), test_width*2);

	test_size2.setHeight(test_height*2);
	BOOST_CHECK_EQUAL(test_size2.getHeight(), test_height*2);		
}

BOOST_AUTO_TEST_CASE (Size_copy_constructor)
{
	Size temp_size(*test_size);

	BOOST_CHECK_EQUAL(temp_size.getWidth(), test_width);
	BOOST_CHECK_EQUAL(temp_size.getHeight(), test_height);
}

BOOST_AUTO_TEST_CASE (Size_assignment_operator)
{
	Size temp_size = *test_size;

	BOOST_CHECK_EQUAL(temp_size.getWidth(), test_width);
	BOOST_CHECK_EQUAL(temp_size.getHeight(), test_height);
}

BOOST_AUTO_TEST_CASE (Size_compare_operator)
{
	Size temp_size(test_width, test_height);

	BOOST_CHECK(temp_size == *test_size);

	Size temp_size2(temp_size + Size(1, 0));
	Size temp_size3(temp_size + Size(1, 1));

	BOOST_CHECK(!(temp_size2 < *test_size));
	BOOST_CHECK(!(*test_size > temp_size2));
	BOOST_CHECK(temp_size3 > *test_size);
	BOOST_CHECK(*test_size < temp_size3);

	BOOST_CHECK(!(temp_size != *test_size));
}

BOOST_AUTO_TEST_CASE (Size_modification_operator)
{
	Size temp_size(test_width, test_height);
	Size temp_size2(temp_size + Size(1, 0));
	Size temp_size3 = temp_size + temp_size2;

	BOOST_CHECK_EQUAL(temp_size3.getWidth(), test_width + test_width + static_cast<Uint16>(1));
	BOOST_CHECK_EQUAL(temp_size3.getHeight(), test_height + test_height);

	Size temp_size4 = temp_size2 - temp_size;

	BOOST_CHECK_EQUAL(temp_size4.getWidth(), static_cast<Uint16>(1));
	BOOST_CHECK_EQUAL(temp_size4.getHeight(), static_cast<Uint16>(0));

	Size temp_size5 = (temp_size + temp_size)/2;

	BOOST_CHECK_EQUAL(temp_size.getWidth(), test_width);
	BOOST_CHECK_EQUAL(temp_size.getHeight(), test_height);

}

// TODO make better check
BOOST_AUTO_TEST_CASE (Size_movement)
{
	Size temp_size = *test_size;

	if(temp_size != *test_target_size) {

		temp_size.move(*test_size, *test_target_size);
		// did we move away from starting point?
		BOOST_CHECK(temp_size != *test_size);
		Size last_size = temp_size;
		if(temp_size != *test_target_size) {
			temp_size.move(*test_size, *test_target_size);
			// did we move away from starting point?
			BOOST_CHECK(temp_size != last_size);

			// did we reach target point at least after n steps? TODO make logarithmic
			int maxx = 0;
			int maxy = 0;
			if(test_size->getWidth() >= test_target_size->getWidth()) {
				maxx = test_size->getWidth() - test_target_size->getWidth();
			} else {
				maxx = test_target_size->getWidth() - test_size->getWidth();
			}
			if(test_size->getHeight() >= test_target_size->getHeight()) {
				maxy = test_size->getHeight() - test_target_size->getHeight();
			} else {
				maxy = test_target_size->getHeight() - test_size->getHeight();
			}
			int max = maxx > maxy?maxx:maxy;
			for(int i = 0; i < max; i++) {
				temp_size.move(*test_size, *test_target_size);
			}
			BOOST_CHECK_EQUAL(temp_size, *test_target_size);
		}
	}

}


BOOST_AUTO_TEST_SUITE_END()

	// --- SIZE END ---



	// --- POINT ---

	BOOST_FIXTURE_TEST_SUITE( Point_test, Point_Fixture)

	BOOST_AUTO_TEST_CASE (Point_constructor)
{
	BOOST_CHECK_EQUAL(test_point->getX(), test_x);
	BOOST_CHECK_EQUAL(test_point->getY(), test_y);
}

BOOST_AUTO_TEST_CASE (Point_assignment_constructor)
{
	Point temp_point(*test_point);

	BOOST_CHECK_EQUAL(temp_point.getX(), test_x);
	BOOST_CHECK_EQUAL(temp_point.getY(), test_y);
}

BOOST_AUTO_TEST_CASE (Point_assignment_operator)
{
	Point temp_point = *test_point;

	BOOST_CHECK_EQUAL(temp_point.getX(), test_x);
	BOOST_CHECK_EQUAL(temp_point.getY(), test_y);
}

BOOST_AUTO_TEST_CASE (Point_comparison_operator)
{
	Point temp_point(test_x, test_y);
	Point temp_point2(temp_point + Size(0, 1));
	Point temp_point3(temp_point + Size(1, 1));

	BOOST_CHECK(temp_point == *test_point); 
	BOOST_CHECK(temp_point2 != *test_point); 

	BOOST_CHECK(temp_point3 > temp_point);
	BOOST_CHECK(temp_point < temp_point3);
	BOOST_CHECK(temp_point2 >= temp_point);
	BOOST_CHECK(temp_point <= temp_point2);
}

BOOST_AUTO_TEST_CASE (Point_simple_movement)
{
	Point temp_point(test_x, test_y);

	temp_point += Size(1, 1);

	BOOST_CHECK_EQUAL(temp_point.getX(), test_x+static_cast<Sint16>(1));
	BOOST_CHECK_EQUAL(temp_point.getY(), test_y+static_cast<Uint16>(1));

	temp_point -= Size(0, 2);

	BOOST_CHECK_EQUAL(temp_point.getX(), test_x+static_cast<Sint16>(1));
	BOOST_CHECK_EQUAL(temp_point.getY(), test_y-static_cast<Sint16>(1));
}

// TODO make better check
BOOST_AUTO_TEST_CASE (Point_movement)
{
	Point temp_point = *test_point;

	Size s = temp_point - *test_point;
	BOOST_REQUIRE_EQUAL(s.getDiagonalLength(), static_cast<Uint16>(0));


	if(temp_point != *test_target_point) {

		temp_point.move(*test_point, *test_target_point);
		// did we move away from starting point?
		BOOST_CHECK(temp_point != *test_point);
		Point last_point = temp_point;
		if(temp_point != *test_target_point) {
			temp_point.move(*test_point, *test_target_point);
			// did we move away from starting point?
			BOOST_CHECK(temp_point != last_point);

			// did we reach target point at least after n steps? TODO make logarithmic
			s = *test_point - *test_target_point;
			for(unsigned int i = 0; i < s.getDiagonalLength(); i++) {
				temp_point.move(*test_point, *test_target_point);
			}
			BOOST_CHECK_EQUAL(temp_point, *test_target_point);
		}
	}

}



BOOST_AUTO_TEST_CASE (Point_size)
{
	Point temp_point(*test_point + Size(10, 12));

	Size temp_size = temp_point - *test_point;

	BOOST_CHECK_EQUAL(temp_size.getWidth(), static_cast<Uint16>(10));
	BOOST_CHECK_EQUAL(temp_size.getHeight(), static_cast<Uint16>(12));
}

BOOST_AUTO_TEST_CASE (Point_arithmetic)
{
	Point temp_point2 = *test_point * 2;

	BOOST_CHECK_EQUAL(temp_point2.getX(), 2*test_x);
	BOOST_CHECK_EQUAL(temp_point2.getY(), 2*test_y);

	temp_point2 = temp_point2 + Size(1,1);

	BOOST_CHECK_EQUAL(temp_point2.getX(), 2*test_x+1);
	BOOST_CHECK_EQUAL(temp_point2.getY(), 2*test_y+1);

	temp_point2 = temp_point2 - Size(1,1);

	BOOST_CHECK_EQUAL(temp_point2.getX(), 2*test_x);
	BOOST_CHECK_EQUAL(temp_point2.getY(), 2*test_y);

	Point temp_point3 = *test_point * 3;

	BOOST_CHECK_EQUAL(temp_point3.getX(), 3*test_x);
	BOOST_CHECK_EQUAL(temp_point3.getY(), 3*test_y);
}


BOOST_AUTO_TEST_CASE (Point_string)
{
	std::ostringstream os;
	os << test_point->getX() << ":" << test_point->getY();
	BOOST_CHECK_EQUAL(test_point->toString(), os.str());	
}

BOOST_AUTO_TEST_SUITE_END( )

	// --- END Point ---


	// --- RECT ---

	BOOST_FIXTURE_TEST_SUITE( Rect_test, Rect_Fixture)

	BOOST_AUTO_TEST_CASE (Rect_emptyconstructor)
{
	Rect test_rect;
	BOOST_CHECK_EQUAL(test_rect.getTopLeft(), Point());
	BOOST_CHECK_EQUAL(test_rect.getBottomRight(), Point());
}

BOOST_AUTO_TEST_CASE (Rect_constructor)
{
	BOOST_CHECK_EQUAL(test_rect1->getTopLeft(), test_topLeftCorner);
	BOOST_CHECK_EQUAL(test_rect1->getBottomRight(), test_bottomRightCorner);
	BOOST_CHECK_EQUAL(test_rect2->getTopLeft(), test_topLeftCorner);
	BOOST_CHECK_EQUAL(test_rect2->getBottomRight(), test_bottomRightCorner);
	BOOST_CHECK_EQUAL(test_rect3->getTopLeft(), test_topLeftCorner);
	BOOST_CHECK_EQUAL(test_rect3->getBottomRight(), test_bottomRightCorner);

	BOOST_CHECK_EQUAL(test_rect1->getLeft(), test_topLeftCorner.getX());
	BOOST_CHECK_EQUAL(test_rect1->getRight(), test_bottomRightCorner.getX());
	BOOST_CHECK_EQUAL(test_rect1->getTop(), test_topLeftCorner.getY());
	BOOST_CHECK_EQUAL(test_rect1->getBottom(), test_bottomRightCorner.getY());
	BOOST_CHECK_EQUAL(test_rect1->getBottomLeft(), test_topLeftCorner + Size(0, test_rectSize.getHeight()));
	BOOST_CHECK_EQUAL(test_rect1->getTopRight(), test_topLeftCorner + Size(test_rectSize.getWidth(), static_cast<Sint16>(0)));

	BOOST_CHECK_EQUAL(test_rect1->getSize(), test_rectSize);
	BOOST_CHECK_EQUAL(test_rect1->getWidth(), test_rectSize.getWidth());
	BOOST_CHECK_EQUAL(test_rect1->getHeight(), test_rectSize.getHeight());

	std::ostringstream os;
	os << "(" << test_rect1->getLeft() << " " << test_rect1->getTop() << ") (" << test_rect1->getWidth() << " " << test_rect1->getHeight() << ")";
	BOOST_CHECK_EQUAL(test_rect1->toString(), os.str());		
}


BOOST_AUTO_TEST_CASE (Rect_assignment_constructor)
{
	Rect temp_rect(*test_rect1);

	BOOST_CHECK_EQUAL(temp_rect.getTopLeft(), test_topLeftCorner);
	BOOST_CHECK_EQUAL(temp_rect.getBottomRight(), test_bottomRightCorner);
	BOOST_CHECK_EQUAL(temp_rect.getSize(), test_rectSize);
}

BOOST_AUTO_TEST_CASE (Rect_assignment_operator)
{
	Rect temp_rect = *test_rect1;

	BOOST_CHECK_EQUAL(temp_rect.getTopLeft(), test_topLeftCorner);
	BOOST_CHECK_EQUAL(temp_rect.getBottomRight(), test_bottomRightCorner);
	BOOST_CHECK_EQUAL(temp_rect.getSize(), test_rectSize);
}

BOOST_AUTO_TEST_CASE (Rect_create_SDL_Rect)
{
	SDL_Rect r1 = Rect::createRect(test_topLeftCorner.getX(), test_topLeftCorner.getY(), test_rectSize.getWidth(), test_rectSize.getHeight());
	SDL_Rect r2 = Rect::createRect(*test_rect1);

	BOOST_CHECK_EQUAL(r1.x, test_topLeftCorner.getX());
	BOOST_CHECK_EQUAL(r1.y, test_topLeftCorner.getY());
	BOOST_CHECK_EQUAL(r1.w, test_rectSize.getWidth());
	BOOST_CHECK_EQUAL(r1.h, test_rectSize.getHeight());

	BOOST_CHECK_EQUAL(r2.x, test_topLeftCorner.getX());
	BOOST_CHECK_EQUAL(r2.y, test_topLeftCorner.getY());
	BOOST_CHECK_EQUAL(r2.w, test_rectSize.getWidth());
	BOOST_CHECK_EQUAL(r2.h, test_rectSize.getHeight());
}


BOOST_AUTO_TEST_CASE (Rect_pixelInside)
{
	BOOST_REQUIRE(!test_rect1->isPixelInside(static_cast<Sint16>(test_rect1->getLeft() - 1), test_rect1->getTop()));
	BOOST_REQUIRE(!test_rect1->isPixelInside(test_rect1->getRight(), test_rect1->getTop()));
	BOOST_REQUIRE(!test_rect1->isPixelInside(test_rect1->getLeft(), static_cast<Sint16>(test_rect1->getTop()-1)));
	BOOST_REQUIRE(!test_rect1->isPixelInside(test_rect1->getLeft(), test_rect1->getBottom()));

	BOOST_REQUIRE(test_rect1->isPixelInside(test_rect1->getLeft(), test_rect1->getTop()));

	for(unsigned int i = 0; i < 100; i++) {
		Point p(static_cast<Sint16>(RandomGenerator::instance().rnd()), static_cast<Sint16>(RandomGenerator::instance().rnd()));

		if(p >= test_rect1->getTopLeft() && p < test_rect1->getBottomRight()) {
			BOOST_CHECK(test_rect1->isPixelInside(p));
		} else {
			BOOST_CHECK(!test_rect1->isPixelInside(p));
		}
	}
}

BOOST_AUTO_TEST_CASE (Rect_setTopLeft)
{
	Rect temp_rect = *test_rect1;

	temp_rect.setTopLeft(test_topLeftCorner + Size(2, 1));

	BOOST_CHECK_EQUAL(temp_rect.getTopLeft(), test_topLeftCorner + Size(2, 1));
	BOOST_CHECK_EQUAL(temp_rect.getBottomRight(), test_bottomRightCorner + Size(2, 1));
	BOOST_CHECK_EQUAL(temp_rect.getSize(), test_rectSize);
}

BOOST_AUTO_TEST_CASE (Rect_setSize)
{
	Rect temp_rect = *test_rect1;

	temp_rect.setSize(test_rectSize + Size(1,2));

	BOOST_CHECK_EQUAL(temp_rect.getTopLeft(), test_topLeftCorner);
	BOOST_CHECK_EQUAL(temp_rect.getBottomRight(), test_bottomRightCorner + Size(1, 2));
	BOOST_CHECK_EQUAL(temp_rect.getSize(), test_rectSize + Size(1, 2) );
}


BOOST_AUTO_TEST_CASE (Rect_setWidth)
{
	Rect temp_rect = *test_rect1;

	temp_rect.setWidth(static_cast<Sint16>(test_rectSize.getWidth() + 1));

	BOOST_CHECK_EQUAL(temp_rect.getTopLeft(), test_topLeftCorner);
	BOOST_CHECK_EQUAL(temp_rect.getBottomRight(), test_bottomRightCorner + Size(1, 0));
	BOOST_CHECK_EQUAL(temp_rect.getSize(), test_rectSize + Size(1, 0) );
}

BOOST_AUTO_TEST_CASE (Rect_setHeight)
{
	Rect temp_rect = *test_rect1;

	temp_rect.setHeight(static_cast<Sint16>(test_rectSize.getHeight() + 1));

	BOOST_CHECK_EQUAL(temp_rect.getTopLeft(), test_topLeftCorner);
	BOOST_CHECK_EQUAL(temp_rect.getBottomRight(), test_bottomRightCorner + Size(0, 1));
	BOOST_CHECK_EQUAL(temp_rect.getSize(), test_rectSize + Size(0, 1) );
}

BOOST_AUTO_TEST_CASE (Rect_setTop)
{
	Rect temp_rect = *test_rect1;

	temp_rect.setTop(static_cast<Sint16>(test_topLeftCorner.getY() - 1));

	BOOST_CHECK_EQUAL(temp_rect.getTopLeft(), test_topLeftCorner - Size(0, 1));
	BOOST_CHECK_EQUAL(temp_rect.getBottomRight(), test_bottomRightCorner - Size(0, 1));
	BOOST_CHECK_EQUAL(temp_rect.getSize(), test_rectSize);
}

BOOST_AUTO_TEST_CASE (Rect_setBottom)
{
	Rect temp_rect = *test_rect1;

	temp_rect.setBottom(static_cast<Sint16>(test_bottomRightCorner.getY() + 1));

	BOOST_CHECK_EQUAL(temp_rect.getTopLeft(), test_topLeftCorner);
	BOOST_CHECK_EQUAL(temp_rect.getBottomRight(), test_bottomRightCorner + Size(0, 1));
	BOOST_CHECK_EQUAL(temp_rect.getSize(), test_rectSize + Size(0, 1));
}

BOOST_AUTO_TEST_CASE (Rect_setLeft)
{
	Rect temp_rect = *test_rect1;

	temp_rect.setLeft(static_cast<Sint16>(test_topLeftCorner.getX() - 1));

	BOOST_CHECK_EQUAL(temp_rect.getTopLeft(), test_topLeftCorner - Size(1, 0) );
	BOOST_CHECK_EQUAL(temp_rect.getBottomRight(), test_bottomRightCorner - Size(1, 0));
	BOOST_CHECK_EQUAL(temp_rect.getSize(), test_rectSize);
}

BOOST_AUTO_TEST_CASE (Rect_setRight)
{
	Rect temp_rect = *test_rect1;

	temp_rect.setRight(static_cast<Sint16>(test_bottomRightCorner.getX() + 1));

	BOOST_CHECK_EQUAL(temp_rect.getTopLeft(), test_topLeftCorner);
	BOOST_CHECK_EQUAL(temp_rect.getBottomRight(), test_bottomRightCorner + Size(1, 0));
	BOOST_CHECK_EQUAL(temp_rect.getSize(), test_rectSize + Size(1,0));
}



BOOST_AUTO_TEST_CASE (Rect_operatoradd)
{
	Rect temp_rect = *test_rect1 + Point(3,4);

	BOOST_CHECK_EQUAL(temp_rect.getTopLeft(), test_topLeftCorner + Size(3,4));
	BOOST_CHECK_EQUAL(temp_rect.getBottomRight(), test_bottomRightCorner + Size(3, 4));
	BOOST_CHECK_EQUAL(temp_rect.getSize(), test_rectSize);

	BOOST_CHECK(temp_rect != *test_rect1);
}


BOOST_AUTO_TEST_CASE(Rect_testpointinside)
{
	for(int i = 0; i < 100; i++) {
		Sint16 x = static_cast<Sint16>(RandomGenerator::instance().rnd());
		Sint16 y = static_cast<Sint16>(RandomGenerator::instance().rnd());

		if(x < test_rect1->getRight() && x >= test_rect1->getLeft() && y < test_rect1->getBottom() && y >= test_rect1->getTop()) {
			BOOST_REQUIRE(test_rect1->isTopLeftCornerInside(x, y));
		} else {
			BOOST_REQUIRE(!test_rect1->isTopLeftCornerInside(x, y));
		}

		if(x <= test_rect1->getRight() && x > test_rect1->getLeft() && y < test_rect1->getBottom() && y >= test_rect1->getTop()) {
			BOOST_REQUIRE(test_rect1->isTopRightCornerInside(x, y));
		} else {
			BOOST_REQUIRE(!test_rect1->isTopRightCornerInside(x, y));
		}

		if(x <= test_rect1->getRight() && x > test_rect1->getLeft() && y <= test_rect1->getBottom() && y > test_rect1->getTop()) {
			BOOST_REQUIRE(test_rect1->isBottomRightCornerInside(x, y));
		} else {
			BOOST_REQUIRE(!test_rect1->isBottomRightCornerInside(x, y));
		}

		if(x < test_rect1->getRight() && x >= test_rect1->getLeft() && y <= test_rect1->getBottom() && y > test_rect1->getTop()) {
			BOOST_REQUIRE(test_rect1->isBottomLeftCornerInside(x, y));
		} else {
			BOOST_REQUIRE(!test_rect1->isBottomLeftCornerInside(x, y));
		}
	}
}

BOOST_AUTO_TEST_CASE(Rect_istouched)
{
	for(int i = 0; i < 1000; i++) { 
		Sint16 x = static_cast<Sint16>(RandomGenerator::instance().rnd());
		Sint16 y = static_cast<Sint16>(RandomGenerator::instance().rnd());
		Uint16 w = static_cast<Uint16>(RandomGenerator::instance().rnd());
		Uint16 h = static_cast<Uint16>(RandomGenerator::instance().rnd());
		Rect r(x,y,w,h);

		if(x >= test_rect1->getRight() || x+w <= test_rect1->getLeft() || y >= test_rect1->getBottom() || y+h <= test_rect1->getTop()) {
			BOOST_REQUIRE(!test_rect1->isTouched(r));
		} else {
			BOOST_REQUIRE(test_rect1->isTouched(r));
		}
	}
}

BOOST_AUTO_TEST_CASE(Rect_commonrect)
{
	Rect r1(10,10,100,100);
	Rect r2(1,1,10,10);
	Rect r3(10,1,10,10);
	Rect r4(105,2,10,10);
	Rect r5(109,25,10,10);
	Rect r6(50,109,10,10);
	Rect r7(2,20,10,10);
	Rect r8(1,109,10,10);
	Rect r9(11, 11, 99, 99);

	Rect r12 = r1.commonRect(r2);
	Rect r13 = r1.commonRect(r3);
	Rect r14 = r1.commonRect(r4);
	Rect r15 = r1.commonRect(r5);
	Rect r16 = r1.commonRect(r6);
	Rect r17 = r1.commonRect(r7);
	Rect r18 = r1.commonRect(r8);
	Rect r19 = r1.commonRect(r9);

	BOOST_CHECK_EQUAL(r12, Rect(10, 10, 1, 1));
	BOOST_CHECK_EQUAL(r13, Rect(10, 10, 10, 1));
	BOOST_CHECK_EQUAL(r14, Rect(105, 10, 5, 2));
	BOOST_CHECK_EQUAL(r15, Rect(109, 25, 1, 10));
	BOOST_CHECK_EQUAL(r16, Rect(50, 109, 10, 1));
	BOOST_CHECK_EQUAL(r17, Rect(10, 20, 2, 10));
	BOOST_CHECK_EQUAL(r18, Rect(10, 109, 1, 1));
	BOOST_CHECK_EQUAL(r19, r9);
}

BOOST_AUTO_TEST_CASE(RECT_withoutrect)
{
	Rect r1(10,10,100,100); // main rect 
	Rect r2(1,1,10,10); // top left corner
	Rect r3(10,1,10,10); // top center
	Rect r4(105,2,10,10); // top right corner
	Rect r5(109,109,10,10); // bottom right corner
	Rect r6(109,25,10,10); // bottom center
	Rect r7(50,109,10,10); // 
	Rect r8(2,20,10,10);
	Rect r9(1,109,10,10);
	Rect r10(11,11,98,98);
	Rect r11(r1); // same rect
	Rect r12(200, 200, 100, 100); // no common rect

	Rect r13(1, 20, 120, 60); // left and right border
	Rect r14(20, 1, 60, 120); // top and bottom border

	std::list<Rect> r1_2 = r1.withoutRect(r2);
	std::list<Rect> r1_3 = r1.withoutRect(r3);
	std::list<Rect> r1_4 = r1.withoutRect(r4);
	std::list<Rect> r1_5 = r1.withoutRect(r5);
	std::list<Rect> r1_6 = r1.withoutRect(r6);
	std::list<Rect> r1_7 = r1.withoutRect(r7);
	std::list<Rect> r1_8 = r1.withoutRect(r8);
	std::list<Rect> r1_9 = r1.withoutRect(r9);
	std::list<Rect> r1_10 = r1.withoutRect(r10);
	std::list<Rect> r1_11 = r1.withoutRect(r11);
	std::list<Rect> r1_12 = r1.withoutRect(r12);
	std::list<Rect> r1_13 = r1.withoutRect(r13);
	std::list<Rect> r1_14 = r1.withoutRect(r14);


	BOOST_CHECK_EQUAL(r1_2.front(), Rect(11, 10, 99, 1));
	BOOST_CHECK_EQUAL(r1_2.back(), Rect(10, 11, 100, 99));
	BOOST_CHECK_EQUAL(r1_3.front(), Rect(20, 10, 90, 1));
	BOOST_CHECK_EQUAL(r1_3.back(), Rect(10, 11, 100, 99));
	BOOST_CHECK_EQUAL(r1_4.front(), Rect(10, 10, 95, 2));
	BOOST_CHECK_EQUAL(r1_4.back(), Rect(10, 12, 100, 98));

	BOOST_CHECK_EQUAL(r1_5.front(), Rect(10, 10, 100, 99));
	BOOST_CHECK_EQUAL(r1_5.back(), Rect(10, 109, 99, 1));

	BOOST_CHECK_EQUAL(r1_6.front(), Rect(10, 10, 100, 15));
	r1_6.pop_front();
	BOOST_CHECK_EQUAL(r1_6.front(), Rect(10, 25, 99, 10));
	BOOST_CHECK_EQUAL(r1_6.back(), Rect(10, 35, 100, 75));
	BOOST_CHECK_EQUAL(r1_7.front(), Rect(10, 10, 100, 99));
	r1_7.pop_front();
	BOOST_CHECK_EQUAL(r1_7.front(), Rect(10, 109, 40, 1));
	BOOST_CHECK_EQUAL(r1_7.back(), Rect(60, 109, 50, 1));
	BOOST_CHECK_EQUAL(r1_8.front(), Rect(10, 10, 100, 10));
	r1_8.pop_front();
	BOOST_CHECK_EQUAL(r1_8.front(), Rect(12, 20, 98, 10));
	BOOST_CHECK_EQUAL(r1_8.back(), Rect(10, 30, 100, 80));
	BOOST_CHECK_EQUAL(r1_9.front(), Rect(10, 10, 100, 99));
	BOOST_CHECK_EQUAL(r1_9.back(), Rect(11, 109, 99, 1));
	BOOST_CHECK_EQUAL(r1_10.front(), Rect(10, 10, 100, 1));
	r1_10.pop_front();
	BOOST_CHECK_EQUAL(r1_10.front(), Rect(10, 11, 1, 98));
	r1_10.pop_front();
	BOOST_CHECK_EQUAL(r1_10.front(), Rect(109, 11, 1, 98));
	r1_10.pop_front();
	BOOST_CHECK_EQUAL(r1_10.back(), Rect(10, 109, 100, 1));

	BOOST_CHECK_EQUAL(r1_11.size(), 0);
	BOOST_CHECK_EQUAL(r1_12.back(), r1);

	BOOST_CHECK_EQUAL(r1_13.front(), Rect(10, 10, 100, 10));
	BOOST_CHECK_EQUAL(r1_13.back(), Rect(10, 80, 100, 30));
	BOOST_CHECK_EQUAL(r1_14.front(), Rect(10, 10, 10, 100));
	BOOST_CHECK_EQUAL(r1_14.back(), Rect(80, 10, 30, 100));
}

BOOST_AUTO_TEST_CASE(Rect_testrectinside)
{
	for(unsigned int i = 0; i < 1000; i++) {	
		Sint16 x = static_cast<Sint16>(RandomGenerator::instance().rnd());
		Sint16 y = static_cast<Sint16>(RandomGenerator::instance().rnd());
		Uint16 w = static_cast<Uint16>(RandomGenerator::instance().rnd());
		Uint16 h = static_cast<Uint16>(RandomGenerator::instance().rnd());

		if((x >= test_rect1->getLeft()) && (y >= test_rect1->getTop()) && (x+w <= test_rect1->getRight()) && (y+h <= test_rect1->getBottom())) {
			BOOST_REQUIRE(test_rect1->isRectInside(Rect(x,y,w,h)));
		} else {
			BOOST_REQUIRE(!test_rect1->isRectInside(Rect(x,y,w,h)));
		}
	}
}




/*	
Rect& operator=(const Rect& rect);
bool operator==(const Rect& rect) const;
void moveSmooth(Rect& start_rect, Rect& target_rect);*/


BOOST_AUTO_TEST_SUITE_END( )

	// --- END RECT ---





	// --- ObjectSize ---

	BOOST_FIXTURE_TEST_SUITE( ObjectSize_test, ObjectSize_Fixture )

	BOOST_AUTO_TEST_CASE (ObjectSize_constructor)
{
	ObjectSize_Fixture_Helper testFixtureHelper(test_objectsize);

	test_objectsize->updateResolution(TEST_RESOLUTION2_ID);
	BOOST_CHECK_EQUAL(testFixtureHelper.getSize(), test_objectsize2_size);
	test_objectsize->updateResolution(TEST_RESOLUTION1_ID);
	BOOST_CHECK_EQUAL(testFixtureHelper.getSize(), test_objectsize1_size);
}

BOOST_AUTO_TEST_CASE (ObjectSize_simple_constructor)
{
	ObjectSize simple_test_objectsize(test_sizeMap);
	BOOST_CHECK_EQUAL(simple_test_objectsize.getSizeMap().find(TEST_RESOLUTION1_ID)->second, test_objectsize1_size);
	BOOST_CHECK_EQUAL(simple_test_objectsize.getSizeMap().find(TEST_RESOLUTION2_ID)->second, test_objectsize2_size);
}

BOOST_AUTO_TEST_CASE (ObjectSize_storage)
{
	ObjectSizeStorage::updateResolution(TEST_RESOLUTION1_ID);
	BOOST_CHECK_EQUAL(static_cast<Size>(*ObjectSizeStorage::instance().get(test_objectsize->getId())), test_objectsize1_size);

	ObjectSizeStorage::saveToXML();
	ObjectSizeStorage::reset();
	ObjectSizeStorage::updateResolution(TEST_RESOLUTION1_ID);

	BOOST_CHECK_EQUAL(static_cast<Size>(*ObjectSizeStorage::instance().get(test_objectsize->getId())), test_objectsize1_size);
		

	ObjectSizeStorage::saveToXML();
	ObjectSizeStorage::reset();
	ObjectSizeStorage::updateResolution(TEST_RESOLUTION2_ID);

	BOOST_CHECK_EQUAL(static_cast<Size>(*ObjectSizeStorage::instance().get(test_objectsize->getId())), test_objectsize2_size);
}



BOOST_AUTO_TEST_SUITE_END( )

	// --- END ObjectSize ---




	// --- Resolution ---

	BOOST_FIXTURE_TEST_SUITE( Resolution_test, Resolution_Fixture )

	BOOST_AUTO_TEST_CASE (Resolution_constructor)
{
	BOOST_CHECK_EQUAL(test_resolution->getName(), test_name);
	BOOST_CHECK_EQUAL(test_resolution->getSize(), test_size);
}

BOOST_AUTO_TEST_CASE (Resolution_storage)
{
	BOOST_CHECK_EQUAL(ResolutionStorage::instance().get(test_resolution->getId())->getName(), test_name);
	BOOST_CHECK_EQUAL(ResolutionStorage::instance().get(test_resolution->getId())->getSize(), test_size);

	ResolutionStorage::saveToXML();
	ResolutionStorage::reset();

	BOOST_CHECK_EQUAL(ResolutionStorage::instance().get(test_resolution->getId())->getName(), test_name);
	BOOST_CHECK_EQUAL(ResolutionStorage::instance().get(test_resolution->getId())->getSize(), test_size);
}

BOOST_AUTO_TEST_SUITE_END( )

	// --- END Resolution ---

	// ---- BEGIN LayoutManager ----


	BOOST_FIXTURE_TEST_SUITE( LayoutManager_test, LayoutManager_Fixture )

	BOOST_AUTO_TEST_CASE (LayoutManager_horizontal)
{
	BOOST_CHECK(true);
	PositionObject::setSmoothMovements(false);
	ObjectSizeStorage::updateResolution(test_objectSizeFixture1.TEST_RESOLUTION1_ID);	
	for(int i = 0; i < 4; i++) {
		test_positionObjectVector[i]->move();
	}

	test_layoutManagerVector[0]->doLayout();



	unsigned int total_width = 0;
	for(int i = 0; i < 4; i++) {
		test_positionObjectVector[i]->move();
		total_width += test_positionObjectVector[i]->getWidth();
	}

	unsigned int startx = test_parentObject->getAbsoluteLeftBound() + (test_parentObject->getWidth() - total_width)/2;
	unsigned int starty = test_parentObject->getAbsoluteUpperBound() + test_sizeFixture.test_height;

	BOOST_CHECK_EQUAL(test_positionObjectVector[0]->getAbsolutePosition(), Point(startx, starty)); startx += test_positionObjectVector[0]->getWidth();
	BOOST_CHECK_EQUAL(test_positionObjectVector[1]->getAbsolutePosition(), Point(startx, starty)); startx += test_positionObjectVector[1]->getWidth();
	BOOST_CHECK_EQUAL(test_positionObjectVector[2]->getAbsolutePosition(), Point(startx, starty)); startx += test_positionObjectVector[2]->getWidth();
	BOOST_CHECK_EQUAL(test_positionObjectVector[3]->getAbsolutePosition(), Point(startx, starty));
}

	BOOST_AUTO_TEST_CASE (LayoutManager_vertical)
{
	BOOST_CHECK(true);
	PositionObject::setSmoothMovements(false);
	ObjectSizeStorage::updateResolution(test_objectSizeFixture1.TEST_RESOLUTION1_ID);	
	for(int i = 4; i < 8; i++) {
		test_positionObjectVector[i]->move();
	}

	test_layoutManagerVector[1]->doLayout();

	for(int i = 4; i < 8; i++) {
		test_positionObjectVector[i]->move();
	}

	unsigned int startx = test_parentObject->getAbsoluteRightBound() - test_sizeFixture.test_width;
	unsigned int starty = test_parentObject->getAbsoluteUpperBound() + test_sizeFixture.test_height;

	BOOST_CHECK_EQUAL(test_positionObjectVector[4]->getAbsolutePosition(), Point(startx - test_positionObjectVector[4]->getWidth(), starty)); starty += test_positionObjectVector[4]->getHeight();
	BOOST_CHECK_EQUAL(test_positionObjectVector[5]->getAbsolutePosition(), Point(startx - test_positionObjectVector[5]->getWidth(), starty)); starty += test_positionObjectVector[5]->getHeight();
	BOOST_CHECK_EQUAL(test_positionObjectVector[6]->getAbsolutePosition(), Point(startx - test_positionObjectVector[6]->getWidth(), starty)); starty += test_positionObjectVector[6]->getHeight();
	BOOST_CHECK_EQUAL(test_positionObjectVector[7]->getAbsolutePosition(), Point(startx - test_positionObjectVector[7]->getWidth(), starty));
}

		/*
BOOST_AUTO_TEST_CASE (LayoutManager_grid_two_columns)
{
	BOOST_CHECK(true);
	PositionObject::setSmoothMovements(false);
	ObjectSizeStorage::updateResolution(test_objectSizeFixture1.TEST_RESOLUTION1_ID);	
	for(int i = 0; i < 4; i++) {
		test_positionObjectVector[i]->move();
	}

	test_layoutManagerVector[0]->doLayout();



	unsigned int total_width = 0;
	for(int i = 0; i < 4; i++) {
		test_positionObjectVector[i]->move();
		total_width += test_positionObjectVector[i]->getWidth();
	}

	unsigned int startx = test_parentObject->getAbsoluteLeftBound() + (test_parentObject->getWidth() - total_width)/2;
	unsigned int starty = test_parentObject->getAbsoluteUpperBound() + test_sizeFixture.test_height;
	// TODO check y
	BOOST_CHECK_EQUAL(test_positionObjectVector[0]->getAbsolutePosition(), Point(startx, starty)); startx += test_positionObjectVector[0]->getWidth();
	BOOST_CHECK_EQUAL(test_positionObjectVector[1]->getAbsolutePosition(), Point(startx, starty)); startx += test_positionObjectVector[1]->getWidth();
	BOOST_CHECK_EQUAL(test_positionObjectVector[2]->getAbsolutePosition(), Point(startx, starty)); startx += test_positionObjectVector[2]->getWidth();
	BOOST_CHECK_EQUAL(test_positionObjectVector[3]->getAbsolutePosition(), Point(startx, starty));
}

	
BOOST_AUTO_TEST_CASE (LayoutManager_grid_two_rows)
{
	BOOST_CHECK(true);
	PositionObject::setSmoothMovements(false);
	ObjectSizeStorage::updateResolution(test_objectSizeFixture1.TEST_RESOLUTION1_ID);	
	for(int i = 0; i < 4; i++) {
		test_positionObjectVector[i]->move();
	}

	test_layoutManagerVector[0]->doLayout();



	unsigned int total_width = 0;
	for(int i = 0; i < 4; i++) {
		test_positionObjectVector[i]->move();
		total_width += test_positionObjectVector[i]->getWidth();
	}

	unsigned int startx = test_parentObject->getAbsoluteLeftBound() + (test_parentObject->getWidth() - total_width)/2;
	unsigned int starty = test_parentObject->getAbsoluteUpperBound() + test_sizeFixture.test_height;
	// TODO check y
	BOOST_CHECK_EQUAL(test_positionObjectVector[0]->getAbsolutePosition(), Point(startx, starty)); startx += test_positionObjectVector[0]->getWidth();
	BOOST_CHECK_EQUAL(test_positionObjectVector[1]->getAbsolutePosition(), Point(startx, starty)); startx += test_positionObjectVector[1]->getWidth();
	BOOST_CHECK_EQUAL(test_positionObjectVector[2]->getAbsolutePosition(), Point(startx, starty)); startx += test_positionObjectVector[2]->getWidth();
	BOOST_CHECK_EQUAL(test_positionObjectVector[3]->getAbsolutePosition(), Point(startx, starty));
}*/

BOOST_AUTO_TEST_SUITE_END( )

	// ---- END LayoutManager ----