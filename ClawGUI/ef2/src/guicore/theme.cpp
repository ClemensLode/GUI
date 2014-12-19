#include "theme.hpp"
#include "color.hpp"

Theme::Theme(const boost::uuids::uuid& id, const std::string& name, const boost::shared_ptr<const Color> primaryColor, const boost::shared_ptr<const Color> secondaryColor):
UUID<Theme>(id),
	name(name),
	primaryColor(primaryColor),
	secondaryColor(secondaryColor)
{ }

Theme::Theme(const std::string& name, const boost::shared_ptr<const Color> primaryColor, const boost::shared_ptr<const Color> secondaryColor):
	UUID<Theme>(),
	name(name),
	primaryColor(primaryColor),
	secondaryColor(secondaryColor)
{ }