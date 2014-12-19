#ifndef _GUICORE_COLOR_HPP
#define _GUICORE_COLOR_HPP

#pragma warning(push, 0)  
#include <SDL.h>

#include <boost/signals.hpp>
#pragma warning(pop)

#include <misc/uuid.hpp>


class Color : public UUID<Color>
{
public:
	Color(const SDL_PixelFormat* pixelFormat, const SDL_Color color);
	Color(const SDL_PixelFormat* pixelFormat, const Uint8 red, const Uint8 green, const Uint8 blue, const Uint8 alpha = 255);
	
	Color(const std::map<const boost::uuids::uuid, const SDL_Color>& sdlColorMap);
	Color(const boost::uuids::uuid id, const std::map<const boost::uuids::uuid, const SDL_Color>& sdlColorMap);
	~Color() { }

	operator SDL_Color() const;
	operator Uint32() const;

	void updateTheme(const SDL_PixelFormat* pixelFormat, const boost::uuids::uuid themeId) const;
	// use public boost::signals::trackable on the object wanting to connect to test
	// .connect(boost::bind(&CLASS::function, this));
	boost::signals::connection connect(boost::signal<void (Uint32)>::slot_function_type subscriber) const;
	const std::map<const boost::uuids::uuid, const SDL_Color>& getColorMap() const;

	Uint8 r() const;
	Uint8 g() const;
	Uint8 b() const;
	Uint8 a() const;

	const Uint32 mixColor(const Color& other) const;
	const Uint32 mixColor(const Color& other, const unsigned int gradient) const;
	const Uint32 changeAbsoluteBrightness(const signed int brightness) const;
	const Uint32 changeRelativeBrightness(const unsigned int brightness_percent) const;

	static const SDL_Color toSDL_Color(const Uint8 r = 0, const Uint8 g = 0, const Uint8 b = 0, const Uint8 a = 255);
	static const SDL_Color toSDL_Color(const SDL_PixelFormat* pixelFormat, const Uint32 int_color);

private:	
	const std::map<const boost::uuids::uuid, const SDL_Color> sdlColorMap; // themeId -> SDL_Color

	mutable Uint32 ucol;
	mutable const SDL_PixelFormat* pixelFormat;
	mutable SDL_Color scol;

	mutable boost::signal<void (Uint32)> sig;
	mutable boost::uuids::uuid themeId;

	Color& operator=(const Color& object);
	Color(const Color& object);
};

// temporary constructors!
inline Color::Color(const SDL_PixelFormat* pixelFormat, const Uint8 red, const Uint8 green, const Uint8 blue, const Uint8 alpha):
        ucol(SDL_MapRGBA(pixelFormat, red, green, blue, alpha)),
        scol(toSDL_Color(red, green, blue, alpha))
{ }


inline Color::Color(const SDL_PixelFormat* pixelFormat, const SDL_Color scolor):
	ucol(SDL_MapRGBA(pixelFormat, scolor.r, scolor.g, scolor.b, scolor.unused)),
       scol(scolor)
{ }

inline const std::map<const boost::uuids::uuid, const SDL_Color>& Color::getColorMap() const {
	return sdlColorMap;
}

inline Color::operator SDL_Color() const {
	return scol;
}

inline Color::operator Uint32() const {
	return ucol;
}

inline Uint8 Color::r() const {
	return scol.r;
}

inline Uint8 Color::g() const {
	return scol.g;
}

inline Uint8 Color::b() const {
	return scol.b;
}

inline Uint8 Color::a() const {
	return scol.unused;
}



#endif // _GUICORE_COLOR_HPP
