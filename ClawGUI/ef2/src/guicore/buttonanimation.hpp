#ifndef _GUICORE_BUTTONANIMATION_HPP
#define _GUICORE_BUTTONANIMATION_HPP

#include "brush.hpp"
#include "color.hpp"
#include "pen.hpp"
#include "bitmap.hpp"

#include <misc/uuid.hpp>

#include <vector>

class ButtonAnimation : public UUID<ButtonAnimation>
{
public:
	ButtonAnimation(const boost::uuids::uuid id, const boost::shared_ptr<const Brush>& startBrush, const boost::shared_ptr<const Brush>& endBrush, const boost::shared_ptr<const Color>& startTextColor, 
		const boost::shared_ptr<const Color>& endTextColor, const boost::shared_ptr<const Pen>& startBorderPen, const boost::shared_ptr<const Pen>& endBorderPen, const boost::shared_ptr<const Bitmap>& bitmap);

	ButtonAnimation(const boost::shared_ptr<const Brush>& startBrush, const boost::shared_ptr<const Brush>& endBrush, const boost::shared_ptr<const Color>& startTextColor, 
		const boost::shared_ptr<const Color>& endTextColor, const boost::shared_ptr<const Pen>& startBorderPen, const boost::shared_ptr<const Pen>& endBorderPen, const boost::shared_ptr<const Bitmap>& bitmap);
	~ButtonAnimation();

	const boost::shared_ptr<const Brush>& getStartBrush() const;
	const boost::shared_ptr<const Brush>& getEndBrush() const;
	const boost::shared_ptr<const Color>& getStartTextColor() const;
	const boost::shared_ptr<const Color>& getEndTextColor() const;	
	const boost::shared_ptr<const Pen>& getStartBorderPen() const;
	const boost::shared_ptr<const Pen>& getEndBorderPen() const;
	const boost::shared_ptr<const Bitmap>& getBitmap() const;

private:

	const boost::shared_ptr<const Brush> startBrush;
	const boost::shared_ptr<const Brush> endBrush;
	const boost::shared_ptr<const Color> startTextColor;
	const boost::shared_ptr<const Color> endTextColor;	
	const boost::shared_ptr<const Pen> startBorderPen;
	const boost::shared_ptr<const Pen> endBorderPen;
	const boost::shared_ptr<const Bitmap> bitmap;
};

	
inline const boost::shared_ptr<const Brush>& ButtonAnimation::getStartBrush() const {
	return startBrush;
}

inline const boost::shared_ptr<const Brush>& ButtonAnimation::getEndBrush() const {
	return endBrush;
}

inline const boost::shared_ptr<const Color>& ButtonAnimation::getStartTextColor() const {
	return startTextColor;
}

inline const boost::shared_ptr<const Color>& ButtonAnimation::getEndTextColor() const {
	return endTextColor;
}

inline const boost::shared_ptr<const Pen>& ButtonAnimation::getStartBorderPen() const {
	return startBorderPen;
}

inline const boost::shared_ptr<const Pen>& ButtonAnimation::getEndBorderPen() const {
	return endBorderPen;
}

inline const boost::shared_ptr<const Bitmap>& ButtonAnimation::getBitmap() const {
	return bitmap;
}


#endif // _GUICORE_BUTTONANIMATION_HPP