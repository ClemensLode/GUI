#ifndef _GEOMETRY_RECT_HPP
#define _GEOMETRY_RECT_HPP

#include <list>

#include "point.hpp"
#include "enums/touchtype.hpp"

#pragma warning(push, 0)  
#include <SDL.h>
#pragma warning(pop)


class Rect
{
	friend std::ostream& operator<<(std::ostream& out, Rect val) {out << val.toString();return out;}
public:
	Rect();
	Rect(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height);
	Rect(const Point& pos, const Size& size);
	Rect(const Point& top_left_pos, const Point& bottom_right_pos);
	Rect(const Rect& rect);

	const Point& getTopLeft() const;
	const Point getBottomLeft() const;
	void setTopLeft( const Point& point );
	const Point& getBottomRight() const;
	const Point getTopRight() const;

	const Size& getSize() const;
	void setSize( const Size& size );
	Uint16 getWidth() const;
	void setWidth(const Uint16 width);
	Uint16 getHeight() const;
	void setHeight(const Uint16 height);
	Sint16 getLeft() const;
	Sint16 getTop() const;
	Sint16 getBottom() const;
	Sint16 getRight()  const;
	void setLeft(const Sint16 left);
	void setTop(const Sint16 top); 
	void setRight(const Sint16 right);
	void setBottom(const Sint16 bottom);

	static const SDL_Rect createRect(const Sint16 x, const Sint16 y, const Uint16 w, const Uint16 h);
	static const SDL_Rect createRect(const Point p, const Size s);
	static const SDL_Rect createRect(const Rect& r);

	const Rect operator+(const Point p) const;
	Rect& operator=(const Rect& rect);
	bool operator==(const Rect& rect) const;
	bool operator!=(const Rect& rect) const;

	bool isPixelInside(const Sint16 x, const Sint16 y) const;
	bool isPixelInside(const Point& point) const;
	bool isTopLeftCornerInside(const Sint16 x, const Sint16 y) const;
	bool isTopRightCornerInside(const Sint16 x, const Sint16 y) const;
	bool isBottomRightCornerInside(const Sint16 x, const Sint16 y) const;
	bool isBottomLeftCornerInside(const Sint16 x, const Sint16 y) const;
	bool isTopLeftCornerInside(const Point& point) const;
	bool isTopRightCornerInside(const Point& point) const;
	bool isBottomRightCornerInside(const Point& point) const;
	bool isBottomLeftCornerInside(const Point& point) const;
	bool isRectInside(const Rect& rect) const;
	
	eTouchType getTouchType(const Rect& rect) const;
	bool isTouched(const Rect& rect) const;
	const Rect commonRect(const Rect& rect) const; // Schnittmenge
	std::list<Rect> withoutRect(const Rect& rect) const; // Ohne
	std::list<Rect> removeRects(const std::list<Rect>& rects) const;
	void moveSmooth(Rect& start_rect, Rect& target_rect);

	
	const std::string toString() const;

private:
	void calculateBottomRightCorner();
	void correctStartTargetRectPosition(Point& start_rect_pos, Point& target_rect_pos);
	void correctStartTargetRectSize(Size& start_rect_size, Size& target_rect_size);

	Point topLeftCorner;
	Point bottomRightCorner;
	Size rectSize;
};

inline const SDL_Rect Rect::createRect(const Sint16 x, const Sint16 y, const Uint16 w, const Uint16 h) {
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	return rect;
}

inline const SDL_Rect Rect::createRect(const Point p, const Size s) {
	SDL_Rect rect;	
	rect.x = p.getX();
	rect.y = p.getY();
	rect.w = s.getWidth();
	rect.h = s.getHeight();
	return rect;
}


inline const SDL_Rect Rect::createRect(const Rect& r) {
	SDL_Rect rect;
	rect.x = r.getLeft();
	rect.y = r.getTop();
	rect.w = r.getWidth();
	rect.h = r.getHeight();
	return rect;
}

inline Rect::Rect():topLeftCorner(0,0),bottomRightCorner(0,0), rectSize(0,0) 
{ }

inline Rect::Rect(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height) :
	topLeftCorner(x, y),
	bottomRightCorner(Point(x, y) + Size(width, height)),
	rectSize(width, height)
{ }


inline Rect::Rect(const Point& pos, const Size& size) :
	topLeftCorner(pos),
	bottomRightCorner(pos + size),
	rectSize(size)
{ }

inline Rect::Rect(const Point& top_left_pos, const Point& bottom_right_pos) :
	topLeftCorner(top_left_pos),
	bottomRightCorner(bottom_right_pos),
	rectSize(bottom_right_pos - top_left_pos)
{ }

inline const Rect Rect::operator+(const Point p) const {
	return Rect(topLeftCorner + p, rectSize);
}

inline void Rect::calculateBottomRightCorner() {
	bottomRightCorner = topLeftCorner + rectSize;
}


inline const Point& Rect::getTopLeft() const { 
	return topLeftCorner; 
}

inline const Size& Rect::getSize() const { 
	return rectSize; 
}

inline const Point& Rect::getBottomRight() const {
	return bottomRightCorner;
}

inline Rect::Rect(const Rect& rect) : 
topLeftCorner(rect.getTopLeft()), 
	bottomRightCorner(rect.getBottomRight()),
	rectSize(rect.getSize()) 
{ }	

inline const Point Rect::getTopRight() const {
	return Point(bottomRightCorner.getX(), topLeftCorner.getY());
}

