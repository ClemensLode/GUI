#ifndef _GUICORE_STORAGES_BUTTONANIMATION_STORAGE_HPP
#define _GUICORE_STORAGES_BUTTONANIMATION_STORAGE_HPP

#include <misc/singlestorage.hpp>

class ButtonAnimation;

class ButtonAnimationStorage : public SingleStorage<ButtonAnimation>
{ 
public:
	static const std::string node_string;
	static const std::string id_string;
	static const std::string startBrushID_string;
	static const std::string endBrushID_string;
	static const std::string startTextColorID_string;
	static const std::string endTextColorID_string;
	static const std::string startBorderPenID_string;
	static const std::string endBorderPenID_string;
	static const std::string bitmapID_string;
};

#endif // _GUICORE_STORAGES_BUTTONANIMATION_STORAGE_HPP
