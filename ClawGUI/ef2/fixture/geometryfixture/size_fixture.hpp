#ifndef _GEOMETRY_FIXTURE_SIZEFIXTURE_HPP
#define _GEOMETRY_FIXTURE_SIZEFIXTURE_HPP

#pragma warning(push, 0)  
#include <boost/shared_ptr.hpp>
#pragma warning(pop)

#include <geometry/size.hpp>


struct Size_Fixture
{
	const Uint16 test_width;
	const Uint16 test_height;

	const boost::shared_ptr<const Size> test_size;

	const Uint16 test_target_width;
	const Uint16 test_target_height;

	const boost::shared_ptr<const Size> test_target_size;

	Size_Fixture();
	virtual ~Size_Fixture();
};

#endif // _GEOMETRY_FIXTURE_SIZEFIXTURE_HPP