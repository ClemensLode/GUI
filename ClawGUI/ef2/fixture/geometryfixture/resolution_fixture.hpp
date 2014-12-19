#ifndef _GEOMETRY_FIXTURE_RESOLUTIONFIXTURE_HPP
#define _GEOMETRY_FIXTURE_RESOLUTIONFIXTURE_HPP

#pragma warning(push, 0)  
#include <boost/shared_ptr.hpp>
#pragma warning(pop)

#include <geometry/resolution.hpp>
#include <map>

struct Resolution_Fixture
{

	const std::string test_name;
	const Size test_size;

	const boost::shared_ptr<const Resolution> test_resolution;

	Resolution_Fixture();	
	~Resolution_Fixture();

private:
	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Resolution> > test_resolutionMap;
	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Resolution> > init_resolutionmap_helper();
};

#endif // _GEOMETRY_FIXTURE_RESOLUTIONFIXTURE_HPP
