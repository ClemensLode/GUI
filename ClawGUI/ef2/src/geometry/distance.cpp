#include <sstream>

#include "distance.hpp"

void Distance::setWidth(const unsigned int width) {
	BOOST_ASSERT(width <= 10000);
	this->width = width;
}

void Distance::setHeight(const unsigned int height) {
	BOOST_ASSERT(height <= 10000);
	this->height = height;
}

const std::string Distance::toString() const
{
	std::ostringstream os;
	os << getWidth() << "x" << getHeight();
	return os.str();
}

const unsigned int Distance::MAX_WIDTH = 30000;
const unsigned int Distance::MAX_HEIGHT = 30000;
