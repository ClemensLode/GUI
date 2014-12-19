#include "buttoncolors.hpp"

#include "buttonanimation_storage.hpp"

ButtonColors::ButtonColors(const boost::uuids::uuid id, const boost::shared_ptr<const Font> font, const unsigned int speed, const eButtonAnimationType animationType, const std::vector<boost::shared_ptr<const ButtonAnimation> >& buttonAnimationVector):
	UUID<ButtonColors>(id),
	font(font),
	speed(speed),
	animationType(animationType),
	buttonAnimationVector(buttonAnimationVector)
{ }

ButtonColors::ButtonColors(const boost::shared_ptr<const Font> font, const unsigned int speed, const eButtonAnimationType animationType, const std::vector<boost::shared_ptr<const ButtonAnimation> >& buttonAnimationVector):
	font(font),
	speed(speed),
	animationType(animationType),
	buttonAnimationVector(buttonAnimationVector)
{ }

ButtonColors::~ButtonColors()
{ }
