#include "size.hpp"
#include <sstream>

void Size::setWidth(const Uint16 width) {
	BOOST_ASSERT(width <= 10000);
	this->width = width;
}

void Size::setHeight(const Uint16 height) {
	BOOST_ASSERT(height <= 10000);
	this->height = height;
}

bool Size::mv(Uint16& x, const Uint16 sx, const Uint16 tx)
{
	BOOST_ASSERT( (x >= sx && x <= tx) || (x <= sx && x >= tx) );

	int x1 = x;
	int sx1 = sx;
	int tx1 = tx;

	if(x == tx) {
		return true;
	}

	int z;
	if(sx < tx) {
		if(2*x < tx+sx) {
			z = x1 - sx1;
		} else {
			z = tx1 - x1;
		}
	} else {
		if(2*x > tx+sx) {
			z = x1 - sx1;
		} else {
			z = tx1 - x1;
		}
	}
	if(abs(z) > 1) {
		z /= 2;
	}
	if(z == 0) {
		z = sx<tx?1:-1;
	}

	BOOST_ASSERT(x1 + z >= 0);
	x = static_cast<Uint16>(x1 + z);

	return false;
}	

void Size::move(const Size& startSize, const Size& targetSize)
{
	mv(width, startSize.getWidth(), targetSize.getWidth());
	mv(height, startSize.getHeight(), targetSize.getHeight());
}	



const std::string Size::toString() const
{
	std::ostringstream os;
	os << getWidth() << "x" << getHeight();
	return os.str();
}
