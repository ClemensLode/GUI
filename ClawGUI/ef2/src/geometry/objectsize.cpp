#include "objectsize.hpp"

ObjectSize::ObjectSize(const boost::uuids::uuid id, const std::map<const boost::uuids::uuid, const Size>& sizeMap, const eAutoSize horizontalAutoSizeType, const eAutoSize verticalAutoSizeType):
	UUID<ObjectSize>(id),
	sizeMap(sizeMap),
	horizontalAutoSizeType(horizontalAutoSizeType),
	verticalAutoSizeType(verticalAutoSizeType),
	size(), // TODO default size?
	sig(),
	resolutionId() // TODO default resolution? static?
{ }

ObjectSize::ObjectSize(const std::map<const boost::uuids::uuid, const Size>& sizeMap, const eAutoSize horizontalAutoSizeType, const eAutoSize verticalAutoSizeType):
	UUID<ObjectSize>(),
	sizeMap(sizeMap),
	horizontalAutoSizeType(horizontalAutoSizeType),
	verticalAutoSizeType(verticalAutoSizeType),
	size(),
	sig(),
	resolutionId()
{ }

ObjectSize::~ObjectSize()
{ }

	
void ObjectSize::updateResolution(const boost::uuids::uuid resolutionId) const {
	if(this->resolutionId == resolutionId) {
		return;
	}
	this->resolutionId = resolutionId;

	const std::map<const boost::uuids::uuid, const Size>::const_iterator i = sizeMap.find(resolutionId);
	
	BOOST_ASSERT(i != sizeMap.end());

	size = i->second;
	sig(size);
}


boost::signals::connection ObjectSize::connect(boost::signal<void (Size)>::slot_function_type subscriber) const {
	BOOST_ASSERT(sizeMap.size() > 0);

	return sig.connect(subscriber);
}