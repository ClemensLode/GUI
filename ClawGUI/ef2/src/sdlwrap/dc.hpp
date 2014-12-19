#ifndef _SDL_DC_HPP
#define _SDL_DC_HPP

#include <sstream>

#define PRESSED_BRIGHTEN 50
#define PRESSED_DARKEN 130
#define PRESSED_NORMAL 90
#define NOT_PRESSED_DARKEN 60
#define NOT_PRESSED_BRIGHTEN 140

#define DC_MAX_CHANGED_RECTANGLES 200

#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include <geometry/rect.hpp>

#include <guicore/pen.hpp>
#include <guicore/brush.hpp>
#include <guicore/enums/brushstyle.hpp>
#include <guicore/font.hpp>

#include "enums/bitdepth.hpp"

#include <guicore/surface.hpp>
#include <misc/exceptions.hpp>

#include <SDL_image.h>

#include <vector>

#pragma warning(push, 0)
#include <boost/shared_ptr.hpp>
#include <boost/assert.hpp>
#pragma warning(pop)

typedef struct tColorRGBA {
	Uint8 r;
	Uint8 g;
	Uint8 b;
	Uint8 a;
} tColorRGBA;

typedef struct tColorY {
	Uint8 y;
} tColorY;




class DC
{
public:
	DC(const Uint32 initflags);
	~DC();

	static const char* getVersion();

	operator SDL_Surface*() const;
	SDL_Surface* operator->() const;
	SDL_Surface* getSurface() const;

	bool isSurfaceBuffered() const;

	const Size getSize() const;
	Uint16 w() const;
	Uint16 h() const;

	bool valid() const;
	Uint32 flags() const;

	bool setResolution(const Size current_resolution);
	bool setBitDepth(const eBitDepth bit_depth);
	bool setScreen(const Size current_resolution, const eBitDepth bit_depth, const Uint32 nflags);

	eBitDepth getBitDepth() const;
	Uint8 getBits() const;

	Uint16 pitch() const;
	void *pixels();
	void const* pixels() const;
	const struct private_hwdata *hwdata() const;

	bool Lock() const { return Surface::Lock(surface); }
	void Unlock() const { Surface::Unlock(surface); }

	bool setColorKey(const Uint32 flag, const Color key) const;
	bool setAlpha(const Uint32 flag, const Uint8 alpha) const;
	void updateScreen();

	void Blit(SDL_Surface* src, SDL_Rect& dstrect) const;

	void clearScreen();

	void saveBMP(const std::string& fileName) const;
	SDL_Surface* loadBMP(const std::string& fileName) const;

	bool setFullScreen(const bool fullscreen = true);
	bool isFullScreen() const;


	void setBrush(const boost::shared_ptr<const Brush>& brush);
	void setDarkBrush(const boost::shared_ptr<const Brush>& darkBrush);
	void setPen(const boost::shared_ptr<const Pen>& pen);
	void setDarkPen(const boost::shared_ptr<const Pen>& darkPen);
	void setPressedPen(const boost::shared_ptr<const Pen>& pressedPen);
	void setDarkPressedPen(const boost::shared_ptr<const Pen>& darkPressedPen);
	void setTextColor(const boost::shared_ptr<const Color>& textColor);

	void setEndBrush(const boost::shared_ptr<const Brush>& endBrush);
	void setEndDarkBrush(const boost::shared_ptr<const Brush>& endDarkBrush);
	void setEndPen(const boost::shared_ptr<const Pen>& endPen);
	void setEndDarkPen(const boost::shared_ptr<const Pen>& endDarkPen);
	void setEndPressedPen(const boost::shared_ptr<const Pen>& endPressedPen);
	void setEndDarkPressedPen(const boost::shared_ptr<const Pen>& endDarkPressedPen);
	void setEndTextColor(const boost::shared_ptr<const Color>& endTextColor);

	void setFont(const boost::shared_ptr<const Font>& font);

	Uint32 getBrushColor() const;
	Uint32 getDarkBrushColor() const;
	Uint32 getPenColor() const;
	Uint32 getDarkPenColor() const;
	Uint32 getPressedPenColor() const;
	Uint32 getDarkPressedPenColor() const;
	Uint32 getTextColor() const;

	const Size getTextExtent(const std::string& text) const;

