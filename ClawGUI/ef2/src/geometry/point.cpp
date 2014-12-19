#include "point.hpp"
#include <sstream>

#pragma warning(push, 0)
#include <boost/assert.hpp>
#pragma warning(pop)


void Point::setX(const Sint16 x) {
	BOOST_ASSERT(x >= -10000 && x <= 10000);
	this->x = x;
}

void Point::setY(const Sint16 y) {
	BOOST_ASSERT(y >= -10000 && y <= 10000);
	this->y = y;
}

bool Point::mv(Sint16& x, const Sint16 sx, const Sint16 tx)
{
	BOOST_ASSERT( (x >= sx && x <= tx) || (x <= sx && x >= tx) );

	if(x == tx) {
		return true;
	}

	int x1 = x;
	int sx1 = sx;
	int tx1 = tx;
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
	z/=2;
	if(z == 0) {
		z = sx1<tx1?1:-1;
	}

	BOOST_ASSERT(z <= 32768 && z >= -32767);
	x = static_cast<Sint16>(x + z);

	return false;
}	


void Point::move(const Point& startPoint, const Point& targetPoint)
{
	mv(x, startPoint.x, targetPoint.x);
	mv(y, startPoint.y, targetPoint.y);
}	

const std::string Point::toString() const
{
	std::ostringstream os;
	os << getX() << ":" << getY();
	return os.str();
}
