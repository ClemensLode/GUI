#ifndef _GUICORE_FIXTURE_BRUSHFIXTURE_HPP
#define _GUICORE_FIXTURE_BRUSHFIXTURE_HPP

#pragma warning(push, 0)  
#include <boost/shared_ptr.hpp>
#pragma warning(pop)

#include <guicore/brush.hpp>

#include "color_fixture.hpp"
#include <map>

struct Brush_Fixture
{
	const Color_Fixture colorFixture;
	const eBrushStyle test_style;
	const boost::shared_ptr<const Brush> test_brush;

	Brush_Fixture();	
	~Brush_Fixture();

private:
	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Brush> > test_brushMap;
	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Brush> > init_brushmap_helper();
};

#endif // _GUICORE_FIXTURE_BRUSHFIXTURE_HPP
