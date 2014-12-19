#ifndef _MISC_DISTANCE_HPP
#define _MISC_DISTANCE_HPP

// is similar to the SDL version "size"

#include <string>
#include <iostream>
#include <math.h>

#pragma warning(push, 0)  
#include <boost/assert.hpp>
#pragma warning(pop)

class Distance
{
public:
	Distance(const Distance& distance);
	Distance(const unsigned int width, const unsigned int height);
	Distance& operator=(const Distance& distance);
	bool operator==(const Distance& distance) const;
	bool operator<(const Distance& distance) const;
	bool operator>(const Distance& distance) const;
	bool operator!=(const Distance& distance) const;
	const Distance operator+(const Distance& distance) const;
	const Distance operator-(const Distance& distance) const;
	const Distance operator/(const unsigned int d) const;
	void setWidth(const unsigned int width);
	void setHeight(const unsigned int height);
	unsigned int getWidth() const;
	unsigned int getHeight() const;
	unsigned int getLength() const;

	const std::string toString() const;

private:
	unsigned int width;
	unsigned int height;

	static const unsigned int MAX_WIDTH;
	static const unsigned int MAX_HEIGHT;
};

inline Distance::Distance(const Distance& distance):width(distance.width), height(distance.height) {}

inline Distance::Distance(const unsigned int width, const unsigned int height):width(width),height(height) {
	BOOST_ASSERT(width <= MAX_WIDTH && height <= MAX_HEIGHT);
}

inline const Distance Distance::operator-(const Distance& distance) const {
	return Distance(width - distance.width, height - distance.height);
}

inline Distance& Distance::operator=(const Distance& distance)
{
	setWidth(distance.width);
	setHeight(distance.height);
	return *this;
}

inline bool Distance::operator==(const Distance& distance) const {
	return (width == distance.width) && (height == distance.height);
}

inline bool Distance::operator<(const Distance& distance) const {
	return (width < distance.width) && (height < distance.height);
}	

inline bool Distance::operator>(const Distance& distance) const {
	return (width > distance.width) && (height > distance.height);
}	

inline bool Distance::operator!=(const Distance& distance) const {
	return !(*this == distance);
}

inline const Distance Distance::operator+(const Distance& distance) const {
	return Distance(width + distance.width, height + distance.height);
}

inline const Distance Distance::operator/(const unsigned int d) const {
	return Distance(width/d, height/d);
}


inline unsigned int Distance::getWidth() const {
	return width;
}

inline unsigned int Distance::getHeight() const {
	return height;
}


inline unsigned int Distance::getLength() const {
	return static_cast<unsigned int>(sqrt(static_cast<float>(width * width + height * height)));
}

#endif // _MISC_DISTANCE_HPP