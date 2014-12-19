#include "buttonanimation.hpp"

#include "brush_storage.hpp"
#include "color_storage.hpp"
#include "pen_storage.hpp"
#include "bitmap_storage.hpp"


ButtonAnimation::ButtonAnimation(const boost::uuids::uuid id, const boost::shared_ptr<const Brush>& startBrush, const boost::shared_ptr<const Brush>& endBrush, const boost::shared_ptr<const Color>& startTextColor, 
		const boost::shared_ptr<const Color>& endTextColor, const boost::shared_ptr<const Pen>& startBorderPen, const boost::shared_ptr<const Pen>& endBorderPen, const boost::shared_ptr<const Bitmap>& bitmap):
	UUID<ButtonAnimation>(id),
	startBrush(startBrush),
	endBrush(endBrush),
	startTextColor(startTextColor),
	endTextColor(endTextColor),
	startBorderPen(startBorderPen),
	endBorderPen(endBorderPen),
	bitmap(bitmap)
{ }

ButtonAnimation::ButtonAnimation(const boost::shared_ptr<const Brush>& startBrush, const boost::shared_ptr<const Brush>& endBrush, const boost::shared_ptr<const Color>& startTextColor, 
		const boost::shared_ptr<const Color>& endTextColor, const boost::shared_ptr<const Pen>& startBorderPen, const boost::shared_ptr<const Pen>& endBorderPen, const boost::shared_ptr<const Bitmap>& bitmap):
	UUID<ButtonAnimation>(),
	startBrush(startBrush),
	endBrush(endBrush),
	startTextColor(startTextColor),
	endTextColor(endTextColor),
	startBorderPen(startBorderPen),
	endBorderPen(endBorderPen),
	bitmap(bitmap)
{ }
	
ButtonAnimation::~ButtonAnimation() {}

