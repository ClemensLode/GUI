#ifndef _GUICORE_RESOLUTION_HPP
#define _GUICORE_RESOLUTION_HPP

#include <misc/uuid.hpp>
#include <geometry/size.hpp>

class Resolution : public UUID<Resolution>
{
public:
	Resolution(const boost::uuids::uuid& id, const std::string& name, const Size size);
	Resolution(const std::string& name, const Size size);
	~Resolution() { }

	const std::string& getName() const;
	const Size& getSize() const;

private:
	const std::string name;
	const Size size;

	Resolution(const Resolution& other);
	Resolution& operator=(const Resolution& other);
};
	
inline const std::string& Resolution::getName() const {
	return name;
}

inline const Size& Resolution::getSize() const {
	return size;
}

#endif // _GUICORE_RESOLUTION_HPP
