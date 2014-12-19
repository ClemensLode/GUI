#ifndef _GUICORE_ENUMS_BUTTONANIMATIONTYPE_HPP
#define _GUICORE_ENUMS_BUTTONANIMATIONTYPE_HPP

enum eButtonAnimationType
{
	NO_ANIMATION,
	JUMPY_COLORS_ANIMATION, // gets bright and jumps back
	GLOWING_ANIMATION, // back and forth
	BLINKING_ANIMATION, // jumps between start and end colors

	MAX_BUTTON_ANIMATION_TYPES
};

#endif // _GUICORE_ENUMS_BUTTONANIMATIONTYPE_HPP