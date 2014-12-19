#ifndef _SDL_EXPORT_HPP
#define _SDL_EXPORT_HPP

#define SDL_API
// define SDL_EXPORTS to make it a dll
/*#ifndef SDL_API
    #ifdef _MSC_VER
        #define WIN32_LEAN_AND_MEAN
        #include <windows.h>
        #undef min
        #undef max
		#ifdef SDL_EXPORTS
		    #define SDL_API __declspec(dllexport)
		#else
		    #define SDL_API __declspec(dllimport)
		#endif
		#else
		    #define SDL_API
	# endif
#endif*/

#endif // _SDL_EXPORT_HPP