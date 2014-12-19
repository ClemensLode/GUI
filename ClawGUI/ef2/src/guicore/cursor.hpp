#ifndef _GUICORE_CURSOR_HPP
#define _GUICORE_CURSOR_HPP

#pragma warning(push, 0)  
#include <SDL.h>
#pragma warning(pop)

#include <misc/uuid.hpp>
#include "bitmap.hpp"

class Cursor : public UUID<Cursor>
{
public:
	Cursor(const boost::uuids::uuid id, const boost::shared_ptr<const Bitmap> bitmap);
	Cursor(const boost::shared_ptr<const Bitmap> bitmap);
	~Cursor();
	
	operator SDL_Cursor*() const;
	const boost::shared_ptr<const Bitmap>& getBitmap() const;

private:
	// call not before SDL was initialized!
	static SDL_Cursor* createCursor(SDL_Surface* surface);
	static SDL_PixelFormat& get_neutral_pixel_format();
	const boost::shared_ptr<const Bitmap> bitmap;
	SDL_Cursor* cursor;
};

inline const boost::shared_ptr<const Bitmap>& Cursor::getBitmap() const {
	return bitmap;
}

inline Cursor::operator SDL_Cursor*() const {
	return cursor;
}

#endif // _GUICORE_CURSOR_HPP