#include "color.hpp"

#include <misc/exceptions.hpp>

Color::Color(const boost::uuids::uuid id, const std::map<const boost::uuids::uuid, const SDL_Color>& sdlColorMap):
        UUID<Color>(id),
		sdlColorMap(sdlColorMap),
        ucol(),
		scol(),
		sig(),
		themeId()
{ }

Color::Color(const std::map<const boost::uuids::uuid, const SDL_Color>& sdlColorMap):
        UUID<Color>(),
		sdlColorMap(sdlColorMap),
        ucol(),
		scol(),
		sig(),
		themeId()
{ }
		
void Color::updateTheme(const SDL_PixelFormat* pixelFormat, const boost::uuids::uuid themeId) const {
	if(this->themeId == themeId) {
		return;
	}
	this->themeId = themeId;
	this->pixelFormat = pixelFormat;

	const std::map<const boost::uuids::uuid, const SDL_Color>::const_iterator i = sdlColorMap.find(themeId);
	
	BOOST_ASSERT(i != sdlColorMap.end());

	scol = i->second;
	ucol = SDL_MapRGBA(pixelFormat, scol.r, scol.g, scol.b, scol.unused);	
	sig(ucol);
}

boost::signals::connection Color::connect(boost::signal<void (Uint32)>::slot_function_type subscriber) const {
	BOOST_ASSERT(sdlColorMap.size() > 0);

	return sig.connect(subscriber);
}


const Uint32 Color::mixColor(const Color& other)  const
{
	Uint8 r = static_cast<Uint8>((this->r() + other.r())/2);
	Uint8 g = static_cast<Uint8>((this->g() + other.g())/2);
	Uint8 b = static_cast<Uint8>((this->b() + other.b())/2);
	Uint8 a = static_cast<Uint8>((this->a() + other.a())/2);

	return SDL_MapRGBA(pixelFormat, r, g, b, a);
}


const Uint32 Color::mixColor(const Color& other, const unsigned int gradient) const
{
	BOOST_ASSERT(gradient <= 100);

	Uint8 r = static_cast<Uint8>((this->r()*gradient + other.r() * (100 - gradient))/100);
	Uint8 g = static_cast<Uint8>((this->g()*gradient + other.g() * (100 - gradient))/100);
	Uint8 b = static_cast<Uint8>((this->b()*gradient + other.b() * (100 - gradient))/100);
	Uint8 a = static_cast<Uint8>((this->a()*gradient + other.a() * (100 - gradient))/100);

	return SDL_MapRGBA(pixelFormat, r, g, b, a);
}

const Uint32 Color::changeAbsoluteBrightness(const signed int brightness) const
{
	if(brightness == 0) {
		return *this;
	}
	BOOST_ASSERT(brightness < 256);

	int r = this->r() + brightness;
	int g = this->g() + brightness;
	int b = this->b() + brightness;
	if(r > 255) { r = 255;}
	if(g > 255) { g = 255;}
	if(b > 255) { b = 255;}
	if(r < 0) { r = 0;}
	if(g < 0) { g = 0;}
	if(g < 0) { b = 0;}

	return SDL_MapRGBA(pixelFormat, static_cast<Uint8>(r), static_cast<Uint8>(g), static_cast<Uint8>(b), this->a());
}

const Uint32 Color::changeRelativeBrightness(const unsigned int brightness_percent) const
{
	if(brightness_percent == 100) {
		return *this;
	}
	int r = this->r() * brightness_percent / 100; if(r>255) r = 255;
	int g = this->g() * brightness_percent / 100; if(g>255) g = 255;
	int b = this->b() * brightness_percent / 100; if(b>255) b = 255;
	return SDL_MapRGBA(pixelFormat, static_cast<Uint8>(r), static_cast<Uint8>(g), static_cast<Uint8>(b), this->a());
}

const SDL_Color Color::toSDL_Color(const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a) {
	SDL_Color scol;
	scol.r = r;
	scol.g = g;
	scol.b = b;
	scol.unused = a;
	return scol;
}

const SDL_Color Color::toSDL_Color(const SDL_PixelFormat* pixelFormat, const Uint32 int_color) {   
	Uint8 r;
	Uint8 g;
	Uint8 b;
	Uint8 a;
	SDL_GetRGBA(int_color, pixelFormat, &r, &g, &b, &a);
	return toSDL_Color(r, g, b, a);
}