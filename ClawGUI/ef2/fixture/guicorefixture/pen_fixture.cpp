#include <misc/randomgenerator.hpp>

#include "pen_fixture.hpp"
#include <guicore/pen_storage.hpp>
#include <guicore/guicore_directories.hpp>

Pen_Fixture::Pen_Fixture() :
	colorFixture(),
	test_width(static_cast<Uint16>(RandomGenerator::instance().rnd())),
	test_style(static_cast<ePenStyle>(RandomGenerator::instance().rnd() % MAX_PEN_STYLE)),
	test_pen(new Pen(colorFixture.test_color, test_width, test_style)),
	test_penMap(init_penmap_helper())
{ 
	GuiCoreDirectories::initTemp("temp");	

	PenStorage::instance(test_penMap);
}

Pen_Fixture::~Pen_Fixture() 
{ 
	GuiCoreDirectories::initTemp("temp");

	PenStorage::clear();
	
	GuiCoreDirectories::init();
}

const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Pen> > Pen_Fixture::init_penmap_helper() {
	std::map<const boost::uuids::uuid, const boost::shared_ptr<const Pen> > penMap;
	penMap.insert(std::pair<const boost::uuids::uuid, const boost::shared_ptr<const Pen> >(test_pen->getId(), test_pen));
	return penMap;
}