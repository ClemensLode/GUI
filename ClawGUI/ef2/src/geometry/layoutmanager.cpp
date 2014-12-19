#include "layoutmanager.hpp"

#include <misc/exceptions.hpp>
#include <vector>

#pragma warning(push, 0)  
#include <boost/lexical_cast.hpp>
#pragma warning(pop)

#include "positionobject.hpp"

LayoutManager::LayoutManager(const eDockType dockType, const Size padding, const eLayoutType layoutType):
parentObject(NULL),	
	dockType(dockType),
	padding(padding),
	layoutType(layoutType),
	positionObjectList()
{ }

LayoutManager::~LayoutManager()
{ }

void LayoutManager::registerObject(PositionObject* object) {
	positionObjectList.push_back(object);
	if(parentObject == NULL) {
		parentObject = static_cast<PositionObject*>(object->getParent());
	} else {
		BOOST_ASSERT(parentObject == object->getParent());
	}
	doLayout();
}

void LayoutManager::unregisterAllObjects() {
	positionObjectList.clear();
	parentObject = NULL;
}

void LayoutManager::unregisterObject(const PositionObject* object) {
	for(std::list<PositionObject*>::const_iterator i = positionObjectList.begin(); i != positionObjectList.end(); i++) {
		if((*i)->getId() == object->getId()) {
			positionObjectList.erase(i);
			doLayout();
			return;
		}
	}
	std::ostringstream os;
	os << "LayoutManager::unregisterObject(): Error unregistering the object, object with id " << object->getId() << " was not added to the layout manager.";
	throw GUIException(os.str());
}

