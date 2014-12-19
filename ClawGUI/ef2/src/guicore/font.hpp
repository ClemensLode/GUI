#ifndef _GUICORE_FONT_HPP
#define _GUICORE_FONT_HPP

#pragma warning(push, 0)  
#include <SDL.h>
#include <SDL_ttf.h>
#pragma warning(pop)

#include <misc/uuid.hpp>

#include <geometry/size.hpp>

class Font : public UUID<Font>
{
public:
	Font(const boost::uuids::uuid id, const std::string& fileName, const Uint16 size, const bool underlined = false, const bool shadow = false);
	Font(const std::string& fileName, const Uint16 size, const bool underlined = false, const bool shadow = false);
	~Font();

	operator const TTF_Font*();

	const Size getTextExtent(const std::string& font_text) const; 
	void DrawText(SDL_Surface* surface, const SDL_Color& color, const std::string& text, const Sint16 x, const Sint16 y) const;
	void DrawText(SDL_Surface* surface, const SDL_Color& color, const SDL_Color& back_color, const std::string& font_text, const Sint16 x, const Sint16 y) const;

	bool isUnderlined() const;
	bool isShadow() const;
	Uint16 getSize() const;
	const std::string& getFileName() const;

	static void initTTF();

private:
		
	const std::string fileName;
	const Uint16 size;
	const bool underlined;
	const bool shadow;

	TTF_Font *const font;

	Font& operator=(const Font& object);
	Font(const Font& object);

	static const std::string FONT_DIRECTORY;
};

inline const std::string& Font::getFileName() const {
	return fileName;
}

inline Font::operator const TTF_Font*() {
	return font;
}

inline bool Font::isUnderlined() const {
	return underlined;
}

inline bool Font::isShadow() const {
	return shadow;
}

inline Uint16 Font::getSize() const {
	return size;
}

#endif // _GUICORE_FONT_HPP
