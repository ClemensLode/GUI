#include "windowcolors.hpp"

#include "font_storage.hpp"
#include "color_storage.hpp"
#include "brush_storage.hpp"
#include "pen_storage.hpp"

WindowColors::WindowColors(const boost::shared_ptr<const Font>& font, 
		const boost::shared_ptr<const Color>& text_color, 
		const boost::shared_ptr<const Brush>& background_brush, 
		const boost::shared_ptr<const Pen>& border_pen, 
		const boost::shared_ptr<const Pen>& outer_border_pen, 
		const boost::shared_ptr<const Pen>& highlighted_border_pen):
	UUID<WindowColors>(),
	font(font),
	textColor(text_color),
	backgroundBrush(background_brush),
	borderPen(border_pen),
	outerBorderPen(outer_border_pen),
	highlightedBorderPen(highlighted_border_pen)
{ }

WindowColors::WindowColors(const boost::uuids::uuid id,
		const boost::shared_ptr<const Font>& font, 
		const boost::shared_ptr<const Color>& text_color, 
		const boost::shared_ptr<const Brush>& background_brush, 
		const boost::shared_ptr<const Pen>& border_pen, 
		const boost::shared_ptr<const Pen>& outer_border_pen, 
		const boost::shared_ptr<const Pen>& highlighted_border_pen):
	UUID<WindowColors>(id),
	font(font),
	textColor(text_color),
	backgroundBrush(background_brush),
	borderPen(border_pen),
	outerBorderPen(outer_border_pen),
	highlightedBorderPen(highlighted_border_pen)
{ }

WindowColors::~WindowColors()
{ }

