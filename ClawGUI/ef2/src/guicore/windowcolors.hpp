#ifndef _GUICORE_WINDOWCOLORS_HPP
#define _GUICORE_WINDOWCOLORS_HPP

#include "brush.hpp"
#include "color.hpp"
#include "pen.hpp"
#include "font.hpp"

#include <misc/uuid.hpp>

class WindowColors : public UUID<WindowColors>
{
public:
	WindowColors(const boost::uuids::uuid id,
		const boost::shared_ptr<const Font>& font, 
		const boost::shared_ptr<const Color>& text_color, 
		const boost::shared_ptr<const Brush>& background_brush, 
		const boost::shared_ptr<const Pen>& border_pen, 
		const boost::shared_ptr<const Pen>& outer_border_pen, 
		const boost::shared_ptr<const Pen>& highlighted_border_pen);
	WindowColors(const boost::shared_ptr<const Font>& font, 
		const boost::shared_ptr<const Color>& text_color, 
		const boost::shared_ptr<const Brush>& background_brush, 
		const boost::shared_ptr<const Pen>& border_pen, 
		const boost::shared_ptr<const Pen>& outer_border_pen, 
		const boost::shared_ptr<const Pen>& highlighted_border_pen);
	~WindowColors();

	const boost::shared_ptr<const Font>& getFont() const {return font;}
	const boost::shared_ptr<const Color>& getTextColor() const {return textColor;}
	const boost::shared_ptr<const Brush>& getBackgroundBrush() const {return backgroundBrush;}
	const boost::shared_ptr<const Pen>& getBorderPen() const {return borderPen;}
	const boost::shared_ptr<const Pen>& getOuterBorderPen() const {return outerBorderPen;}
	const boost::shared_ptr<const Pen>& getHighlightedBorderPen() const {return highlightedBorderPen;}

private:
	const boost::shared_ptr<const Font> font;
	const boost::shared_ptr<const Color> textColor;
	const boost::shared_ptr<const Brush> backgroundBrush;
	const boost::shared_ptr<const Pen> borderPen;
	const boost::shared_ptr<const Pen> outerBorderPen;
	const boost::shared_ptr<const Pen> highlightedBorderPen;
};

#endif // _GUICORE_WINDOWCOLORS_HPP