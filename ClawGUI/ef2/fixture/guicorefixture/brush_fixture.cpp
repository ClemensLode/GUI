#include <misc/randomgenerator.hpp>

#include "brush_fixture.hpp"
#include <guicore/brush_storage.hpp>
#include <guicore/guicore_directories.hpp>

Brush_Fixture::Brush_Fixture() :
	colorFixture(),
	test_style(static_cast<eBrushStyle>(RandomGenerator::instance().rnd() % MAX_BRUSH_STYLES)),
	test_brush(new Brush(colorFixture.test_color, test_style)),
	test_brushMap(init_brushmap_helper())
{ 
	GuiCoreDirectories::initTemp("temp");	

	BrushStorage::instance(test_brushMap);
}

Brush_Fixture::~Brush_Fixture() 
{ 
	GuiCoreDirectories::initTemp("temp");	

	BrushStorage::clear();
	
	GuiCoreDirectories::init();
}

const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Brush> > Brush_Fixture::init_brushmap_helper() {
	std::map<const boost::uuids::uuid, const boost::shared_ptr<const Brush> > brushMap;
	brushMap.insert(std::pair<const boost::uuids::uuid, const boost::shared_ptr<const Brush> >(test_brush->getId(), test_brush));
	return brushMap;
}