	void DrawText(const std::string& text, const Point& p) const;			
	void DrawBitmap(const SDL_Surface* bitmap, const Point& p) const;		
	void DrawBitmap(const SDL_Surface* bitmap, const Point& p, const Rect& clip_rect) const;
	void DrawEmptyRectangle(const Rect& rect) const;
	void DrawEmptyRectangle(const Point& p, const Size& s) const;		
	void DrawRectangle(const Rect& rect) const; 
	void DrawRectangle(const Point& p, const Size& s) const;
	void DrawTabRectangle(const Rect& rect) const; 
	void DrawTabRectangle(const Point& p, const Size& s) const;
	void DrawSpline(const unsigned int c, const Point* p) const;
	void DrawSpline(const unsigned int c, const Point* p, const Point s) const;
	void DrawLine(const Point& p1, const Point& p2) const;		
	void DrawVerticalLine(const Point& p, const Uint16 height) const;
	void DrawHorizontalLine(const Point& p, const Uint16 width) const;		
	void DrawRoundedRectangle(const Point& p, const Size& s, const Uint16 radius) const;
	void DrawRoundedRectangle(const Rect& rect, const Uint16 radius) const;
	void DrawEdgedRoundedRectangle(const Point& p, const Size& s, const Uint16 radius) const;
	void DrawEdgedRoundedRectangle(const Rect& rect, const Uint16 radius) const;

	void setPressedRectangle(const bool pressed = true);

	void addRectangle(const Rect& rect);

	void switchToSurface(SDL_Surface* temp_surface);
	void switchToOriginalSurface();

	void drawFromPoint(const Point& p);
	Sint16 getMaxX() const;
	Sint16 getMaxY() const;

	void setBrightness(const signed int brightness);
	void resetBrightness();

	void setGradient(const unsigned int gradient);
	void resetGradient();

	unsigned int getScreenDataSize() const;

	const std::string printHardwareInformation();
	const std::string printSurfaceInformation();

	static const Sint16 ZERO_SINT16;
	static const Sint16 ZERO_UINT16;


private:


	static const char* dcVersion;



	Sint16 cutTop(const Sint16 y) const { if(y < ZERO_SINT16) return ZERO_SINT16; else return y; }
	Sint16 cutLeft(const Sint16 x) const { if(x < ZERO_SINT16) return ZERO_SINT16; else return x; }
	Sint16 cutRight(const Sint16 x) const { if(x > max_x) return max_x; else return x; }
	Sint16 cutBottom(const Sint16 y) const { if(y > max_y) return max_y; else return y; }
	Uint16 cutWidth(const Sint16 x, const Uint16 width) const { if(x + static_cast<Sint16>(width) > static_cast<Sint16>(max_width)) { return static_cast<Uint16>(static_cast<Sint16>(max_width) - x); } else return width; }
	Uint16 cutHeight(const Sint16 y, const Uint16 height) const { if(y + static_cast<Sint16>(height) > static_cast<Sint16>(max_height)) { return static_cast<Uint16>(static_cast<Sint16>(max_height) - y); } else return height; }
	bool isRectOutside(const Rect rect) const { return (rect.getLeft() > max_x) || (rect.getTop() > max_y) || (rect.getRight() < ZERO_SINT16) || (rect.getBottom() < ZERO_SINT16); }


	SDL_Surface* surface;
	SDL_Surface* oldSurface;

	void setSurface(SDL_Surface* sdl_surface);

	Size resolution;
	eBitDepth bitDepth;
	Uint8 bits;

	boost::shared_ptr<const Brush> brush;
	boost::shared_ptr<const Brush> darkBrush;
	boost::shared_ptr<const Pen> pen;
	boost::shared_ptr<const Pen> darkPen;
	boost::shared_ptr<const Pen> pressedPen;
	boost::shared_ptr<const Pen> darkPressedPen;
	boost::shared_ptr<const Color> textColor;

	boost::shared_ptr<const Brush> endBrush;
	boost::shared_ptr<const Brush> endDarkBrush;
	boost::shared_ptr<const Pen> endPen;
	boost::shared_ptr<const Pen> endDarkPen;
	boost::shared_ptr<const Pen> endPressedPen;
	boost::shared_ptr<const Pen> endDarkPressedPen;
	boost::shared_ptr<const Color> endTextColor;

