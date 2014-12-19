#ifndef _GEOMETRY_POSITIONOBJECT_HPP
#define _GEOMETRY_POSITIONOBJECT_HPP

#include <misc/objectnode.hpp>
#include "objectsize.hpp"
#include "rect.hpp"

class LayoutManager;

class PositionObject : public ObjectNode
{
public:		
	PositionObject(ObjectNode* parent,
		const Rect& relative_rect = Rect());

	PositionObject(ObjectNode* parent,
		const boost::shared_ptr<const ObjectSize> objectSize,
		const boost::shared_ptr<LayoutManager> layoutManager);

	PositionObject(const boost::uuids::uuid id, 
		ObjectNode* parent,
		const boost::shared_ptr<const ObjectSize> objectSize,
		const boost::shared_ptr<LayoutManager> layoutManager);

	~PositionObject();



	const Point& getRelativePosition() const;	
	const Size& getSize() const;
	Sint16 getRelativeUpperBound() const;
	Sint16 getRelativeLowerBound() const;
	Sint16 getRelativeLeftBound() const;
	Sint16 getRelativeRightBound() const;
	Uint16 getHeight() const;
	Uint16 getWidth() const;
	const Rect& getRelativeRect() const;

	Uint16 getTargetWidth() const;
	Uint16 getTargetHeight() const;
	const Size& getTargetSize() const;
	const Point getTargetPosition() const;
	const Rect& getTargetRect() const;
	void setTargetRect(const Rect& rect);
	

	const Point getAbsolutePosition() const;	
	const Point getParentAbsolutePosition() const;		
	const Rect getAbsoluteRect() const;		
	Sint16 getAbsoluteUpperBound() const;				
	Sint16 getAbsoluteLowerBound() const;	
	Sint16 getAbsoluteLeftBound() const;	
	Sint16 getAbsoluteRightBound() const;

	bool wasMoved() const;
	bool wasResized() const;

	bool isMoving() const;

	void setPosition(const Point& position);
	void setPosition(const Sint16 x, const Sint16 y);
	void setTargetPosition(const Point& position);
	void setTargetPosition(const Sint16 x, const Sint16 y);
	void setTargetSize(const Size& size);
	void setTargetLeft(const Sint16 x);
	void setTargetTop(const Sint16 y);
	void setSize(const Size& size);
	void setWidth(const Uint16 width);
	void setHeight(const Uint16 height);
	void setSize(const Uint16 width, const Uint16 height);

	static bool setSmoothMovements(const bool smooth);
	static bool isSmoothMovements();

	void adjustAfterParentChange();
	void adjustAfterChildChange(const Size& size);

	void move();
	// called from layout manager
	void updateMaxSize(const Size& maxSize);

	// called from object size (resolution change)
	void updateObjectSize(const Size& size);

protected:
	static bool smoothMovements;

	Rect relativeRect; // every object needs a current position and size, position is >> RELATIVE << to parent!
	Rect startRect;
	Rect targetRect;

	Size maxSize; // is set from outside by the layoutmanager

	// this is to check whether the size/position has changed since the last call
	Rect oldRect;

	// called by SDL_Object if oldRect.size != size
	void signalSizeChange();

private:
	const boost::shared_ptr<const ObjectSize> objectSize;
	const boost::shared_ptr<LayoutManager> layoutManager;

	bool moved;
	bool resized;

	void setLeft(const Sint16 x);
	void setTop(const Sint16 y);

	boost::signals::connection objectSizeSubscriber;
};

inline bool PositionObject::wasResized() const {
	return resized;
}

inline bool PositionObject::wasMoved() const {
	return moved;
}

inline const Point& PositionObject::getRelativePosition() const {
	return relativeRect.getTopLeft();
}			

inline const Size& PositionObject::getSize() const {
	return relativeRect.getSize();
}

inline Sint16 PositionObject::getRelativeUpperBound() const {
	return relativeRect.getTop();
}

inline Sint16 PositionObject::getRelativeLowerBound() const {
	return relativeRect.getBottom();
}

inline Sint16 PositionObject::getRelativeLeftBound() const {
	return relativeRect.getLeft();
}

inline Sint16 PositionObject::getRelativeRightBound() const {
	return relativeRect.getRight();
}

inline Uint16 PositionObject::getHeight() const {
	return relativeRect.getHeight();
}

inline Uint16 PositionObject::getWidth() const {
	return relativeRect.getWidth();
}

inline const Rect& PositionObject::getRelativeRect() const {
	return relativeRect;
}

inline Uint16 PositionObject::getTargetWidth() const {
	return targetRect.getWidth();
}

inline Uint16 PositionObject::getTargetHeight() const {
	return targetRect.getHeight();
}

inline const Point PositionObject::getTargetPosition() const {
	return targetRect.getTopLeft();
}

