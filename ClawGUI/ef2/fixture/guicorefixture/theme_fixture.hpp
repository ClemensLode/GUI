#ifndef _GUICORE_FIXTURE_THEMEFIXTURE_HPP
#define _GUICORE_FIXTURE_THEMEFIXTURE_HPP

#pragma warning(push, 0)  
#include <boost/shared_ptr.hpp>
#pragma warning(pop)

#include <guicore/theme.hpp>
#include "color_fixture.hpp"
#include <map>

struct Theme_Fixture
{
	const Color_Fixture primaryColorFixture;
	const Color_Fixture secondaryColorFixture;
	const std::string test_name;

	const boost::shared_ptr<const Theme> test_theme;

	Theme_Fixture();	
	~Theme_Fixture();

private:
	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Theme> > test_themeMap;
	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Theme> > init_thememap_helper();
};

#endif // _GUICORE_FIXTURE_THEMEFIXTURE_HPP
