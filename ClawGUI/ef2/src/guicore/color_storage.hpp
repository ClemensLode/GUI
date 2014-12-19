#ifndef _GUICORE_STORAGES_COLOR_STORAGE_HPP
#define _GUICORE_STORAGES_COLOR_STORAGE_HPP

#include <misc/singlestorage.hpp>
#include <SDL.h>

#include "color.hpp"

class ColorStorage : public SingleStorage<Color>
{ 
public:
	// call when sdl_surface has changed (e.g. new bit depth)
	static void updateTheme(const SDL_PixelFormat* pixelFormat, const boost::uuids::uuid themeId);
	static boost::uuids::uuid getCurrentThemeId();

private:
	static boost::uuids::uuid currentThemeId;
};


inline boost::uuids::uuid ColorStorage::getCurrentThemeId() {
	return currentThemeId;
}

#endif // _GUICORE_STORAGES_COLOR_STORAGE_HPP