inline const Rect& PositionObject::getTargetRect() const {
	return targetRect;
}


inline const Size& PositionObject::getTargetSize() const {
	return targetRect.getSize();
}

inline void PositionObject::setPosition(const Sint16 x, const Sint16 y) {
	setPosition(Point(x, y));
}

inline void PositionObject::setSize(const Uint16 width, const Uint16 height) {
	setSize(Size(width, height));
}

// -------- BEGIN COORDINATES --------

inline void PositionObject::setPosition(const Point& position)
{
	if(position != relativeRect.getTopLeft()) {
		startRect.setTopLeft(position);
		targetRect.setTopLeft(position);
		relativeRect.setTopLeft(position);
	}
}

inline void PositionObject::setTargetPosition(const Sint16 x, const Sint16 y) {
	setTargetPosition(Point(x, y));
}

inline void PositionObject::setTargetLeft(const Sint16 x) {
	setTargetPosition(x, targetRect.getTop());
}

inline void PositionObject::setTargetTop(const Sint16 y) {
	setTargetPosition(targetRect.getLeft(), y);
}


inline void PositionObject::setHeight(const Uint16 height) 
{
	if(getTargetHeight() != height) {
		relativeRect.setHeight(height);
		startRect.setHeight(height);
		targetRect.setHeight(height);
	}
}

inline void PositionObject::setWidth(const Uint16 width) 
{
	if(relativeRect.getWidth() != width) {
		relativeRect.setWidth(width);
		startRect.setWidth(width);
		targetRect.setWidth(width);
	}
}

inline void PositionObject::setSize(const Size& size)
{
	if(relativeRect.getSize() != size) {
		relativeRect.setSize(size);
		startRect.setSize(size);
		targetRect.setSize(size);
	}
}

inline void PositionObject::setLeft(const Sint16 x) 
{
	if(relativeRect.getLeft() != x) {
		relativeRect.setLeft(x);
		startRect.setLeft(x);
		targetRect.setLeft(x);
	}
}

inline void PositionObject::setTop(const Sint16 y) 
{
	if(relativeRect.getTop() != y) {
		relativeRect.setTop(y);
		startRect.setTop(y);
		targetRect.setTop(y);
	}
}

inline bool PositionObject::setSmoothMovements(const bool smooth) {
	if(smoothMovements == smooth) {
		return false;
	}
	smoothMovements = smooth;
	return true;
}

inline bool PositionObject::isSmoothMovements() {
	return smoothMovements;
}


// -------- END COORDINATES --------



inline const Point PositionObject::getAbsolutePosition() const {
	if(getPositionParent()) {
		return relativeRect.getTopLeft() + static_cast<PositionObject*>(getPositionParent())->getAbsolutePosition();
	} else {
		return relativeRect.getTopLeft();
	}
}

inline const Point PositionObject::getParentAbsolutePosition() const	{
	if(getPositionParent()) {
		return static_cast<PositionObject*>(getPositionParent())->getAbsolutePosition();
	} else { 
		return Point(0,0);
	}
}

inline const Rect PositionObject::getAbsoluteRect() const {
	if(getPositionParent()) {
		return Rect(relativeRect.getTopLeft() + static_cast<PositionObject*>(getPositionParent())->getAbsolutePosition(), getSize());
	} else {
		return relativeRect;
	}
}

inline Sint16 PositionObject::getAbsoluteUpperBound() const {
	if(getPositionParent()) {
		return static_cast<Sint16>(relativeRect.getTop() + static_cast<PositionObject*>(getPositionParent())->getAbsoluteUpperBound());
	} else {
		return relativeRect.getTop();
	}
}

inline Sint16 PositionObject::getAbsoluteLowerBound() const {
	if(getPositionParent()) {
		return static_cast<Sint16>(relativeRect.getBottom() + static_cast<PositionObject*>(getPositionParent())->getAbsoluteUpperBound());			
	} else {
		return relativeRect.getBottom();
	}
}

inline Sint16 PositionObject::getAbsoluteLeftBound() const {
	if(getPositionParent()) {
		return static_cast<Sint16>(relativeRect.getLeft() + (static_cast<PositionObject*>(getPositionParent()))->getAbsoluteLeftBound());			
	} else {
		return relativeRect.getLeft();
	}
}

inline Sint16 PositionObject::getAbsoluteRightBound() const {
	if(getPositionParent()) {
		return static_cast<Sint16>(relativeRect.getRight() + (static_cast<PositionObject*>(getPositionParent()))->getAbsoluteLeftBound());			
	} else {
		return relativeRect.getRight();
	}
}

// only for BO window... TODO
inline bool PositionObject::isMoving() const {
	return relativeRect.getLeft() != targetRect.getLeft();
}


#endif // _GEOMETRY_POSITIONOBJECT_HPP

