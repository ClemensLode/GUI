#ifndef _GUICORE_FIXTURE_CURSORFIXTURE_HPP
#define _GUICORE_FIXTURE_CURSORFIXTURE_HPP

#pragma warning(push, 0)  
#include <boost/shared_ptr.hpp>
#pragma warning(pop)

#include <guicore/cursor.hpp>
#include <map>
#include "bitmap_fixture.hpp"

struct Cursor_Fixture
{
	Bitmap_Fixture test_bitmapFixture;

	const boost::shared_ptr<const Cursor> test_cursor1;
	const boost::shared_ptr<const Cursor> test_cursor2;

	Cursor_Fixture();	
	~Cursor_Fixture();
private:
	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Cursor> > test_cursorMap;
	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Cursor> > init_cursormap_helper();
};

#endif // _GUICORE_FIXTURE_CURSORFIXTURE_HPP
