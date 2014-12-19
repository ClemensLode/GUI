#ifndef _GUICORE_FIXTURE_PENFIXTURE_HPP
#define _GUICORE_FIXTURE_PENFIXTURE_HPP

#pragma warning(push, 0)  
#include <boost/shared_ptr.hpp>
#pragma warning(pop)

#include <guicore/pen.hpp>
#include "color_fixture.hpp"
#include <map>

struct Pen_Fixture
{
	const Color_Fixture colorFixture;
	const Uint16 test_width;
	const ePenStyle test_style;

	const boost::shared_ptr<const Pen> test_pen;

	Pen_Fixture();	
	~Pen_Fixture();
private:
	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Pen> > test_penMap;
	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Pen> > init_penmap_helper();
};

#endif // _GUICORE_FIXTURE_PENFIXTURE_HPP
