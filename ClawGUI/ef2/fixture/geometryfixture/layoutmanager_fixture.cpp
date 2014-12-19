#include <misc/randomgenerator.hpp>

#include "layoutmanager_fixture.hpp"

LayoutManager_Fixture::LayoutManager_Fixture() :
	test_rectFixture(),
	test_parentObject(new PositionObject(NULL, *test_rectFixture.test_rect1)),
	test_layoutManagerVector(create_layoutmanager_helper()),
	test_sizeFixture(),
	test_objectSizeFixture1(),
	test_objectSizeFixture2(),
	test_objectSizeFixture3(),
	test_objectSizeFixture4(),
	test_objectSizeFixture5(),
	test_objectSizeFixture6(),
	test_positionObjectVector(create_positionobject_helper())
{ }

LayoutManager_Fixture::~LayoutManager_Fixture() 
{ 
	delete test_parentObject;
	for(std::vector<PositionObject*>::iterator i = test_positionObjectVector.begin(); i != test_positionObjectVector.end(); i++) {
		delete *i;
	}
}

std::vector<boost::shared_ptr<LayoutManager> > LayoutManager_Fixture::create_layoutmanager_helper() const {
	std::vector<boost::shared_ptr<LayoutManager> > layoutmanager_vector;

	layoutmanager_vector.push_back(boost::shared_ptr<LayoutManager>(new LayoutManager(DOCK_TOP, *test_sizeFixture.test_size, HORIZONTAL_LAYOUT_TYPE)));
	layoutmanager_vector.push_back(boost::shared_ptr<LayoutManager>(new LayoutManager(DOCK_TOP_RIGHT, *test_sizeFixture.test_size, VERTICAL_LAYOUT_TYPE)));
	layoutmanager_vector.push_back(boost::shared_ptr<LayoutManager>(new LayoutManager(DOCK_BOTTOM_LEFT, *test_sizeFixture.test_size, GRID_TWO_COLUMNS_LAYOUT_TYPE)));
	layoutmanager_vector.push_back(boost::shared_ptr<LayoutManager>(new LayoutManager(DOCK_CENTER, *test_sizeFixture.test_size, GRID_TWO_LINES_LAYOUT_TYPE)));
	
	/*	DOCK_RIGHT,
	DOCK_BOTTOM_RIGHT,
	DOCK_BOTTOM,
	DOCK_LEFT,*/

	return layoutmanager_vector;
}

std::vector<PositionObject*> LayoutManager_Fixture::create_positionobject_helper() const {
	std::vector<PositionObject*> positionobject_vector;

	positionobject_vector.push_back(new PositionObject(test_parentObject, test_objectSizeFixture1.test_objectsize, test_layoutManagerVector[0]));
	positionobject_vector.push_back(new PositionObject(test_parentObject, test_objectSizeFixture2.test_objectsize, test_layoutManagerVector[0]));
	positionobject_vector.push_back(new PositionObject(test_parentObject, test_objectSizeFixture3.test_objectsize, test_layoutManagerVector[0]));
	positionobject_vector.push_back(new PositionObject(test_parentObject, test_objectSizeFixture4.test_objectsize, test_layoutManagerVector[0]));

	positionobject_vector.push_back(new PositionObject(test_parentObject, test_objectSizeFixture1.test_objectsize, test_layoutManagerVector[1]));
	positionobject_vector.push_back(new PositionObject(test_parentObject, test_objectSizeFixture2.test_objectsize, test_layoutManagerVector[1]));
	positionobject_vector.push_back(new PositionObject(test_parentObject, test_objectSizeFixture3.test_objectsize, test_layoutManagerVector[1]));
	positionobject_vector.push_back(new PositionObject(test_parentObject, test_objectSizeFixture4.test_objectsize, test_layoutManagerVector[1]));

	positionobject_vector.push_back(new PositionObject(test_parentObject, test_objectSizeFixture1.test_objectsize, test_layoutManagerVector[2]));
	positionobject_vector.push_back(new PositionObject(test_parentObject, test_objectSizeFixture2.test_objectsize, test_layoutManagerVector[2]));
	positionobject_vector.push_back(new PositionObject(test_parentObject, test_objectSizeFixture3.test_objectsize, test_layoutManagerVector[2]));
	positionobject_vector.push_back(new PositionObject(test_parentObject, test_objectSizeFixture4.test_objectsize, test_layoutManagerVector[2]));
	positionobject_vector.push_back(new PositionObject(test_parentObject, test_objectSizeFixture5.test_objectsize, test_layoutManagerVector[2]));
	positionobject_vector.push_back(new PositionObject(test_parentObject, test_objectSizeFixture6.test_objectsize, test_layoutManagerVector[2]));

	positionobject_vector.push_back(new PositionObject(test_parentObject, test_objectSizeFixture1.test_objectsize, test_layoutManagerVector[3]));
	positionobject_vector.push_back(new PositionObject(test_parentObject, test_objectSizeFixture2.test_objectsize, test_layoutManagerVector[3]));
	positionobject_vector.push_back(new PositionObject(test_parentObject, test_objectSizeFixture3.test_objectsize, test_layoutManagerVector[3]));
	positionobject_vector.push_back(new PositionObject(test_parentObject, test_objectSizeFixture4.test_objectsize, test_layoutManagerVector[3]));
	positionobject_vector.push_back(new PositionObject(test_parentObject, test_objectSizeFixture5.test_objectsize, test_layoutManagerVector[3]));
	positionobject_vector.push_back(new PositionObject(test_parentObject, test_objectSizeFixture6.test_objectsize, test_layoutManagerVector[3]));

	return positionobject_vector;
}