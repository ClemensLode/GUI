#ifndef _MISC_OBJECTNODE_HPP
#define _MISC_OBJECTNODE_HPP

#include <list>
#include "uuid.hpp"

class ObjectNode : public UUID<ObjectNode>
{
public:
	ObjectNode(const boost::uuids::uuid id, ObjectNode* parent);
	ObjectNode(ObjectNode* parent);
	virtual ~ObjectNode();

	void setParent(ObjectNode* const parent);
	static void removeRootObject(ObjectNode* const object);

	ObjectNode* getPrevBrother() const;
	ObjectNode* getParent() const; // TODO make const correctness!
	ObjectNode* getPositionParent() const; // TODO make const correctness!
	ObjectNode* getChildren() const;

	void setPositionParent(ObjectNode* const parent);
	ObjectNode* getNextBrother() const;
	void makeFirstChild();
	bool isTopItem() const;
	unsigned int getZ() const;
	virtual void setZ(const unsigned int zcoord);
	void setChildrenWereChanged(const bool changed = true);

	static const unsigned int Z_STEP;

protected:
	static std::list<ObjectNode*> rootObjectList;
	void removeFromFamily();
	bool wereChildrenChanged() const;
	void addChild(ObjectNode* const child);

private:
	ObjectNode* parent; // = NULL means that this is the screen (x=0/y=0)
	ObjectNode* children; // pointer to the head of the linked list of children
	ObjectNode* positionParent; // = NULL means that this is the screen (x=0/y=0)
	ObjectNode* prevBrother;
	ObjectNode* nextBrother; 	
	bool childrenWereChanged;
	unsigned int zCoordinate;
};

inline bool ObjectNode::wereChildrenChanged() const {
	return childrenWereChanged;
}

inline void ObjectNode::setChildrenWereChanged(const bool changed) {
	childrenWereChanged = changed;
}

inline ObjectNode* ObjectNode::getPrevBrother() const {
	return prevBrother;
}

inline ObjectNode* ObjectNode::getNextBrother() const {
	return nextBrother;
}

inline ObjectNode* ObjectNode::getParent() const {
	return parent;
}

inline ObjectNode* ObjectNode::getPositionParent() const {
	return positionParent;
}

inline ObjectNode* ObjectNode::getChildren() const {
	return children;
}

inline bool ObjectNode::isTopItem() const {
	return positionParent == NULL;
}

inline unsigned int ObjectNode::getZ() const {
	return zCoordinate;
}


#endif // _MISC_OBJECTNODE_HPP