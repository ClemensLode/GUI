#include <misc/randomgenerator.hpp>

#include "bitmap_fixture.hpp"
#include <misc/miscellaneous.hpp>
#include <misc/io.hpp>
#include <guicore/bitmap_storage.hpp>
#include <guicore/guicore_directories.hpp>

#pragma warning(push, 0) 
#include <boost/assign/list_of.hpp>
#pragma warning(pop)

Bitmap_Fixture::Bitmap_Fixture() :
	test_fileName1("clawsoftware.jpg"),
	test_fileName2("clawsoftware.png"),
	test_objectSizeFixture1(),
	test_objectSizeFixture2(),
	test_transparent1(RandomGenerator::instance().rndBool()),
	test_transparent2(RandomGenerator::instance().rndBool()),
	test_bitmap1(new Bitmap(test_fileName1, test_objectSizeFixture1.test_objectsize, test_transparent1)),
	test_bitmap2(new Bitmap(test_fileName2, test_objectSizeFixture2.test_objectsize, test_transparent2)),
	test_bitmapMap(init_bitmapmap_helper())
{ 
	GuiCoreDirectories::initTemp("temp");	

	BitmapStorage::instance(test_bitmapMap);
}

Bitmap_Fixture::~Bitmap_Fixture() 
{
	GuiCoreDirectories::initTemp("temp");

	BitmapStorage::clear();
	
	GuiCoreDirectories::init();
}

const std::map<const boost::uuids::uuid, const boost::shared_ptr<const Bitmap> > Bitmap_Fixture::init_bitmapmap_helper() {
	std::map<const boost::uuids::uuid, const boost::shared_ptr<const Bitmap> > bitmapMap;
	bitmapMap.insert(std::pair<const boost::uuids::uuid, const boost::shared_ptr<const Bitmap> >(test_bitmap1->getId(), test_bitmap1));
	bitmapMap.insert(std::pair<const boost::uuids::uuid, const boost::shared_ptr<const Bitmap> >(test_bitmap2->getId(), test_bitmap2));
	return bitmapMap;
}