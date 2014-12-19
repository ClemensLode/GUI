#ifndef _GEOMETRY_LAYOUTMANAGER_HPP
#define _GEOMETRY_LAYOUTMANAGER_HPP

#pragma warning(push, 0)  
#include <boost/uuid/uuid.hpp>
#pragma warning(pop)

#include <map>
#include <list>

#include "size.hpp"
#include "point.hpp"
#include "enums/docktype.hpp"
#include "enums/layouttype.hpp"

class PositionObject;

// TODO extends position object, overrride 'get width'
class LayoutManager
{
public:
	LayoutManager(const eDockType dockType = DOCK_TOP_LEFT, const Size padding = Size(), const eLayoutType layoutType = HORIZONTAL_LAYOUT_TYPE);
	~LayoutManager();

	void registerObject(PositionObject* object);
	void unregisterObject(const PositionObject* object);
	void unregisterAllObjects();
	void doLayout() const;

private:
	PositionObject* parentObject;
	
	const eDockType dockType;
	const Size padding;
	const eLayoutType layoutType;

	std::list<PositionObject*> positionObjectList;
};

#endif // _GEOMETRY_LAYOUTMANAGER_HPP