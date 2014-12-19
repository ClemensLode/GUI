#include <misc/randomgenerator.hpp>

#include "resolution_fixture.hpp"
#include <geometry/resolution_storage.hpp>
#include <geometry/geometry_directories.hpp>

Resolution_Fixture::Resolution_Fixture() :
	test_name("test resolution"),
	test_size(Size(RandomGenerator::instance().rnd(), RandomGenerator::instance().rnd())),
	test_resolution(new Resolution(test_name, test_size)),
	test_resolutionMap(init_resolutionmap_helper())
{
	GeometryDirectories::initTemp("temp");	

	ResolutionStorage::instance(test_resolutionMap);
}

Resolution_Fixture::~Resolution_Fixture() 
{ 
	GeometryDirectories::initTemp("temp");

	ResolutionStorage::clear();
	
	GeometryDirectories::init();
}

const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Resolution> > Resolution_Fixture::init_resolutionmap_helper() {
	std::map<const boost::uuids::uuid, const boost::shared_ptr<const Resolution> > resolutionMap;
	resolutionMap.insert(std::pair<const boost::uuids::uuid, const boost::shared_ptr<const Resolution> >(test_resolution->getId(), test_resolution));
	return resolutionMap;
}