	boost::shared_ptr<const Font> font;

	signed int brightness;
	unsigned int gradient;

	Point dp;
	bool pressedRectangle;
	
	void (DC::*Draw_HLine)(const Sint16 x0, const Sint16 y0, const Sint16 x1) const;
	void Draw_HLine_8bit(const Sint16 x0, const Sint16 y0, const Sint16 x1) const;
	void Draw_HLine_16bit(const Sint16 x0, const Sint16 y0, const Sint16 x1) const;
	void Draw_HLine_24bit(const Sint16 x0, const Sint16 y0, const Sint16 x1) const;
	void Draw_HLine_32bit(const Sint16 x0, const Sint16 y0, const Sint16 x1) const;


	void (DC::*Draw_VLine)(const Sint16 x0, const Sint16 y0, const Sint16 y1) const;
	void Draw_VLine_8bit(const Sint16 x0, const Sint16 y0, const Sint16 y1) const;
	void Draw_VLine_16bit(const Sint16 x0, const Sint16 y0, const Sint16 y1) const;
	void Draw_VLine_24bit(const Sint16 x0, const Sint16 y0, const Sint16 y1) const;
	void Draw_VLine_32bit(const Sint16 x0, const Sint16 y0, const Sint16 y1) const;


	void callDrawLine(const Sint16 x0, const Sint16 y0, const Sint16 x1, const Sint16 y1) const;
	void (DC::*Draw_Line)(const Sint16 x0, const Sint16 y0, const Sint16& dx, const Sint16& dy, const Sint16& pixx, const Sint16& pixy) const;
	void Draw_Line_8bit(const Sint16 x0, const Sint16 y0, const Sint16& dx, const Sint16& dy, const Sint16& pixx, const Sint16& pixy) const;
	void Draw_Line_16bit(const Sint16 x0, const Sint16 y0, const Sint16& dx, const Sint16& dy, const Sint16& pixx, const Sint16& pixy) const;
	void Draw_Line_24bit(const Sint16 x0, const Sint16 y0, const Sint16& dx, const Sint16& dy, const Sint16& pixx, const Sint16& pixy) const;
	void Draw_Line_32bit(const Sint16 x0, const Sint16 y0, const Sint16& dx, const Sint16& dy, const Sint16& pixx, const Sint16& pixy) const;

	void (DC::*DrawRound)(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height, const Uint16 corner) const;
	void DrawRound_8bit(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height, const Uint16 corner) const;
	void DrawRound_16bit(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height, const Uint16 corner) const;
	void DrawRound_24bit(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height, const Uint16 corner) const;
	void DrawRound_32bit(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height, const Uint16 corner) const;

	void (DC::*DrawEdgedRound)(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height, const Uint16 corner) const;
	void DrawEdgedRound_8bit(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height, const Uint16 corner) const;
	void DrawEdgedRound_16bit(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height, const Uint16 corner) const;
	void DrawEdgedRound_24bit(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height, const Uint16 corner) const;
	void DrawEdgedRound_32bit(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height, const Uint16 corner) const;


	void (DC::*DrawTab)(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height) const;
	void DrawTab_8bit(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height) const;
	void DrawTab_16bit(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height) const;
	void DrawTab_24bit(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height) const;
	void DrawTab_32bit(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height) const;

	
	void DrawText(const std::string& text, const Sint16 x, const Sint16 y) const;
	void DrawBitmap(const SDL_Surface* bitmap, const Sint16 x, const Sint16 y) const;
	void DrawBitmap(const SDL_Surface* bitmap, const Sint16 x, const Sint16 y, const Rect& clip_rect) const;
	void DrawEmptyRectangle(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height) const;
	void DrawRectangle(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height) const;
	void DrawTabRectangle(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height) const;
	void DrawLine(const Sint16 x0, const Sint16 y0, const Sint16 x1, const Sint16 y1) const;
	void DrawVerticalLine(const Sint16 x0, const Sint16 y0, const Sint16 y1) const;
	void DrawHorizontalLine(const Sint16 x0, const Sint16 y0, const Sint16 x1) const;
	void DrawRoundedRectangle(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height, const Uint16 radius) const;
	void DrawEdgedRoundedRectangle(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height, const Uint16 radius) const;

