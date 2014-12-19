#ifndef _GUICORE_THEME_HPP
#define _GUICORE_THEME_HPP

class Color;

#include <misc/uuid.hpp>

class Theme : public UUID<Theme>
{
public:
	Theme(const boost::uuids::uuid& id, const std::string& name, const boost::shared_ptr<const Color> primaryColor, const boost::shared_ptr<const Color> secondaryColor);
	Theme(const std::string& name, const boost::shared_ptr<const Color> primaryColor, const boost::shared_ptr<const Color> secondaryColor);
	~Theme() { }

	const std::string& getName() const;
	const boost::shared_ptr<const Color>& getPrimaryColor() const; 
	const boost::shared_ptr<const Color>& getSecondaryColor() const;

private:
	const std::string name;
	const boost::shared_ptr<const Color> primaryColor;
	const boost::shared_ptr<const Color> secondaryColor;

	Theme(const Theme& other);
	Theme& operator=(const Theme& other);
};
	
inline const std::string& Theme::getName() const {
	return name;
}

inline const boost::shared_ptr<const Color>& Theme::getPrimaryColor() const {
	return primaryColor;
}

inline const boost::shared_ptr<const Color>& Theme::getSecondaryColor() const {
	return secondaryColor;
}

#endif // _GUICORE_THEME_HPP
