#include "brush.hpp"
#include "color_storage.hpp"

Brush::Brush(const boost::shared_ptr<const Color>& color, const eBrushStyle style):
	color(color),
	style(style)
{ }

Brush::Brush(const boost::uuids::uuid id, const boost::shared_ptr<const Color>& color, const eBrushStyle style):
	UUID<Brush>(id),
	color(color),
	style(style)
{ }


Brush::~Brush()
{ }