void LayoutManager::doLayout() const 
{
	unsigned int totalWidth = 0;
	unsigned int totalHeight = 0;
	unsigned int size = (positionObjectList.size() + 1) / 2;
	std::vector<unsigned int> maxCellWidthColumnsList(2);
	std::vector<unsigned int> maxCellHeightColumnsList(size);
	std::vector<unsigned int> maxCellWidthRowsList(size);
	std::vector<unsigned int> maxCellHeightRowsList(2);
	unsigned int maxWidth = 0;
	unsigned int maxHeight = 0;

	int index = 0;

	for(std::list<PositionObject*>::const_iterator i = positionObjectList.begin(); i != positionObjectList.end(); i++) {
		totalHeight += (*i)->getTargetHeight();
		totalWidth += (*i)->getTargetWidth();
		if((*i)->getTargetWidth() > maxCellWidthColumnsList[index%2]) {
			maxCellWidthColumnsList[index%2] = (*i)->getTargetWidth();
		}
		if((*i)->getTargetWidth() > maxCellHeightColumnsList[index/2]) {
			maxCellHeightColumnsList[index/size] = (*i)->getTargetHeight();
		}
		if((*i)->getTargetWidth() > maxCellWidthRowsList[index%size]) {
			maxCellWidthRowsList[index%2] = (*i)->getTargetWidth();
		}
		if((*i)->getTargetWidth() > maxCellHeightRowsList[index/size]) {
			maxCellHeightRowsList[index/size] = (*i)->getTargetHeight();
		}
		if((*i)->getTargetWidth() > maxWidth) {
			maxWidth = (*i)->getTargetWidth();
		}
		if((*i)->getTargetHeight() > maxHeight) {
			maxHeight = (*i)->getTargetHeight();
		}

		index++;
	}		

	// calculate position of layout block:

	switch(layoutType) {
	case HORIZONTAL_LAYOUT_TYPE:
		totalHeight = maxHeight;
		break; 
	case VERTICAL_LAYOUT_TYPE:
		totalWidth = maxWidth;			
		break;
	case GRID_TWO_COLUMNS_LAYOUT_TYPE:
		totalWidth = 0;
		totalHeight = 0;
		for(std::vector<unsigned int>::const_iterator i = maxCellWidthColumnsList.begin(); i != maxCellWidthColumnsList.end(); i++) {
			totalWidth += *i;
		}
		for(std::vector<unsigned int>::const_iterator i = maxCellHeightColumnsList.begin(); i != maxCellHeightColumnsList.end(); i++) {
			totalHeight += *i;
		}			
		break;
	case GRID_TWO_LINES_LAYOUT_TYPE:
		totalWidth = 0;
		totalHeight = 0;
		for(std::vector<unsigned int>::const_iterator i = maxCellWidthRowsList.begin(); i != maxCellWidthRowsList.end(); i++) {
			totalWidth += *i;
		}
		for(std::vector<unsigned int>::const_iterator i = maxCellHeightRowsList.begin(); i != maxCellHeightRowsList.end(); i++) {
			totalHeight += *i;
		}
		break;
	case MAX_LAYOUT_TYPES:			
	default:
		std::ostringstream os;
		os << "LayoutManager::doLayout(): Error doing the layout, layout type invalid (" << static_cast<unsigned int>(layoutType) << ").";
		throw GUIException(os.str());
		break;
	}

	Point p;
	bool bottom = false;
	bool centerx = false;
	bool centery = false;
	bool right = false;

	switch(dockType) {
	case DOCK_TOP_LEFT:p = Point(padding.getWidth(), padding.getHeight());break;
	case DOCK_TOP:centerx = true; p = Point((parentObject->getWidth() - totalWidth)/2, padding.getHeight());break;
	case DOCK_TOP_RIGHT:right = true; p = Point(parentObject->getWidth() - totalWidth - padding.getWidth(), padding.getHeight());break;
	case DOCK_RIGHT:right = true; centery = true; p = Point(parentObject->getWidth() - totalWidth - padding.getWidth(), (parentObject->getHeight() - totalHeight)/2);break;
	case DOCK_BOTTOM_RIGHT:right = true; bottom = true; p = Point(parentObject->getWidth() - totalWidth - padding.getWidth(), parentObject->getHeight() - totalHeight - padding.getHeight());break;
	case DOCK_BOTTOM:bottom = true; centerx = true; p = Point((parentObject->getWidth() - totalWidth)/2, parentObject->getHeight() - totalHeight - padding.getHeight());break;
	case DOCK_BOTTOM_LEFT:bottom = true; p = Point(padding.getWidth(), parentObject->getHeight() - totalHeight - padding.getHeight());break;
	case DOCK_LEFT:centery = true; p = Point(padding.getWidth(), (parentObject->getHeight() - totalHeight)/2);break;
	case DOCK_CENTER:centerx = true; centery = true; p = Point((parentObject->getWidth() - totalWidth)/2, (parentObject->getHeight() - totalHeight)/2);break;
	case MAX_DOCKTYPES:
	default:
		std::ostringstream os;
		os << "LayoutManager::doLayout(): Error doing the layout, dock type invalid (" << static_cast<unsigned int>(dockType) << ").";
		throw GUIException(os.str());
		break;
	}

	int x = p.getX();
	int y = p.getY();
	index = 0;

	switch(layoutType) {
	case HORIZONTAL_LAYOUT_TYPE:
		for(std::list<PositionObject*>::const_iterator i = positionObjectList.begin(); i != positionObjectList.end(); i++) {
			if(bottom) {
				y += maxHeight - (*i)->getHeight();
			}
			if(bottom) {
				(*i)->setTargetPosition(Point(x, p.getY() + maxHeight - (*i)->getHeight()));
			} else if(centery) {
				(*i)->setTargetPosition(Point(x, p.getY() + (maxHeight - (*i)->getHeight()) / 2));
			} else {
				(*i)->setTargetPosition(Point(x, p.getY()));
			}
			x += (*i)->getWidth();
		}
		break; 
	case VERTICAL_LAYOUT_TYPE:
		for(std::list<PositionObject*>::const_iterator i = positionObjectList.begin(); i != positionObjectList.end(); i++) {
			if(right) {
				(*i)->setTargetPosition(Point(p.getX() + maxWidth - (*i)->getWidth(), y));
			} else if(centerx) {
				(*i)->setTargetPosition(Point(p.getX() + (maxWidth - (*i)->getWidth()) / 2, y));
			} else {
				(*i)->setTargetPosition(Point(p.getX(), y));
			}
			y += (*i)->getHeight();
		}		
		break;
	case GRID_TWO_COLUMNS_LAYOUT_TYPE:
		for(std::list<PositionObject*>::const_iterator i = positionObjectList.begin(); i != positionObjectList.end(); i++) {
			(*i)->setTargetPosition(Point(x, y));

			index++;
			if(index%2 == 0) {
				x = p.getX();
				if(index/size < maxCellHeightColumnsList.size()) {
					y += maxCellHeightColumnsList[index/size];
				}
			} else {
				x += maxCellWidthColumnsList[0];
			}				
		}
		break;
	case GRID_TWO_LINES_LAYOUT_TYPE:
		for(std::list<PositionObject*>::const_iterator i = positionObjectList.begin(); i != positionObjectList.end(); i++) {
			(*i)->setTargetPosition(Point(x, y));

			index++;
			if(size < 2) {
				break;
			}

			if(index%(size/2) == 0) {
				x = p.getX();
				y+= maxCellHeightRowsList[0];
			} else {
				if((index-1)%(size/2) < maxCellWidthRowsList.size()) {
					x += maxCellWidthRowsList[(index-1)%(size/2)];
				}
			}				
		}
		break;
	case MAX_LAYOUT_TYPES:			
	default:
		std::ostringstream os;
		os << "LayoutManager::doLayout(): Error doing the layout, layout type invalid (" << static_cast<unsigned int>(layoutType) << ").";
		throw GUIException(os.str());
		break;		

	}
}

