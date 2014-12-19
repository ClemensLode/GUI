#ifndef _SDL_FIXTURE_DCFIXTURE_HPP
#define _SDL_FIXTURE_DCFIXTURE_HPP

#pragma warning(push, 0)  
#include <boost/smart_ptr.hpp>
#pragma warning(pop)

#include <sdlwrap/dc.hpp>
#include <string>

struct DC_Fixture
{
	const Uint32 flags;
	const Uint32 nflags;
	const eBitDepth depth;

	const boost::scoped_ptr<DC> test_dc;

	DC_Fixture(const eBitDepth bitDepth = MAX_BITDEPTHS);	
	virtual ~DC_Fixture();
};

#endif // _SDL_FIXTURE_DCFIXTURE_HPP
