#ifndef _GEOMETRY_POINT_HPP
#define _GEOMETRY_POINT_HPP

#include "size.hpp"

class Point
{
	friend std::ostream& operator<<(std::ostream& out, Point val) {out << val.toString();return out;}
public:
	Point();
	Point(const Sint16 x, const Sint16 y);
	Point& operator=(const Point& point);
	bool operator==(const Point& point) const;
	bool operator!=(const Point& point) const;
	const Point operator+(const Point& point) const;
	const Point operator*(const Sint16 scalar) const;
	const Point operator*(const Size& size) const;
	const Point operator+(const Size& size) const;
	const Point operator-(const Size& size) const;
	const Size operator-(const Point& point) const;
	Point& operator+=(const Size& size);
	Point& operator-=(const Size& size);
	bool operator>=(const Point& point) const;
	bool operator<=(const Point& point) const;
	bool operator>(const Point& point) const;
	bool operator<(const Point& point) const;
	void move(const Point& startPoint, const Point& targetPoint);
	static bool mv(Sint16& x, const Sint16 sx, const Sint16 tx);

	void setX(const Sint16 x);
	void setY(const Sint16 y);

	Sint16 getX() const;
	Sint16 getY() const;

	const std::string toString() const;

private:
	Sint16 x;
	Sint16 y;
};


inline Point::Point():	x(0), y(0)
{ }

inline Point::Point(const Sint16 x, const Sint16 y)
{
	setX(x);
	setY(y);
}


inline Sint16 Point::getX() const {
	return x;
}

inline Sint16 Point::getY() const {
	return y;
}

inline Point& Point::operator=(const Point& point)
{
	setX(point.x);
	setY(point.y);

	return *this;
}

inline bool Point::operator==(const Point& point) const {
	return (x == point.x) && (y == point.y);
}

inline bool Point::operator!=(const Point& point) const {
	return !(*this == point);
}

inline const Point Point::operator*(const Sint16 scalar) const	{
	BOOST_ASSERT(x*scalar <= 32768 && x*scalar >= -32677 && y*scalar <= 32768 && y*scalar >=-32677);
	return Point(static_cast<Sint16>(x * scalar), static_cast<Sint16>(y * scalar) );
}

inline const Point Point::operator*(const Size& size) const {
	BOOST_ASSERT(x*size.getWidth() <= 32768 && x*size.getWidth() >= -32677 && y*size.getHeight() <= 32768 && y*size.getWidth() >=-32677);
	return Point(static_cast<Sint16>(x * size.getWidth()), static_cast<Sint16>(y * size.getHeight()));
}


inline const Point Point::operator+(const Point& point) const	{
	BOOST_ASSERT(x + point.x <= 32768 && x + point.x >= -32677 && y + point.y <= 32768 && y + point.y >=-32677);
	return Point(static_cast<Sint16>(x + point.x), static_cast<Sint16>(y + point.y) );
}

inline const Point Point::operator+(const Size& size) const	{
	BOOST_ASSERT(x + size.getWidth() <= 32768 && x + size.getWidth() >= -32677 && y + size.getHeight() <= 32768 && y + size.getHeight() >=-32677);
	return Point(static_cast<Sint16>(x + size.getWidth()), static_cast<Sint16>(y + size.getHeight()) );
}

inline const Point Point::operator-(const Size& size) const {
	BOOST_ASSERT(x - size.getWidth() <= 32768 && x - size.getWidth() >= -32677 && y - size.getHeight() <= 32768 && y - size.getHeight() >=-32677);
	return Point(static_cast<Sint16>(x - size.getWidth()), static_cast<Sint16>(y - size.getHeight()) );
}

inline const Size Point::operator-(const Point& point) const {
	BOOST_ASSERT((abs(x - point.x) <= 65536 && abs(y - point.y) <= 65536));
	return Size(static_cast<Uint16>(abs(x - point.x)), static_cast<Uint16>(abs(y - point.y)));
}

inline Point& Point::operator+=(const Size& size) 
{
	*this = *this + size;
	return *this;
}

inline Point& Point::operator-=(const Size& size)
{
	*this = *this - size;
	return *this;
}

inline bool Point::operator>=(const Point& point) const
{
	if((x >= point.x) && (y >= point.y)) {
		return true;
	} else {
		return false;
	}
}

inline bool Point::operator<=(const Point& point) const
{
	if((x <= point.x) && (y <= point.y)) {
		return true;
	} else {
		return false;
	}
}

inline bool Point::operator>(const Point& point) const
{
	if((x > point.x) && (y > point.y)) {
		return true;
	} else {
		return false;
	}
}

inline bool Point::operator<(const Point& point) const
{
	if((x < point.x) && (y < point.y)) {
		return true;
	} else {
		return false;
	}
}	


#endif // _GEOMETRY_POINT_HPP
