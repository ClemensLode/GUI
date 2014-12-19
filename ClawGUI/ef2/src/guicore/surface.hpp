#ifndef _SDL_SURFACE_HPP
#define _GUICORE_SURFACE_HPP

#pragma warning(push, 0)  
#include <SDL.h>
#pragma warning(pop)

class Surface
{
	public:
		static bool Lock(SDL_Surface* s);
		static void Unlock(SDL_Surface* s);
	private:
		Surface();
		~Surface();
};



#endif // _GUICORE_SURFACE_HPP