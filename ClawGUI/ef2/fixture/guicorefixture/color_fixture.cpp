#include <misc/randomgenerator.hpp>

#include "color_fixture.hpp"
#include <guicore/color_storage.hpp>
#include <guicore/guicore_directories.hpp>

Color_Fixture::Color_Fixture() :
// TODO also test other bit depths. Problem: SDL Map RGB functions only approximate with 8bit, 16bit, 24bit bitdepths
	dcFixture(DEPTH_32BIT),
	TEST_THEME1_ID(Misc::randomUuid()),
	TEST_THEME2_ID(Misc::randomUuid()),
	test_sdlcolor1(Color::toSDL_Color(static_cast<Uint8>(RandomGenerator::instance().rnd()), static_cast<Uint8>(RandomGenerator::instance().rnd()), static_cast<Uint8>(RandomGenerator::instance().rnd()), static_cast<Uint8>(RandomGenerator::instance().rnd()))),
	test_sdlcolor2(Color::toSDL_Color(static_cast<Uint8>(RandomGenerator::instance().rnd()), static_cast<Uint8>(RandomGenerator::instance().rnd()), static_cast<Uint8>(RandomGenerator::instance().rnd()), static_cast<Uint8>(RandomGenerator::instance().rnd()))),
	test_sdlcolorMap(init_sdlcolormap_helper()),
	test_color(new Color(test_sdlcolorMap)),
	test_colorMap(init_colormap_helper())
{ 
	GuiCoreDirectories::initTemp("temp");	

	ColorStorage::instance(test_colorMap);
}

Color_Fixture::~Color_Fixture() 
{ 
	GuiCoreDirectories::initTemp("temp");

	ColorStorage::clear();
	
	GuiCoreDirectories::init();
}


const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Color> > Color_Fixture::init_colormap_helper() {
	std::map<const boost::uuids::uuid, const boost::shared_ptr<const Color> > colorMap;
	colorMap.insert(std::pair<const boost::uuids::uuid, const boost::shared_ptr<const Color> >(test_color->getId(), test_color));
	return colorMap;
}

const std::map<const boost::uuids::uuid, const SDL_Color> Color_Fixture::init_sdlcolormap_helper() const {
	std::map<const boost::uuids::uuid, const SDL_Color> colormap;

	colormap.insert(std::pair<const boost::uuids::uuid, const SDL_Color>(TEST_THEME1_ID, test_sdlcolor1));
	colormap.insert(std::pair<const boost::uuids::uuid, const SDL_Color>(TEST_THEME2_ID, test_sdlcolor2));

	return colormap;
}
