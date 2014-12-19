#ifndef _GUICORE_BRUSH_HPP
#define _GUICORE_BRUSH_HPP

#include "color.hpp"
#include "enums/brushstyle.hpp"

#include <misc/uuid.hpp>

class Brush : public UUID<Brush>
{
public:
	Brush(const boost::uuids::uuid id, const boost::shared_ptr<const Color>& color, const eBrushStyle style = SOLID_BRUSH_STYLE);
	Brush(const boost::shared_ptr<const Color>& color, const eBrushStyle style = SOLID_BRUSH_STYLE);
	~Brush();

	eBrushStyle getStyle() const;
	const boost::shared_ptr<const Color>& getColor() const;

private:

	const boost::shared_ptr<const Color> color;
	const eBrushStyle style;
};

inline eBrushStyle Brush::getStyle() const {
	return style;
}

inline const boost::shared_ptr<const Color>& Brush::getColor() const {
	return color;
}

#endif // _GUICORE_BRUSH_HPP