	std::list<Rect> changedRectangles;
	Sint16 max_x;
	Sint16 max_y;
	Uint16 max_width;
	Uint16 max_height;
	
	SDL_Cursor* initAndGetDefaultCursor(Uint32 initflags);
	SDL_Cursor* defaultCursor;

	DC(const DC& other);
	DC &operator=(const DC& other);
};

inline void DC::setSurface(SDL_Surface* sdl_surface) {
	if(surface) {
		SDL_FreeSurface(surface);
	}
	surface = sdl_surface;
}

inline unsigned int DC::getScreenDataSize() const {
	BOOST_ASSERT(surface);
	return surface->w * surface->h * surface->format->BitsPerPixel;
}

inline SDL_Surface* DC::loadBMP(const std::string& fileName) const {
	return IMG_Load(fileName.c_str());
}

inline void DC::setGradient(const unsigned int gradient) {
	this->gradient = gradient;
}

inline void DC::setBrightness(const signed int brightness) {
	this->brightness = brightness;
}

inline void DC::resetBrightness() {
	this->brightness = 100;
}

inline bool DC::isFullScreen() const {
	BOOST_ASSERT(surface);
	return ((surface->flags) & SDL_FULLSCREEN) == SDL_FULLSCREEN;
}


inline const char* DC::getVersion() {
	return dcVersion;
}

inline void DC::drawFromPoint(const Point& p) {
	dp = p;
}

inline void DC::setPressedRectangle(const bool pressed) {
	pressedRectangle = pressed;
}

inline DC& DC::operator=(const DC& other) {
	//if(*this != other) {
	setSurface(other.surface);
	//}
	return *this;
}

inline DC::operator SDL_Surface*() const { 
	return surface;
}

inline SDL_Surface* DC::operator->() const {
	return surface;
}

inline SDL_Surface* DC::getSurface() const {
	return surface;
}

inline bool DC::valid() const {
	return surface != NULL;
}

inline Uint32 DC::flags() const {
	BOOST_ASSERT(surface);
	return surface->flags;
}

inline const Size DC::getSize() const {
	return Size(w(), h());
}

inline Uint16 DC::w() const {
	BOOST_ASSERT(surface);
	return static_cast<Uint16>(surface->w);
}

inline Uint16 DC::h() const {
	BOOST_ASSERT(surface);
	return static_cast<Uint16>(surface->h);
}

inline Uint16 DC::pitch() const {
	BOOST_ASSERT(surface);
	return surface->pitch;
}

inline void* DC::pixels() { 
	BOOST_ASSERT(surface);
	return surface->pixels; 
}

inline const void* DC::pixels() const {
	BOOST_ASSERT(surface);
	return surface->pixels;
}

inline const struct private_hwdata* DC::hwdata() const {
	BOOST_ASSERT(surface);
	return surface->hwdata;
}

inline void DC::saveBMP(const std::string& fileName) const {
	BOOST_ASSERT(fileName.size() > 0);
	if(SDL_SaveBMP(surface, fileName.c_str())) {
		throw SDLException("ERROR (DC::saveBMP()): Could not save surface to bitmap " + fileName + " (" + std::string(SDL_GetError()) + ").");
	}

}

inline void DC::DrawLine(const Point& p1, const Point& p2) const {
	Point tp1 = dp + p1;
	Point tp2 = dp + p2;
	DrawLine(tp1.getX(), tp1.getY(), tp2.getX(), tp2.getY());
}

inline void DC::DrawText(const std::string& text, const Point& p) const {
	if(text.empty()) {
		return;
	}
	Point tp = dp + p;
	DrawText(text, tp.getX(), tp.getY());
}

inline void DC::DrawRoundedRectangle(const Point& p, const Size& s, const Uint16 radius) const {
	Point tp = dp + p;
	DrawRoundedRectangle(tp.getX(), tp.getY(), s.getWidth(), s.getHeight(), radius);
}

inline void DC::DrawRoundedRectangle(const Rect& rect, const Uint16 radius) const {
	Point tp = dp + rect.getTopLeft();
	DrawRoundedRectangle(tp.getX(), tp.getY(), rect.getWidth(), rect.getHeight(), radius);
}

