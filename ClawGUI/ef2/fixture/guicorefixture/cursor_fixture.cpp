#include <misc/randomgenerator.hpp>

#include "cursor_fixture.hpp"

#include <misc/miscellaneous.hpp>
#include <misc/io.hpp>
#include <guicore/cursor_storage.hpp>
#include <guicore/guicore_directories.hpp>


#pragma warning(push, 0) 
#include <boost/assign/list_of.hpp>
#pragma warning(pop)

Cursor_Fixture::Cursor_Fixture() :
	test_bitmapFixture(),
	
	test_cursor1(new Cursor(test_bitmapFixture.test_bitmap1)),
	test_cursor2(new Cursor(test_bitmapFixture.test_bitmap2)),
	test_cursorMap(init_cursormap_helper())
{ 
	GuiCoreDirectories::initTemp("temp");	

	CursorStorage::instance(test_cursorMap);
}

Cursor_Fixture::~Cursor_Fixture() 
{ 
	GuiCoreDirectories::initTemp("temp");

	CursorStorage::clear();
	
	GuiCoreDirectories::init();
}

const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Cursor> > Cursor_Fixture::init_cursormap_helper() {
	std::map<const boost::uuids::uuid, const boost::shared_ptr<const Cursor> > cursorMap;
	cursorMap.insert(std::pair<const boost::uuids::uuid, const boost::shared_ptr<const Cursor> >(test_cursor1->getId(), test_cursor1));
	cursorMap.insert(std::pair<const boost::uuids::uuid, const boost::shared_ptr<const Cursor> >(test_cursor2->getId(), test_cursor2));
	return cursorMap;
}