inline const Point Rect::getBottomLeft() const {
	return Point(topLeftCorner.getX(), bottomRightCorner.getY());
}

inline void Rect::setTopLeft( const Point& point ) { 
	topLeftCorner = point; 
	calculateBottomRightCorner();
}

inline void Rect::setSize( const Size& size ) {
	rectSize = size;
	calculateBottomRightCorner();
}

inline Uint16 Rect::getWidth() const { 
	return rectSize.getWidth();
}

inline Uint16 Rect::getHeight() const { 
	return rectSize.getHeight(); 
}

inline Sint16 Rect::getLeft() const {
	return topLeftCorner.getX();
}

inline Sint16 Rect::getTop() const {
	return topLeftCorner.getY();
}

inline Sint16 Rect::getBottom() const { 
	return bottomRightCorner.getY();
}

inline Sint16 Rect::getRight()  const { 
	return bottomRightCorner.getX();
}

inline void Rect::setWidth(const Uint16 width) {
	rectSize.setWidth(width);
	BOOST_ASSERT(width + topLeftCorner.getX() <= 32768 && width + topLeftCorner.getX() >= -32767);
	bottomRightCorner.setX(static_cast<Sint16>(width + topLeftCorner.getX()));
}

inline void Rect::setHeight(const Uint16 height) { 
	rectSize.setHeight(height);
	BOOST_ASSERT(height + topLeftCorner.getY() <= 32768 && height + topLeftCorner.getY() >= -32767);
	bottomRightCorner.setY(static_cast<Sint16>(height + topLeftCorner.getY()));
}

inline void Rect::setLeft(const Sint16 left) { 
	topLeftCorner.setX(left);
	BOOST_ASSERT(left + rectSize.getWidth() <= 32768 && left + rectSize.getWidth() >= -32767);
	bottomRightCorner.setX(static_cast<Sint16>(left + rectSize.getWidth()));
}

inline void Rect::setRight(const Sint16 right) {
	Sint16 left_side = getLeft();
	BOOST_ASSERT(right >= left_side);
	rectSize.setWidth(static_cast<Uint16>(right - left_side));
	bottomRightCorner.setX(right);
}

inline void Rect::setTop(const Sint16 top) { 
	BOOST_ASSERT(top + rectSize.getHeight() <= 32768 && top + rectSize.getHeight() >= -32767);
	topLeftCorner.setY(top); 
	bottomRightCorner.setY(static_cast<Sint16>(top + rectSize.getHeight()));
}

inline void Rect::setBottom(const Sint16 bottom) {
	Sint16 top_side = getTop();
	BOOST_ASSERT(bottom >= top_side);
	rectSize.setHeight(static_cast<Uint16>(bottom - top_side));
	bottomRightCorner.setY(bottom);
}

inline Rect& Rect::operator=(const Rect& rect) 
{	
	topLeftCorner = rect.getTopLeft();
	bottomRightCorner = rect.getBottomRight();
	rectSize = rect.getSize();
	return *this;
}

inline bool Rect::operator==(const Rect& rect) const 
{ 
	if( ( getTopLeft() != rect.getTopLeft() ) || ( getSize() != rect.getSize() ) ) {
		return false;
	}
	else {
		return true; 
	}
}

inline bool Rect::operator!=(const Rect& rect) const {
	return !(*this == rect);
}

inline bool Rect::isRectInside(const Rect& rect) const {
	return rect.getTopLeft() >= topLeftCorner && rect.getBottomRight() <= bottomRightCorner;
}

inline bool Rect::isPixelInside(const Point& point) const {
	if( point >= topLeftCorner && point < bottomRightCorner ) {
		return true;
	} else {
		return false;
	}
}

inline bool Rect::isTopLeftCornerInside(const Point& point) const {
	return point >= topLeftCorner  && point < bottomRightCorner;
}

inline bool Rect::isTopRightCornerInside(const Point& point) const {
	return point >= (topLeftCorner + Point(1, 0)) && point < (bottomRightCorner + Point(1, 0));
}

inline bool Rect::isBottomRightCornerInside(const Point& point) const {
	return point >= (topLeftCorner + Point(1, 1)) && point < (bottomRightCorner + Point(1, 1));
}

inline bool Rect::isBottomLeftCornerInside(const Point& point) const {
	return point >= (topLeftCorner + Point(0, 1)) && point < (bottomRightCorner + Point(0, 1));
}

inline bool Rect::isTopLeftCornerInside(const Sint16 x, const Sint16 y) const {
	return isTopLeftCornerInside(Point(x, y));
}

inline bool Rect::isTopRightCornerInside(const Sint16 x, const Sint16 y) const {
	return isTopRightCornerInside(Point(x, y));
}

inline bool Rect::isBottomRightCornerInside(const Sint16 x, const Sint16 y) const {
	return isBottomRightCornerInside(Point(x, y));
}

inline bool Rect::isBottomLeftCornerInside(const Sint16 x, const Sint16 y) const {
	return isBottomLeftCornerInside(Point(x, y));
}

inline bool Rect::isPixelInside(const Sint16 x, const Sint16 y) const {
	return isPixelInside(Point(x,y));
}

inline bool Rect::isTouched(const Rect& rect) const {
	if(rect.getLeft() >= getRight() || getLeft() >= rect.getRight() || rect.getTop() >= getBottom() || getTop() >= rect.getBottom()) {
		return false;
	} else {
		return true;
	}
}

#endif // _GEOMETRY_RECT_HPP