inline void DC::DrawEdgedRoundedRectangle(const Point& p, const Size& s, const Uint16 radius) const {
	Point tp = dp + p;
	DrawEdgedRoundedRectangle(tp.getX(), tp.getY(), s.getWidth(), s.getHeight(), radius);
}

inline void DC::DrawEdgedRoundedRectangle(const Rect& rect, const Uint16 radius) const {
	Point tp = dp + rect.getTopLeft();
	DrawEdgedRoundedRectangle(tp.getX(), tp.getY(), rect.getWidth(), rect.getHeight(), radius);
}

inline void DC::setTextColor(const boost::shared_ptr<const Color>& textColor) {
	this->textColor = textColor;
}

// evtl sowohl gradient als auch gradient TODO
inline Uint32 DC::getBrushColor() const {
	if(gradient != 0) {
		return brush->getColor()->mixColor(*endBrush->getColor(), gradient); // TODO brightness?
	} else {
		return brush->getColor()->changeRelativeBrightness(brightness);
	}
}

inline Uint32 DC::getDarkBrushColor() const{
	if(gradient != 0) {
		return darkBrush->getColor()->mixColor(*endDarkBrush->getColor(), gradient); // TODO brightness?
	} else {	
		return darkBrush->getColor()->changeRelativeBrightness(brightness);
	}
}

inline Uint32 DC::getPenColor() const{
	if(gradient != 0) {
		return pen->getColor()->mixColor(*endPen->getColor(), gradient); // TODO brightness?
	} else {	
		return pen->getColor()->changeRelativeBrightness(brightness);
	}
}

inline Uint32 DC::getDarkPenColor() const{
	if(gradient != 0) {
		return darkPen->getColor()->mixColor(*endDarkPen->getColor(), gradient); // TODO brightness?
	} else {	
		return darkPen->getColor()->changeRelativeBrightness(brightness);
	}
}


inline Uint32 DC::getPressedPenColor() const{
	if(gradient != 0) {
		return pressedPen->getColor()->mixColor(*endPressedPen->getColor(), gradient); // TODO brightness?
	} else {	
		return pressedPen->getColor()->changeRelativeBrightness(brightness);
	}
}

inline Uint32 DC::getDarkPressedPenColor() const{
	if(gradient != 0) {
		return darkPressedPen->getColor()->mixColor(*endDarkPressedPen->getColor(), gradient); // TODO brightness?
	} else {	
		return darkPressedPen->getColor()->changeRelativeBrightness(brightness);
	}
}

inline Uint32 DC::getTextColor() const{
	if(gradient != 0) {
		return textColor->mixColor(*endTextColor, gradient); // TODO brightness?
	} else if(brightness != 0) {
		return textColor->changeRelativeBrightness(brightness);
	}
}


inline void DC::setBrush(const boost::shared_ptr<const Brush>& brush) {
	this->brush = brush;
}

inline void DC::setDarkBrush(const boost::shared_ptr<const Brush>& darkBrush) {
	this->darkBrush = darkBrush;
}

inline void DC::setPen(const boost::shared_ptr<const Pen>& pen) {
	this->pen = pen;
}

inline void DC::setDarkPen(const boost::shared_ptr<const Pen>& darkPen) {
	this->darkPen = darkPen;
}

inline void DC::setPressedPen(const boost::shared_ptr<const Pen>& pressedPen) {
	this->pressedPen = pressedPen;
}

inline void DC::setDarkPressedPen(const boost::shared_ptr<const Pen>& darkPressedPen) {
	this->darkPressedPen = darkPressedPen;
}

inline void DC::setEndBrush(const boost::shared_ptr<const Brush>& endBrush) {
	this->endBrush = endBrush;
}

inline void DC::setEndDarkBrush(const boost::shared_ptr<const Brush>& endDarkBrush) {
	this->endDarkBrush = endDarkBrush;
}

inline void DC::setEndPen(const boost::shared_ptr<const Pen>& endPen) {
	this->endPen = endPen;
}

inline void DC::setEndDarkPen(const boost::shared_ptr<const Pen>& endDarkPen) {
	this->endDarkPen = endDarkPen;
}

inline void DC::setEndPressedPen(const boost::shared_ptr<const Pen>& endPressedPen) {
	this->endPressedPen = endPressedPen;
}

inline void DC::setEndDarkPressedPen(const boost::shared_ptr<const Pen>& endDarkPressedPen) {
	this->endDarkPressedPen = endDarkPressedPen;
}

