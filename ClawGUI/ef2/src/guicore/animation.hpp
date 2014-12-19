#ifndef _SDL_ANIMATION_HPP
#define _SDL_ANIMATION_HPP

#pragma warning(push, 0)  
#include <smpeg/smpeg.h>
#pragma warning(pop)

#include <string>

#include <misc/uuid.hpp>


class Animation : public UUID<Animation>
{
public:
	operator SMPEG*() const;
	SMPEG* operator->() const;
	SMPEG* getSurface() const { return animation;}
	const SMPEG_Info& getInfo() const;
	const std::string& getName() const;

private:

	const std::string name;

	SMPEG* animation;
	SMPEG_Info info;

	bool used;
};

inline const SMPEG_Info& Animation::getInfo() const {
	return info;
}

inline const std::string& Animation::getName() const {
	return name;
}

inline Animation::operator SMPEG*() const { 
	return animation;
}

inline SMPEG* Animation::operator->() const {
	return animation;
}

#endif // _GUICORE_ANIMATION_HPP
