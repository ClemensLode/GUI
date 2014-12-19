#ifndef _GEOMETRY_FIXTURE_OBJECTSIZEFIXTURE_HPP
#define _GEOMETRY_FIXTURE_OBJECTSIZEFIXTURE_HPP

#pragma warning(push, 0)  
#include <boost/shared_ptr.hpp>
#pragma warning(pop)

#include <geometry/objectsize.hpp>
#include <map>

struct ObjectSize_Fixture
{
	const boost::uuids::uuid TEST_RESOLUTION1_ID;
	const boost::uuids::uuid TEST_RESOLUTION2_ID;
	const Size test_objectsize1_size;
	const Size test_objectsize2_size; 

	const std::map<const boost::uuids::uuid, const Size> test_sizeMap;
	const boost::shared_ptr<const ObjectSize> test_objectsize;

	ObjectSize_Fixture();	
	~ObjectSize_Fixture();

private:
	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const ObjectSize> > test_objectsizeMap;
	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const ObjectSize> > init_objectsizemap_helper();
	const std::map<const boost::uuids::uuid, const Size> init_sizemap_helper() const;
};

#endif // _GEOMETRY_FIXTURE_OBJECTSIZEFIXTURE_HPP
