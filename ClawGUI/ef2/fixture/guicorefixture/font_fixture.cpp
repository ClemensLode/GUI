#include <misc/randomgenerator.hpp>

#include "font_fixture.hpp"

#include <misc/miscellaneous.hpp>
#include <misc/io.hpp>
#include <guicore/font_storage.hpp>
#include <guicore/guicore_directories.hpp>

#pragma warning(push, 0) 
#include <boost/assign/list_of.hpp>
#pragma warning(pop)

Font_Fixture::Font_Fixture() :
test_fileName("freesans.ttf"),
	test_size(static_cast<Uint16>(RandomGenerator::instance().rnd())),
	test_underlined(RandomGenerator::instance().rndBool()),
	test_shadow(RandomGenerator::instance().rndBool()),
	test_font(createTestFont(test_fileName, test_size, test_underlined, test_shadow)),
	test_fontMap(init_fontmap_helper())
{ 
	GuiCoreDirectories::initTemp("temp");	

	FontStorage::instance(test_fontMap);
}

Font_Fixture::~Font_Fixture() 
{ 
	GuiCoreDirectories::initTemp("temp");

	FontStorage::clear();
	
	GuiCoreDirectories::init();
}

const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Font> > Font_Fixture::init_fontmap_helper() {
	std::map<const boost::uuids::uuid, const boost::shared_ptr<const Font> > fontMap;
	fontMap.insert(std::pair<const boost::uuids::uuid, const boost::shared_ptr<const Font> >(test_font->getId(), test_font));
	return fontMap;
}

boost::shared_ptr<const Font> Font_Fixture::createTestFont(std::string test_fileName, Uint16 test_size, bool test_underlined, bool test_shadow) {
	Font::initTTF();
	return boost::shared_ptr<const Font>(new Font(test_fileName, test_size, test_underlined, test_shadow));
}

	/*


	SDL_version compile_version;
	const SDL_version *link_version=TTF_Linked_Version();
	SDL_TTF_VERSION(&compile_version);
	printf("compiled with SDL_ttf version: %d.%d.%d\n", 
	compile_version.major,
	compile_version.minor,
	compile_version.patch);
	printf("running with SDL_ttf version: %d.%d.%d\n", 
	link_version->major,
	link_version->minor,
	link_version->patch);
	*/

