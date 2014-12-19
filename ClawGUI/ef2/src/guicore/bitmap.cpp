#include "bitmap.hpp"

#include <misc/exceptions.hpp>
#include <misc/io.hpp>

Bitmap::Bitmap(const std::string& fileName, const boost::shared_ptr<const ObjectSize> objectSize, const bool transparent):
	fileName(fileName),
	objectSize(objectSize),
	transparent(transparent),
	bitmap(IMG_Load((BITMAP_DIRECTORY + fileName).c_str()))
{
	if(!bitmap) {
		throw SDLException("ERROR (Bitmap::Bitmap()): Loading file " + (BITMAP_DIRECTORY + fileName) + " (" + IMG_GetError() + ").");
	}
}

Bitmap::Bitmap(const boost::uuids::uuid id, const std::string& fileName, const boost::shared_ptr<const ObjectSize> objectSize, const bool transparent):
	UUID<Bitmap>(id),
	fileName(fileName),
	objectSize(objectSize),
	transparent(transparent),
	bitmap(IMG_Load((BITMAP_DIRECTORY + fileName).c_str()))
{
	if(!bitmap) {
		throw SDLException("ERROR (Bitmap::Bitmap()): Loading file " + (BITMAP_DIRECTORY + fileName) + " (" + IMG_GetError() + ").");
	}
}

Bitmap::~Bitmap() {
	SDL_FreeSurface(bitmap);
}

bool Bitmap::equals(SDL_Surface* surface) const {
	if(surface->w != bitmap->w || surface->h != bitmap->h || surface->format->BytesPerPixel != bitmap->format->BytesPerPixel) {
		return false;
	}
	
	return memcmp(surface->pixels, surface->pixels, surface->h * surface->w * surface->format->BytesPerPixel) == 0;
}

const std::string Bitmap::BITMAP_DIRECTORY = IO::getDirectory(boost::assign::list_of("data")("bitmaps"));