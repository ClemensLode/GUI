#include "cursor.hpp"

#include <misc/exceptions.hpp>
#include <misc/miscellaneous.hpp>
#include "surface.hpp"
#include <SDL.h>
#include <misc/exceptions.hpp>
#include <sstream>


Cursor::Cursor(const boost::shared_ptr<const Bitmap> bitmap):
	bitmap(bitmap),
	cursor(createCursor(static_cast<SDL_Surface*>(*bitmap)))
{ }

Cursor::Cursor(const boost::uuids::uuid id, const boost::shared_ptr<const Bitmap> bitmap):
UUID<Cursor>(id),
	bitmap(bitmap),
	cursor(createCursor(static_cast<SDL_Surface*>(*bitmap)))
{ }

Cursor::~Cursor() {
	if(cursor) {
		SDL_FreeCursor(cursor);
	}
}

SDL_PixelFormat& Cursor::get_neutral_pixel_format()
{
	static bool first_time = true;
	static SDL_PixelFormat format;

	if(first_time) {
		first_time = false;
		SDL_Surface* surf(SDL_CreateRGBSurface(SDL_SWSURFACE, 1, 1, 32, 0xFF0000, 0xFF00,0xFF, 0xFF000000));
		format = *surf->format;
		format.palette = NULL;
	}

	return format;
}

SDL_Cursor* Cursor::createCursor(SDL_Surface* surface) {

	if(!SDL_WasInit(SDL_INIT_VIDEO)) {
		throw SDLException("ERROR (Cursor::createCursor()): SDL system was not yet initialized, cannot create cursor.");
	}
	
	// The width must be a multiple of 8 (SDL requirement)
	SDL_Surface* const result = SDL_ConvertSurface(surface, &get_neutral_pixel_format(), SDL_SWSURFACE);
	if(result != NULL) {
		SDL_SetAlpha(result, SDL_SRCALPHA, SDL_ALPHA_OPAQUE);
	}

	size_t cursor_width = surface->w;
	size_t cursor_height = surface->h;
	if((cursor_width % 8) != 0) {
		cursor_width -= (cursor_width % 8);
	}

	std::vector<Uint8> data((cursor_width * surface->h) / 8, 0);
	std::vector<Uint8> mask(data.size(), 0);

	Surface::Lock(result);

	const Uint32* const pixels = static_cast<Uint32*>(surface->pixels);
	for(int y = 0; y != surface->h; ++y) {
		for(int x = 0; x != surface->w; ++x) {

			if (static_cast<size_t>(x) < cursor_width) {
				Uint8 r, g, b, a;
				SDL_GetRGBA(pixels[y*surface->w + x], surface->format, &r, &g, &b, &a);

				const size_t index = y * cursor_width + x;
				const size_t shift = 7 - (index % 8);

				const Uint8 trans = static_cast<Uint8>((a < 128 ? 0 : 1) << shift);
				const Uint8 black = static_cast<Uint8>((trans == 0 || (r + g + b) / 3 > 128 ? 0 : 1) << shift);

				data[index/8] |= black;
				mask[index/8] |= trans;
			}
		}
	}

	SDL_Cursor* cursor = SDL_CreateCursor(&data[0], &mask[0], cursor_width, cursor_height, 0, 0);

	if(!cursor) {
		std::ostringstream os;
		os << "ERROR (Cursor::Cursor()): Could not load cursor file (" << SDL_GetError() << ").";
		throw SDLException(os.str());
	}

	return cursor;
}