inline void DC::setEndTextColor(const boost::shared_ptr<const Color>& endTextColor) {
	this->endTextColor = endTextColor;
}

inline bool DC::isSurfaceBuffered() const {
	return oldSurface != NULL;
}

inline void DC::DrawBitmap(const SDL_Surface* bitmap, const Point& p) const {
	Point tp = dp + p;
	DrawBitmap(bitmap, tp.getX(), tp.getY());
}

inline void DC::DrawBitmap(const SDL_Surface* bitmap, const Point& p, const Rect& clip_rect) const {
	Point tp = dp + p;
	DrawBitmap(bitmap, tp.getX(), tp.getY(), clip_rect);
}	

inline void DC::DrawEmptyRectangle(const Rect& rect) const	{
	Point tp = dp + rect.getTopLeft();
	DrawEmptyRectangle(tp.getX(), tp.getY(), rect.getWidth(), rect.getHeight());
}

inline void DC::DrawEmptyRectangle(const Point& p, const Size& s) const {
	Point tp = dp + p;
	DrawEmptyRectangle(tp.getX(), tp.getY(), s.getWidth(), s.getHeight());
}

inline void DC::DrawRectangle(const Rect& rect) const { 
	Point tp = dp + rect.getTopLeft();
	DrawRectangle(tp.getX(), tp.getY(), rect.getWidth(), rect.getHeight());
}

inline void DC::DrawRectangle(const Point& p, const Size& s) const { 
	Point tp = dp + p;
	DrawRectangle(tp.getX(), tp.getY(), s.getWidth(), s.getHeight());
}

inline void DC::DrawTabRectangle(const Rect& rect) const { 
	Point tp = dp + rect.getTopLeft();
	DrawTabRectangle(tp.getX(), tp.getY(), rect.getWidth(), rect.getHeight());
}

inline void DC::DrawTabRectangle(const Point& p, const Size& s) const { 
	Point tp = dp + p;
	DrawTabRectangle(tp.getX(), tp.getY(), s.getWidth(), s.getHeight());
}

inline bool DC::setColorKey(const Uint32 flag, const Color key) const {
	BOOST_ASSERT(surface);
	return SDL_SetColorKey(surface, flag, key) == 0;
}

inline bool DC::setAlpha(const Uint32 flag, const Uint8 alpha) const {
	BOOST_ASSERT(surface);
	return SDL_SetAlpha(surface, flag, alpha) == 0;
}

inline void DC::clearScreen() {
	BOOST_ASSERT(surface);
	SDL_Rect rc = Rect::createRect(0, 0, max_width, max_width);
	SDL_FillRect(surface, &rc, 1);
}

inline void DC::Blit(SDL_Surface* src, SDL_Rect& dstrect) const {
	BOOST_ASSERT(surface);
	SDL_BlitSurface(src, NULL, surface, &dstrect);
}

inline void DC::DrawVerticalLine(const Point& p, const Uint16 height) const {
	Point tp = dp + p;
	DrawVerticalLine(tp.getX(), tp.getY(), static_cast<Sint16>(tp.getY() + height));
}

inline void DC::DrawHorizontalLine(const Point& p, const Uint16 width) const {
	Point tp = dp + p;
	DrawHorizontalLine(tp.getX(), tp.getY(), static_cast<Sint16>(tp.getX() + width));
}

inline bool DC::setBitDepth(const eBitDepth bit_depth) {
	BOOST_ASSERT(surface);
	return setScreen(resolution, bit_depth, surface->flags);
}

inline bool DC::setResolution(const Size current_resolution) {
	BOOST_ASSERT(surface);
	return setScreen(current_resolution, bitDepth, surface->flags);
}

inline const Size DC::getTextExtent(const std::string& text) const {
	return font->getTextExtent(text);
}

inline Sint16 DC::getMaxX() const {
	return max_x;
}

inline Sint16 DC::getMaxY() const {
	return max_y;
}

inline Uint8 DC::getBits() const {
	return bits;
}

inline eBitDepth DC::getBitDepth() const {
	return bitDepth;
}

inline void DC::setFont(const boost::shared_ptr<const Font>& font) {
	this->font = font;
}

#endif // _SDL_DC_HPP


