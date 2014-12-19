#include "font.hpp"

#include <geometry/point.hpp>

#include <misc/exceptions.hpp>
#include <misc/io.hpp>

#pragma warning(push, 0)
#include <SDL_ttf.h>
#include <SDL.h>
#include <boost/assert.hpp>
#pragma warning(pop)


Font::Font(const std::string& fileName, const Uint16 size, const bool underlined, const bool shadow):
	fileName(fileName),
	size(size),
	underlined(underlined),
	shadow(shadow),
	font(TTF_OpenFont((FONT_DIRECTORY + fileName).c_str(), size))
{
	if(font == NULL) {
		throw SDLException("ERROR (Font::setFont()): Could not initialize font " + (FONT_DIRECTORY + fileName) + " [TTF ERROR: \"" + std::string(TTF_GetError()) + "\"].");
	}
}

Font::Font(const boost::uuids::uuid id, const std::string& fileName, const Uint16 size, const bool underlined, const bool shadow):
	UUID<Font>(id),
	fileName(fileName),
	size(size),
	underlined(underlined),
	shadow(shadow),
	font(TTF_OpenFont((FONT_DIRECTORY + fileName).c_str(), size))
{
	if(font == NULL) {
		throw SDLException("ERROR (Font::setFont()): Could not initialize font " + (FONT_DIRECTORY + fileName) + " [TTF ERROR: \"" + std::string(TTF_GetError()) + "\"].");
	}
}

Font::~Font()
{
//	TTF_CloseFont(font);
}

const Size Font::getTextExtent(const std::string& font_text) const
{
	int width;
	int height;
	int result = TTF_SizeUTF8(font, font_text.c_str(), &width, &height);

	if(result != 0) {
		return Size(10, 10);
		//throw SDLException("ERROR (Font::getTextExtent()): Could not determine text dimensions with font [TTF ERROR: \"" + std::string(TTF_GetError()) + "\"].");
	}

	if(height < 2) {
		height = 0;
	} else {
		height -= 2;
	}

	return Size(static_cast<Uint16>(width), static_cast<Uint16>(height));
}


void Font::DrawText(SDL_Surface* surface, const SDL_Color& color, const std::string& font_text, const Sint16 x, const Sint16 y) const
{
	BOOST_ASSERT(surface);
	SDL_Surface *sText = TTF_RenderUTF8_Blended( font, font_text.c_str(), color);
	BOOST_ASSERT(sText != NULL);

	if(sText) {
		SDL_Rect rcDest = {x, static_cast<Sint16>(y-4), 0, 0};
		SDL_BlitSurface( sText, NULL, surface, &rcDest );
		// TODO Reuse?
		SDL_FreeSurface( sText );
	}
}

void Font::DrawText(SDL_Surface* surface, const SDL_Color& color, const SDL_Color& back_color, const std::string& font_text, const Sint16 x, const Sint16 y) const // TODO
{
	BOOST_ASSERT(surface);
	BOOST_ASSERT(Point(x, y) == Point(x, y));
	SDL_Surface *sText = TTF_RenderUTF8_Shaded( font, font_text.c_str(), color, back_color);
	BOOST_ASSERT(sText);

	SDL_Rect rcDest = {x, static_cast<Sint16>(y-4), 0, 0};
	SDL_BlitSurface( sText, NULL, surface, &rcDest );
	SDL_FreeSurface( sText );
}

void Font::initTTF() {
	if(!TTF_WasInit()) {
		if(TTF_Init()==-1) {
			std::ostringstream os;
			os << "Error initializing TTF subsystem [\"" << TTF_GetError() << "\"]";
			throw SDLException(os.str());
		}
		atexit(TTF_Quit);
	}
}

const std::string Font::FONT_DIRECTORY = IO::getDirectory(boost::assign::list_of("data")("fonts"));