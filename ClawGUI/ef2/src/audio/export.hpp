#ifndef _SOUND_EXPORT_HPP
#define _SOUND_EXPORT_HPP

// define SDL_EXPORTS to make it a dll
#ifndef SOUND_API
    #ifdef _MSC_VER
        #define WIN32_LEAN_AND_MEAN
        #include <windows.h>
        #undef min
        #undef max
		#ifdef SOUND_EXPORTS
		    #define SOUND_API __declspec(dllexport)
		#else
		    #define SOUND_API __declspec(dllimport)
		#endif
		#else
		    #define SOUND_API
	# endif
#endif

#endif // _SDL_EXPORT_HPP