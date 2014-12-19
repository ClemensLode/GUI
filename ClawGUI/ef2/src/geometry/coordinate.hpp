#ifndef _CORE_COORDINATE_HPP
#define _CORE_COORDINATE_HPP

#pragma warning(push, 0)  
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/assert.hpp>
#pragma warning(pop)

#include "distance.hpp"

class Coordinate
{
public:
	Coordinate(const Coordinate& coordinate);
	virtual ~Coordinate() {}
	Coordinate(const signed int x, const signed int y);
	Coordinate& operator=(const Coordinate& coordinate);
	bool operator==(const Coordinate& coordinate) const;
	bool operator!=(const Coordinate& coordinate) const;
	const Coordinate operator+(const Coordinate& coordinate) const;
	const Coordinate operator*(const signed int scalar) const;
	const Coordinate operator+(const Distance& distance) const;
	const Coordinate operator-(const Distance& distance) const;
	const Distance operator-(const Coordinate& coordinate) const;
	Coordinate& operator+=(const Distance& distance);
	Coordinate& operator-=(const Distance& distance);
	bool operator>=(const Coordinate& coordinate) const;
	bool operator<=(const Coordinate& coordinate) const;
	bool operator>(const Coordinate& coordinate) const;
	bool operator<(const Coordinate& coordinate) const;

	void setX(const signed int x);
	void setY(const signed int y);

	signed int getX() const;
	signed int getY() const;

protected:
	friend class boost::serialization::access;

	template<class Archive> 
	void serialize(Archive &ar, const unsigned int version)
	{
		ar & BOOST_SERIALIZATION_NVP(x);
		& BOOST_SERIALIZATION_NVP(y);

		if(version > 0) {
		}
	}	

	signed int x;
	signed int y;
};


inline Coordinate::Coordinate(const Coordinate& coordinate):x(coordinate.x), y(coordinate.y) {}

inline Coordinate::Coordinate(const signed int x, const signed int y):
x(x),
	y(y)
{
	BOOST_ASSERT(x >= -10000 && x <= 10000);
	BOOST_ASSERT(y >= -10000 && y <= 10000);	
}

inline signed int Coordinate::getX() const {
	return x;
}

inline signed int Coordinate::getY() const {
	return y;
}

inline Coordinate& Coordinate::operator=(const Coordinate& coordinate)
{
	setX(coordinate.x);
	setY(coordinate.y);
	return *this;
}

inline bool Coordinate::operator==(const Coordinate& coordinate) const {
	return (x == coordinate.x) && (y == coordinate.y);
}

inline bool Coordinate::operator!=(const Coordinate& coordinate) const {
	return !(*this == coordinate);
}

inline const Coordinate Coordinate::operator*(const signed int scalar) const	{
	return Coordinate(x * scalar, y * scalar );
}

inline const Coordinate Coordinate::operator+(const Coordinate& coordinate) const	{
	return Coordinate(x + coordinate.x, y + coordinate.y );
}

inline const Coordinate Coordinate::operator+(const Distance& distance) const	{
	return Coordinate(x + static_cast<signed int>(distance.getWidth()), y + static_cast<signed int>(distance.getHeight()) );
}

inline const Coordinate Coordinate::operator-(const Distance& distance) const {
	return Coordinate(x - static_cast<signed int>(distance.getWidth()), y - static_cast<signed int>(distance.getHeight()) );
}

inline const Distance Coordinate::operator-(const Coordinate& coordinate) const {
	return Distance(static_cast<unsigned int>(abs(x - coordinate.x)), static_cast<unsigned int>(abs(y - coordinate.y)));
}

inline Coordinate& Coordinate::operator+=(const Distance& distance) 
{
	setX(x + static_cast<signed int>(distance.getWidth()));
	setY(y + static_cast<signed int>(distance.getHeight()));
	return *this;
}

inline Coordinate& Coordinate::operator-=(const Distance& distance)
{
	setX(x - static_cast<signed int>(distance.getWidth()));
	setY(y - static_cast<signed int>(distance.getHeight()));
	return *this;
}

inline bool Coordinate::operator>=(const Coordinate& coordinate) const
{
	if((x >= coordinate.x) && (y >= coordinate.y)) {
		return true;
	} else {
		return false;
	}
}

inline bool Coordinate::operator<=(const Coordinate& coordinate) const
{
	if((x <= coordinate.x) && (y <= coordinate.y)) {
		return true;
	} else {
		return false;
	}
}

inline bool Coordinate::operator>(const Coordinate& coordinate) const
{
	if((x > coordinate.x) && (y > coordinate.y)) {
		return true;
	}
	else {
		return false;
	}
}

inline bool Coordinate::operator<(const Coordinate& coordinate) const
{
	if((x < coordinate.x) && (y < coordinate.y)) {
		return true;
	} else {
		return false;
	}
}	

inline void Coordinate::setX(const signed int x) {
	BOOST_ASSERT(x >= -10000 && x <= 10000);

	this->x = x;
}

inline void Coordinate::setY(const signed int y) {
	BOOST_ASSERT(y >= -10000 && y <= 10000);

	this->y = y;
}

#endif // _CORE_COORDINATE_HPP
