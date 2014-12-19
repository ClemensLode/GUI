#ifndef _GEOMETRY_STORAGES_OBJECTSIZE_STORAGE_HPP
#define _GEOMETRY_STORAGES_OBJECTSIZE_STORAGE_HPP

#include <misc/singlestorage.hpp>

class ObjectSize;

class ObjectSizeStorage : public SingleStorage<ObjectSize>
{ 
public:
	static void updateResolution(const boost::uuids::uuid resolutionId);
	static boost::uuids::uuid getCurrentResolutionId();

private:
	static boost::uuids::uuid currentResolutionId;

};

inline boost::uuids::uuid ObjectSizeStorage::getCurrentResolutionId() {
	return currentResolutionId;
}

#endif // _GEOMETRY_STORAGES_OBJECTSIZE_STORAGE_HPP
