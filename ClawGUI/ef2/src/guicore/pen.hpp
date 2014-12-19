#ifndef _GUICORE_PEN_HPP
#define _GUICORE_PEN_HPP

#pragma warning(push, 0)  
#include <SDL.h>
#include <boost/shared_ptr.hpp>
#pragma warning(pop)

#include <misc/uuid.hpp>

#include "color.hpp"
#include "enums/penstyle.hpp"

// #define PEN_MAX_WIDTH 1000 TODO

class Pen : public UUID<Pen>
{
public:
	Pen(const boost::shared_ptr<const Color> color, const Uint16 width = 1, const ePenStyle pen_style = SOLID_PEN_STYLE);
	Pen(const boost::uuids::uuid id, const boost::shared_ptr<const Color> color, const Uint16 width = 1, const ePenStyle pen_style = SOLID_PEN_STYLE);
	~Pen();

	ePenStyle getStyle() const;
	Uint16 getWidth() const;
	const boost::shared_ptr<const Color>& getColor() const;
	void setColor(const Color& pen_color);

private:

	const boost::shared_ptr<const Color> color;
	const Uint16 width;
	const ePenStyle style;

	Pen(const Pen& other);
	const Pen& operator=(const Pen& other);
};

inline ePenStyle Pen::getStyle() const {
	return style;
}

inline Uint16 Pen::getWidth() const {
	return width;
}

inline const boost::shared_ptr<const Color>& Pen::getColor() const {
	return color;
}

#endif // _GUICORE_PEN_HPP

