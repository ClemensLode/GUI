#ifndef _GEOMETRY_FIXTURE_LAYOUMANAGERTFIXTURE_HPP
#define _GEOMETRY_FIXTURE_LAYOUMANAGERTFIXTURE_HPP

#pragma warning(push, 0)  
#include <boost/shared_ptr.hpp>
#pragma warning(pop)

#include <geometry/enums/docktype.hpp>
#include <geometry/enums/layouttype.hpp>
#include <geometry/positionobject.hpp>
#include <geometry/layoutmanager.hpp>
#include "objectsize_fixture.hpp"
#include "rect_fixture.hpp"
#include "size_fixture.hpp"

struct LayoutManager_Fixture
{
	Rect_Fixture test_rectFixture;
	PositionObject* test_parentObject;
	Size_Fixture test_sizeFixture;
	std::vector<boost::shared_ptr<LayoutManager> > test_layoutManagerVector;
	ObjectSize_Fixture test_objectSizeFixture1;
	ObjectSize_Fixture test_objectSizeFixture2;
	ObjectSize_Fixture test_objectSizeFixture3;
	ObjectSize_Fixture test_objectSizeFixture4;
	ObjectSize_Fixture test_objectSizeFixture5;
	ObjectSize_Fixture test_objectSizeFixture6;

	std::vector<PositionObject*> test_positionObjectVector;	

	LayoutManager_Fixture();
	virtual ~LayoutManager_Fixture();

private:
	std::vector<boost::shared_ptr<LayoutManager> > create_layoutmanager_helper() const;
	std::vector<PositionObject*> create_positionobject_helper() const;
};

#endif // _GEOMETRY_FIXTURE_LAYOUMANAGERTFIXTURE_HPP