#ifndef _GUICORE_BUTTONCOLORS_HPP
#define _GUICORE_BUTTONCOLORS_HPP

#include "font.hpp"

#include "enums/buttonanimationphase.hpp"
#include "enums/buttonanimationtype.hpp"

#include <misc/uuid.hpp>

#include <vector>

#include "buttonanimation.hpp"

class ButtonColors : public UUID<ButtonColors>
{
public:
	ButtonColors(const boost::uuids::uuid id, const boost::shared_ptr<const Font> font, const unsigned int speed, const eButtonAnimationType animationType, const std::vector<boost::shared_ptr<const ButtonAnimation> >& buttonAnimationVector);
	ButtonColors(const boost::shared_ptr<const Font> font, const unsigned int speed, const eButtonAnimationType animationType, const std::vector<boost::shared_ptr<const ButtonAnimation> >& buttonAnimationVector);
	~ButtonColors();

	const boost::shared_ptr<const ButtonAnimation>& getButtonAnimation(eButtonAnimationPhase phase) const;
	const boost::shared_ptr<const Font>& getFont() const;
	unsigned int getSpeed() const;
	eButtonAnimationType getAnimationType() const;
	const std::vector<boost::shared_ptr<const ButtonAnimation> >& getButtonAnimationVector() const { return buttonAnimationVector;}

private:
	const boost::shared_ptr<const Font> font;
	const unsigned int speed; // 100 = 100 steps for full animation
	const eButtonAnimationType animationType;
	const std::vector<boost::shared_ptr<const ButtonAnimation> > buttonAnimationVector;
};

inline const boost::shared_ptr<const ButtonAnimation>& ButtonColors::getButtonAnimation(eButtonAnimationPhase phase) const {
	return buttonAnimationVector.at(phase);
}

inline const boost::shared_ptr<const Font>& ButtonColors::getFont() const {
	return font;
}

inline unsigned int ButtonColors::getSpeed() const {
	return speed;
}

inline eButtonAnimationType ButtonColors::getAnimationType() const {
	return animationType;
}

#endif // _GUICORE_BUTTONCOLORS_HPP