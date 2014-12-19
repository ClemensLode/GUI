#ifndef _GEOMETRY_FIXTURE_ZRECTFIXTURE_HPP
#define _GEOMETRY_FIXTURE_ZRECTFIXTURE_HPP

#pragma warning(push, 0)  
#include <boost/shared_ptr.hpp>
#pragma warning(pop)

#include <geometry/zrect.hpp>


struct ZRect_Fixture
{
	const Rect test_rect;
	const signed int test_z;

	const boost::shared_ptr<const ZRect> test_zrect;

	ZRect_Fixture();
	virtual ~ZRect_Fixture();
};

#endif // _GEOMETRY_FIXTURE_ZRECTFIXTURE_HPP