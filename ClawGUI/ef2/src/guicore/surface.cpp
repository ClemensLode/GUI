#include "surface.hpp"

#pragma warning(push, 0)  
#include <boost/assert.hpp>
#pragma warning(pop)

bool Surface::Lock(SDL_Surface* s) {
	BOOST_ASSERT(s);
	if(SDL_MUSTLOCK(s)) {
		return SDL_LockSurface(s) == 0;
	}
	else return true;
}

void Surface::Unlock(SDL_Surface* s) {
	BOOST_ASSERT(s);
	if(SDL_MUSTLOCK(s)) {
		SDL_UnlockSurface(s);
	}
}
