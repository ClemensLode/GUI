#ifndef _GEOMETRY_FIXTURE_OBJECTSIZEFIXTUREHELPER_HPP
#define _GEOMETRY_FIXTURE_OBJECTSIZEFIXTUREHELPER_HPP

#pragma warning(push, 0)
#include <boost/shared_ptr.hpp>
#include <boost/signals.hpp>
#include <boost/bind.hpp>
#include <boost/bind/placeholders.hpp>
#pragma warning(pop)

#include <geometry/objectsize.hpp>

class ObjectSize_Fixture_Helper
{
public:
	ObjectSize_Fixture_Helper(const boost::shared_ptr<const ObjectSize>& size) {
		size->connect(boost::bind(&ObjectSize_Fixture_Helper::updateSize, this, _1));
	}
	~ObjectSize_Fixture_Helper() {}
	const Size& getSize() const { return currentSize; }

	// this is used for signalling
	void updateSize(const Size new_size) { currentSize = new_size;}

private:
	Size currentSize;
};

#endif // _GEOMETRY_FIXTURE_OBJECTSIZEFIXTUREHELPER_HPP