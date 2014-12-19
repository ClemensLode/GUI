#ifndef WIN32
#define BOOST_TEST_NO_MAIN
#define BOOST_TEST_DYN_LINK
#else
#undef main
#endif

#define BOOST_TEST_MAIN

#pragma warning(push, 0) 
#include <boost/test/unit_test.hpp>
#pragma warning(pop)

#include <sdlwrapfixture/dc_fixture.hpp>
#include "SDL.h"
#include <iostream>

BOOST_FIXTURE_TEST_SUITE( dc_test, DC_Fixture )

	BOOST_AUTO_TEST_CASE (dc_constructor)
    {
		BOOST_REQUIRE(test_dc->valid());
		BOOST_CHECK_EQUAL(test_dc->getBitDepth(), depth);
		BOOST_CHECK_EQUAL(test_dc->getBits(), (depth+1)*8);
		BOOST_CHECK_EQUAL(test_dc->getSize().getWidth(), 640);
		BOOST_CHECK_EQUAL(test_dc->getSize().getHeight(), 480);
		BOOST_CHECK_EQUAL(test_dc->w(), 640);
		BOOST_CHECK_EQUAL(test_dc->h(), 480);
		BOOST_CHECK_EQUAL(test_dc->getMaxX(), 639);
		BOOST_CHECK_EQUAL(test_dc->getMaxY(), 479);
		BOOST_CHECK_EQUAL(test_dc->isFullScreen(), false);
    }

#ifdef WIN32
	BOOST_AUTO_TEST_CASE (dc_fullscreen)
    {
		BOOST_REQUIRE(test_dc->valid());
		test_dc->setFullScreen(true);
		SDL_Delay(1000);
		//BOOST_CHECK_EQUAL(test_dc->isFullScreen(), true);

		test_dc->setFullScreen(false);
		BOOST_CHECK_EQUAL(test_dc->isFullScreen(), false);

		test_dc->setFullScreen(true);
		BOOST_CHECK_EQUAL(test_dc->isFullScreen(), true);
    }
#endif

	BOOST_AUTO_TEST_CASE (dc_bitdepth)
    {
		BOOST_REQUIRE(test_dc->valid());
		BOOST_CHECK_EQUAL(test_dc->getBitDepth(), depth);
		test_dc->setBitDepth(DEPTH_16BIT);
		BOOST_CHECK_EQUAL(test_dc->getBitDepth(), DEPTH_16BIT);
		test_dc->setBitDepth(DEPTH_24BIT);
		BOOST_CHECK_EQUAL(test_dc->getBitDepth(), DEPTH_24BIT);
		test_dc->setBitDepth(DEPTH_32BIT);
		BOOST_CHECK_EQUAL(test_dc->getBitDepth(), DEPTH_32BIT);
    }

	BOOST_AUTO_TEST_CASE (dc_size)
    {
		BOOST_REQUIRE(test_dc->valid());
		BOOST_CHECK_EQUAL(test_dc->w(), 640);
		BOOST_CHECK_EQUAL(test_dc->h(), 480);
		test_dc->setResolution(Size(800,600));
		BOOST_CHECK_EQUAL(test_dc->w(), 800);
		BOOST_CHECK_EQUAL(test_dc->h(), 600);
		test_dc->setResolution(Size(1024,768));
		BOOST_CHECK_EQUAL(test_dc->w(), 1024);
		BOOST_CHECK_EQUAL(test_dc->h(), 768);
		test_dc->setResolution(Size(1280,1024));
		BOOST_CHECK_EQUAL(test_dc->w(), 1280);
		BOOST_CHECK_EQUAL(test_dc->h(), 1024);
		test_dc->setResolution(Size(1920,1080));
		BOOST_CHECK_EQUAL(test_dc->w(), 1920);
		BOOST_CHECK_EQUAL(test_dc->h(), 1080);
    }


BOOST_AUTO_TEST_SUITE_END()

// required because of SDL
int main( int argc, char* argv[] )
{
#ifdef WIN32
	return ::boost::unit_test::unit_test_main(&init_unit_test_suite, argc, argv); 
#else
	return ::boost::unit_test::unit_test_main(&init_unit_test, argc, argv); 
#endif
}
