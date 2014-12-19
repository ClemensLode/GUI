#ifndef _GUICORE_FIXTURE_COLORFIXTURE_HPP
#define _GUICORE_FIXTURE_COLORFIXTURE_HPP

#pragma warning(push, 0)  
#include <boost/shared_ptr.hpp>
#pragma warning(pop)

#include <guicore/color.hpp>
#include <map>
#include <sdlwrapfixture/dc_fixture.hpp>

struct Color_Fixture
{
	DC_Fixture dcFixture;
	
	const boost::uuids::uuid TEST_THEME1_ID;
	const boost::uuids::uuid TEST_THEME2_ID;
	const SDL_Color test_sdlcolor1;
	const SDL_Color test_sdlcolor2;

	const std::map<const boost::uuids::uuid, const SDL_Color> test_sdlcolorMap;
	const boost::shared_ptr<const Color> test_color;

	Color_Fixture();	
	~Color_Fixture();

private:
	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Color> > test_colorMap;
	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Color> > init_colormap_helper();
	const std::map<const boost::uuids::uuid, const SDL_Color> init_sdlcolormap_helper() const;
};

#endif // _GUICORE_FIXTURE_COLORFIXTURE_HPP
