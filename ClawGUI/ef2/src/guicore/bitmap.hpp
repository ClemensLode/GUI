#ifndef _GUICORE_BITMAP_HPP
#define _GUICORE_BITMAP_HPP

#pragma warning(push, 0)  
#include <SDL.h>
#include <SDL_image.h>
#pragma warning(pop)

#include <misc/uuid.hpp>
#include <string>
#include <geometry/size.hpp>
#include <geometry/objectsize.hpp>


// object size is used for scaling the bitmap if needed.

class Bitmap : public UUID<Bitmap>
{
public:

	Bitmap(const boost::uuids::uuid id, const std::string& fileName, const boost::shared_ptr<const ObjectSize> objectSize, const bool transparent);
	Bitmap(const std::string& fileName, const boost::shared_ptr<const ObjectSize> objectSize, const bool transparent);
	~Bitmap();

	operator SDL_Surface*() const;
	SDL_Surface* operator->() const;

	bool equals(SDL_Surface* surface) const;

	const std::string& getFileName() const;
	const boost::shared_ptr<const ObjectSize>& getObjectSize() const;
	bool isTransparent() const;
	Size getSize() const;

private:

	const std::string fileName;
	const boost::shared_ptr<const ObjectSize> objectSize;
	const bool transparent;

	SDL_Surface *const bitmap;

	/*		bool scale;
	bool used;
	bool solid;*/

	static const std::string BITMAP_DIRECTORY;
};

inline Size Bitmap::getSize() const {
	return Size(static_cast<Uint16>(bitmap->w), static_cast<Uint16>(bitmap->h)); 
}

inline const std::string& Bitmap::getFileName() const {
	return fileName;
}

inline const boost::shared_ptr<const ObjectSize>& Bitmap::getObjectSize() const {
	return objectSize;
}

inline Bitmap::operator SDL_Surface*() const { 
	return bitmap;
}

inline SDL_Surface* Bitmap::operator->() const {
	return bitmap;
}

inline bool Bitmap::isTransparent() const {
	return transparent;
}

#endif // _GUICORE_BITMAP_HPP