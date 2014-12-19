#include "positionobject.hpp"

#include <misc/log.hpp>

#pragma warning(push, 0)
#include <boost/assert.hpp>
#pragma warning(pop)

#include "layoutmanager.hpp"
#include <misc/exceptions.hpp>

#pragma warning(push, 0)  
#include <boost/signals.hpp>
#include <boost/bind.hpp>
#include <boost/bind/placeholders.hpp>
#pragma warning(pop)

PositionObject::PositionObject(ObjectNode* parent, const Rect& relativeRect) :
ObjectNode(parent),
	objectSize(boost::shared_ptr<const ObjectSize>()),
	layoutManager(boost::shared_ptr<LayoutManager>()),
	relativeRect(relativeRect),
	startRect(relativeRect),
	targetRect(relativeRect),
	oldRect(relativeRect),
	maxSize(relativeRect.getSize()),
	moved(false),
	resized(false),
	objectSizeSubscriber()
{ }

PositionObject::PositionObject(ObjectNode* parent, const boost::shared_ptr<const ObjectSize> objectSize, const boost::shared_ptr<LayoutManager> layoutManager) :
ObjectNode(parent),
	objectSize(objectSize),
	layoutManager(layoutManager),
	// call update resolution at the beginning
	// call layout manager at the very beginning
	relativeRect(Rect(Point(), objectSize->getSize())),
	startRect(relativeRect),
	targetRect(relativeRect),
	oldRect(relativeRect),
	maxSize(relativeRect.getSize()),
	moved(false),
	resized(false),
	objectSizeSubscriber(objectSize->connect(boost::bind(&PositionObject::updateObjectSize, this, _1)))
{ 
	layoutManager->registerObject(this);
}

PositionObject::PositionObject(const boost::uuids::uuid id, ObjectNode* parent, const boost::shared_ptr<const ObjectSize> objectSize, const boost::shared_ptr<LayoutManager> layoutManager) :
ObjectNode(id, parent),
	objectSize(objectSize),
	layoutManager(layoutManager),
	// call update resolution at the beginning
	// call layout manager at the very beginning
	relativeRect(Rect(Point(), objectSize->getSize())),
	startRect(relativeRect),
	targetRect(relativeRect),
	oldRect(relativeRect),
	maxSize(relativeRect.getSize()),
	moved(false),
	resized(false),
	objectSizeSubscriber(objectSize->connect(boost::bind(&PositionObject::updateObjectSize, this, _1)))
{ 
	layoutManager->registerObject(this);
}

PositionObject::~PositionObject()
{
	if(objectSizeSubscriber.connected()) {
		objectSizeSubscriber.disconnect();
	}
}


void PositionObject::updateObjectSize(const Size& size) {
	if(maxSize.getWidth() < size.getWidth()) {
		maxSize.setWidth(size.getWidth());
	}
	if(maxSize.getHeight() < size.getHeight()) {
		maxSize.setHeight(size.getHeight());
	}
	setTargetSize(size);
}


void PositionObject::updateMaxSize(const Size& maxSize) {
	this->maxSize = maxSize;
	// check if current target size is larger than max size
	setTargetSize(getTargetSize());
}

void PositionObject::setTargetRect(const Rect& rect)
{
	if(rect != targetRect)
	{
		setTargetPosition(rect.getTopLeft());
		setTargetSize(rect.getSize());
	}
}


void PositionObject::setTargetPosition(const Point &position) {
	targetRect.setTopLeft(position);
	Sint16 x = getRelativePosition().getX();
	Sint16 y = getRelativePosition().getY();

	if(!((x >= startRect.getLeft() && x <= targetRect.getLeft()) || (x <= startRect.getLeft() && x >= targetRect.getLeft()) )) {
		startRect.setLeft(x);
	}
	if(!((y >= startRect.getTop() && y <= targetRect.getTop()) || (y <= startRect.getTop() && y >= targetRect.getTop()) )) {
		startRect.setTop(y);
	}
}

void PositionObject::setTargetSize(const Size& size) {

	Size s = size;
	
	if(size.getWidth() > maxSize.getWidth()) {
		s.setWidth(maxSize.getWidth());
	}
	
	if(size.getHeight() > maxSize.getHeight()) {
		s.setHeight(maxSize.getHeight());
	}

	targetRect.setSize(s);
	Uint16 w = this->getWidth();
	Uint16 h = this->getHeight();

	if(!((w >= startRect.getWidth() && w <= targetRect.getWidth()) || (w <= startRect.getWidth() && w >= targetRect.getWidth()) )) {
		startRect.setWidth(w);
	}
	if(!((h >= startRect.getHeight() && h <= targetRect.getHeight()) || (h <= startRect.getHeight() && h >= targetRect.getHeight()) )) {
		startRect.setHeight(h);
	}
}

