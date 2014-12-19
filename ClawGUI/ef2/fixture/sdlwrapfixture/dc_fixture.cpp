#include <misc/randomgenerator.hpp>

#include "dc_fixture.hpp"


DC_Fixture::DC_Fixture(const eBitDepth bitDepth):
	flags(SDL_HWSURFACE|SDL_ASYNCBLIT|SDL_HWACCEL|SDL_HWPALETTE|SDL_SRCCOLORKEY|SDL_RLEACCEL|SDL_SRCALPHA|SDL_PREALLOC|SDL_DOUBLEBUF),
	nflags(SDL_INIT_NOPARACHUTE | SDL_INIT_VIDEO | SDL_INIT_TIMER),
	depth(bitDepth != MAX_BITDEPTHS?static_cast<eBitDepth>(RandomGenerator::instance().rnd()%4) : bitDepth),
	test_dc(new DC(nflags))
{ 
	test_dc->setScreen(Size(640, 480), depth, flags);	
}

DC_Fixture::~DC_Fixture() 
{ }
