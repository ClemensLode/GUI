#ifndef _GEOMETRY_SIZE_HPP
#define _GEOMETRY_SIZE_HPP

#include <string>
#include <iostream>


#pragma warning(push, 0)  
#include <math.h>
#include <SDL_stdinc.h> // for Uint16, Sint16
#include <boost/assert.hpp>
#pragma warning(pop)

#include <sstream>

class Size
{
	friend std::ostream& operator<<(std::ostream& out, Size val) {out << val.toString();return out;}
public:

	Size();
	Size(const Size& size);
	Size(const Uint16 width, const Uint16 height);

	Size& operator=(const Size& size);
	bool operator==(const Size& size) const;
	bool operator<(const Size& size) const;
	bool operator<=(const Size& size) const;
	bool operator>(const Size& size) const;
	bool operator>=(const Size& size) const;
	bool operator!=(const Size& size) const;
	const Size operator+(const Size& size) const;
	Size& operator+=(const Size& size);
	const Size operator-(const Size& size) const;
	const Size operator/(const Uint16 d) const;

	void setWidth(const Uint16 width);
	void setHeight(const Uint16 height);

	Uint16 getWidth() const;
	Uint16 getHeight() const;

	void move(const Size& startSize, const Size& targetSize);
	static bool mv(Uint16& x, const Uint16 sx, const Uint16 tx);

	const std::string toString() const;
	unsigned int getDiagonalLength() const;

private:
	Uint16 width;
	Uint16 height;
};

inline Size::Size() : width(0), height(0)
{ }

inline Size::Size(const Size& size) {
	setWidth(size.getWidth());
	setHeight(size.getHeight());
}

inline Size::Size(const Uint16 width, const Uint16 height) {
	setWidth(width);
	setHeight(height);
}

inline const Size Size::operator-(const Size& size) const {
	BOOST_ASSERT(width >= size.getWidth());
	BOOST_ASSERT(height >= size.getHeight());

	return Size(static_cast<Uint16>(width - size.getWidth()), static_cast<Uint16>(height - size.getHeight()));
}

inline Size& Size::operator=(const Size& size)
{
	setWidth(size.getWidth());
	setHeight(size.getHeight());
	return *this;
}

inline bool Size::operator==(const Size& size) const {
	return (width == size.getWidth()) && (height == size.getHeight());
}

inline bool Size::operator<(const Size& size) const {
	return (width < size.getWidth()) && (height < size.getHeight());
}	

inline bool Size::operator>(const Size& size) const {
	return (width > size.getWidth()) && (height > size.getHeight());
}	

inline bool Size::operator<=(const Size& size) const {
	return (width <= size.getWidth()) && (height <= size.getHeight());
}	

inline bool Size::operator>=(const Size& size) const {
	return (width >= size.getWidth()) && (height >= size.getHeight());
}	

inline bool Size::operator!=(const Size& size) const {
	return !(*this == size);
}

inline const Size Size::operator+(const Size& size) const {
	
	BOOST_ASSERT(width + size.getWidth() <= 65536 && height + size.getHeight() <= 65536);
	return Size(static_cast<Uint16>(width + size.getWidth()), static_cast<Uint16>(height + size.getHeight()));
}

inline Size& Size::operator+=(const Size& size) 
{
	*this = *this + size;
	return *this;
}

inline const Size Size::operator/(const Uint16 d) const {
	return Size(static_cast<Uint16>(width/d), static_cast<Uint16>(height/d));
}


inline Uint16 Size::getWidth() const {
	return width;
}

inline Uint16 Size::getHeight() const {
	return height;
}

inline unsigned int Size::getDiagonalLength() const {
	return static_cast<unsigned int>(sqrt(static_cast<float>(width * width + height * height)));
}

#endif // _GEOMETRY_SIZE_HPP

