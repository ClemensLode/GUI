#include "resolution.hpp"

Resolution::Resolution(const boost::uuids::uuid& id, const std::string& name, const Size size):
UUID<Resolution>(id),
	name(name),
	size(size)
{ }


Resolution::Resolution(const std::string& name, const Size size):
	UUID<Resolution>(),
	name(name),
	size(size)
{ }