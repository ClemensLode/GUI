#include <misc/randomgenerator.hpp>

#include "objectsize_fixture.hpp"
#include <geometry/objectsize_storage.hpp>
#include <geometry/geometry_directories.hpp>

ObjectSize_Fixture::ObjectSize_Fixture() :
	TEST_RESOLUTION1_ID(Misc::uuid("0448727e-0ed7-464f-bb43-1761e228f66c")),
	TEST_RESOLUTION2_ID(Misc::uuid("0dc5b93a-d64c-473a-ac65-75eae4eba09f")),
	test_objectsize1_size(static_cast<Uint16>(RandomGenerator::instance().rnd()), static_cast<Uint16>(RandomGenerator::instance().rnd())),
	test_objectsize2_size(static_cast<Uint16>(RandomGenerator::instance().rnd()), static_cast<Uint16>(RandomGenerator::instance().rnd())),
	test_sizeMap(init_sizemap_helper()),
	test_objectsize(new ObjectSize(test_sizeMap)),
	test_objectsizeMap(init_objectsizemap_helper())
{ 
	GeometryDirectories::initTemp("temp");	

	ObjectSizeStorage::instance(test_objectsizeMap);
}

ObjectSize_Fixture::~ObjectSize_Fixture() 
{ 
	GeometryDirectories::initTemp("temp");

	ObjectSizeStorage::clear();
	
	GeometryDirectories::init();
}

const std::map<const boost::uuids::uuid, const boost::shared_ptr<const ObjectSize> > ObjectSize_Fixture::init_objectsizemap_helper() {
	std::map<const boost::uuids::uuid, const boost::shared_ptr<const ObjectSize> > objectsizeMap;
	objectsizeMap.insert(std::pair<const boost::uuids::uuid, const boost::shared_ptr<const ObjectSize> >(test_objectsize->getId(), test_objectsize));
	return objectsizeMap;
}

const std::map<const boost::uuids::uuid, const Size> ObjectSize_Fixture::init_sizemap_helper() const {
	std::map<const boost::uuids::uuid, const Size> sizemap;

	sizemap.insert(std::pair<const boost::uuids::uuid, const Size>(TEST_RESOLUTION1_ID, test_objectsize1_size));
	sizemap.insert(std::pair<const boost::uuids::uuid, const Size>(TEST_RESOLUTION2_ID, test_objectsize2_size));

	return sizemap;
}