void PositionObject::move() {

	if(PositionObject::smoothMovements) {
		relativeRect.moveSmooth(startRect, targetRect);

		if(relativeRect.getTopLeft() == targetRect.getTopLeft()) {
			startRect.setTopLeft(relativeRect.getTopLeft());
		}
		if(relativeRect.getSize() == targetRect.getSize()) {
			startRect.setSize(relativeRect.getSize());
		}
	} else {
		relativeRect = targetRect;
		startRect = relativeRect;
	}

	moved = false;
	resized = false;

	if(oldRect.getTopLeft() != getAbsolutePosition()) {
		moved = true;
	}

	if(oldRect.getSize() != getSize()) {
		resized = true;
	}

}






// called by PARENT after PARENT's size was changed
void PositionObject::adjustAfterParentChange() {

	PositionObject* parentObject = static_cast<PositionObject*>(getParent());

	Uint16 full_width = 0;
	if(parentObject != NULL) {
		full_width = parentObject->getWidth();
	}  else {
		full_width = getWidth();
	}

	Uint16 newTargetWidth = getTargetWidth();
	Uint16 newTargetHeight = getTargetHeight();

	switch(objectSize->getHorizontalAutoSizeType()) {

	case NO_AUTO_SIZE:break;
	case CONST_SIZE:newTargetWidth = objectSize->getWidth();break;
	case AUTO_PARENT_SIZE:newTargetWidth = objectSize->getWidth() * parentObject->getWidth() / 100;break;
	case AUTO_CHILD_SIZE:break;
	default:
		std::ostringstream os;
		os << "PositionObject::adjustAfterParentChange(): Invalid horizontal auto size type (" << static_cast<unsigned int>(objectSize->getHorizontalAutoSizeType()) << ").";
		throw GUIException(os.str());				
		break;
	}

	switch(objectSize->getVerticalAutoSizeType()) {

	case NO_AUTO_SIZE:break;
	case CONST_SIZE:newTargetHeight = objectSize->getHeight();break;
	case AUTO_PARENT_SIZE:newTargetHeight = objectSize->getHeight() * parentObject->getHeight() / 100;break;
	case AUTO_CHILD_SIZE:break;
	default:
		std::ostringstream os;
		os << "PositionObject::adjustAfterParentChange(): Invalid vertical auto size type (" << static_cast<unsigned int>(objectSize->getVerticalAutoSizeType()) << ").";
		throw GUIException(os.str());				
		break;
	}

	setTargetSize(Size(newTargetWidth, newTargetHeight));
}


void PositionObject::adjustAfterChildChange(const Size& size) {
	// TODO MAX OBJECT SIZE
	PositionObject* parentObject = static_cast<PositionObject*>(getParent());

	Uint16 full_width = 0;
	if(parentObject != NULL) {
		full_width = parentObject->getWidth();
	}  else {
		full_width = getWidth();
	}

	Uint16 newTargetWidth = getTargetWidth();
	Uint16 newTargetHeight = getTargetHeight();

	switch(objectSize->getHorizontalAutoSizeType()) {
	case NO_AUTO_SIZE:break;
	case CONST_SIZE:newTargetWidth = objectSize->getWidth();break; // TODO?
	case AUTO_PARENT_SIZE:break;
	case AUTO_CHILD_SIZE:newTargetWidth = objectSize->getWidth() * size.getWidth() / 100;break;
	default:
		std::ostringstream os;
		os << "PositionObject::adjustAfterChildChange(): Invalid horizontal auto size type (" << static_cast<unsigned int>(objectSize->getHorizontalAutoSizeType()) << ").";
		throw GUIException(os.str());				
		break;
	}

	switch(objectSize->getVerticalAutoSizeType()) {
	case NO_AUTO_SIZE:break;
	case CONST_SIZE:newTargetHeight = objectSize->getHeight();break;
	case AUTO_PARENT_SIZE:break;
	case AUTO_CHILD_SIZE:newTargetHeight = objectSize->getHeight() * size.getHeight() / 100;break;
	default:
		std::ostringstream os;
		os << "PositionObject::adjustAfterChildChange(): Invalid vertical auto size type (" << static_cast<unsigned int>(objectSize->getVerticalAutoSizeType()) << ").";
		throw GUIException(os.str());				
		break;
	}

	setTargetSize(Size(newTargetWidth, newTargetHeight));
}


void PositionObject::signalSizeChange() {
	PositionObject* temp_parent = static_cast<PositionObject*>(getParent());
	if(layoutManager != NULL) {
		layoutManager->doLayout();
	}
	
	// signal parent that the size of the child (this object) has changed
	if(temp_parent) {
		temp_parent->adjustAfterChildChange(getSize());
	}

	// signal children that the size of their parent (this object) has changed
	ObjectNode* tmp = getChildren();  // process all children of gadget
	if (tmp) {
		do {
			static_cast<PositionObject*>(tmp)->adjustAfterParentChange();
			tmp = tmp->getNextBrother();
		} while (tmp != getChildren());
	}
}

bool PositionObject::smoothMovements = false;