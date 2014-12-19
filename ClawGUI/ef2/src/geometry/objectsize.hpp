#ifndef _GEOMETRY_OBJECTSIZE_HPP
#define _GEOMETRY_OBJECTSIZE_HPP

#pragma warning(push, 0)  
#include <boost/signals.hpp>
#pragma warning(pop)

#include "size.hpp"
#include "enums/autosize.hpp"

#include <misc/uuid.hpp>

class ObjectSize : public UUID<ObjectSize>
{
public:
	ObjectSize(const std::map<const boost::uuids::uuid, const Size>& sizeMap, const eAutoSize horizontalAutoSizeType = NO_AUTO_SIZE, const eAutoSize verticalAutoSizeType = NO_AUTO_SIZE);
	ObjectSize(const boost::uuids::uuid id, const std::map<const boost::uuids::uuid, const Size>& sizeMap, const eAutoSize horizontalAutoSizeType = NO_AUTO_SIZE, const eAutoSize verticalAutoSizeType = NO_AUTO_SIZE);
	~ObjectSize();

	const Size& getSize() const;
	operator const Size()const;
	Size operator->() const;

	Uint16 getWidth() const;
	Uint16 getHeight() const;

	void updateResolution(const boost::uuids::uuid resolutionId) const;
	// use public boost::signals::trackable on the object wanting to connect to test
	// .connect(boost::bind(&CLASS::function, this, _1));
	boost::signals::connection connect(boost::signal<void (Size)>::slot_function_type subscriber) const;
	const std::map<const boost::uuids::uuid, const Size>& getSizeMap() const;
	
	eAutoSize getHorizontalAutoSizeType() const;
	eAutoSize getVerticalAutoSizeType() const;

private:
	const std::map<const boost::uuids::uuid, const Size> sizeMap;
	const eAutoSize horizontalAutoSizeType;
	const eAutoSize verticalAutoSizeType;

	mutable Size size;

	mutable boost::signal<void (Size)> sig;
	mutable boost::uuids::uuid resolutionId;

	ObjectSize& operator=(const ObjectSize& object);
	ObjectSize(const ObjectSize& object);
};


inline eAutoSize ObjectSize::getHorizontalAutoSizeType() const {
	return horizontalAutoSizeType;
}

inline eAutoSize ObjectSize::getVerticalAutoSizeType() const {
	return verticalAutoSizeType;
}

inline ObjectSize::operator const Size() const { 
	return size;
}

inline const Size& ObjectSize::getSize() const {
	return size;
}

inline Size ObjectSize::operator->() const {
	return size;
}

inline Uint16 ObjectSize::getWidth() const {
	return size.getWidth();
}

inline Uint16 ObjectSize::getHeight() const {
	return size.getHeight();
}

inline const std::map<const boost::uuids::uuid, const Size>& ObjectSize::getSizeMap() const {
	return sizeMap;
}

#endif // _GEOMETRY_OBJECTSIZE_HPP