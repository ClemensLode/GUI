#include "objectsize_storage.hpp"
#include "objectsize.hpp"

#include <misc/miscellaneous.hpp>
#include <misc/io.hpp>
#include <misc/exceptions.hpp>

template<> const std::string SingleStorage<ObjectSize>::DATA_FILE_NAME_BASE = IO::getDirectory(boost::assign::list_of("data")("storage")("geometry")) + "objectsize.xml";
template<> const std::string SingleStorage<ObjectSize>::DATA_FILE_IDENTIFIER = "ObjectSizeStorage";

std::string getAutoSizeName(eAutoSize autoSize) {
	std::string autoSizeName = "";
	switch(autoSize) {
	case NO_AUTO_SIZE:autoSizeName = "NO_AUTO_SIZE";break;
	case CONST_SIZE:autoSizeName = "CONST_SIZE";break;
	case AUTO_PARENT_SIZE:autoSizeName = "AUTO_PARENT_SIZE";break;
	case AUTO_CHILD_SIZE:autoSizeName = "AUTO_CHILD_SIZE";break;
	case MAX_AUTO_SIZES:
	default:
		throw FileException("Auto size type (" + boost::lexical_cast<std::string>(autoSize) + ") is out of range, " + SingleStorage<ObjectSize>::DATA_FILE_NAME_BASE + ")");
		break;
	}
	return autoSizeName;
}

eAutoSize getAutoSizeType(std::string autoSizeValue)
{
	eAutoSize autoSize;

	if(autoSizeValue == "NO_AUTO_SIZE") {
		autoSize = NO_AUTO_SIZE;
	} else 
	if(autoSizeValue == "CONST_SIZE") {
		autoSize = CONST_SIZE;
	} else 
	if(autoSizeValue == "AUTO_PARENT_SIZE") {
		autoSize = AUTO_PARENT_SIZE;
	} else 
	if(autoSizeValue == "AUTO_CHILD_SIZE") {
		autoSize = AUTO_CHILD_SIZE;
	} else {
		throw FileException("Error creating object size from node (" + autoSizeValue + " is unknown auto size, see " + SingleStorage<ObjectSize>::DATA_FILE_NAME_BASE + ")");
	}

	return autoSize;
}

template<> boost::shared_ptr<ObjectSize> NodeCreator<ObjectSize>::createObjectFromNode(const std::vector<XmlNode>& node) {
	std::map<const boost::uuids::uuid, const Size> objectSizeMap;

	eAutoSize horizontalAutoSize = getAutoSizeType(node[1].getValue());
	eAutoSize verticalAutoSize = getAutoSizeType(node[2].getValue());

	for(std::vector<XmlNode>::const_iterator i = node[3].getChildren().begin(); i != node[3].getChildren().end(); i++) {
		Size size(static_cast<Uint16>(boost::lexical_cast<unsigned int>(i->getChildren()[1].getValue())), static_cast<Uint16>(boost::lexical_cast<unsigned int>(i->getChildren()[2].getValue())));
		objectSizeMap.insert(std::pair<const boost::uuids::uuid, const Size>(Misc::uuid(i->getChildren()[0]), size));
	}

	return boost::shared_ptr<ObjectSize>(new ObjectSize(Misc::uuid(node[0]), objectSizeMap, horizontalAutoSize, verticalAutoSize));	
}

template<> XmlNode NodeCreator<ObjectSize>::createNodeFromObject(const ObjectSize& t) {
	XmlNode n("objectsize");

	n.addChild(XmlNode("id", boost::lexical_cast<std::string>(t.getId())));
	n.addChild(XmlNode("autoSizeHorizontal", getAutoSizeName(t.getHorizontalAutoSizeType())));
	n.addChild(XmlNode("autoSizeVertical", getAutoSizeName(t.getVerticalAutoSizeType())));

	XmlNode objectSizeMap("objectSizeMap");
	for(std::map<const boost::uuids::uuid, const Size>::const_iterator i = t.getSizeMap().begin(); i != t.getSizeMap().end(); i++) {
		XmlNode entry("entry");
		entry.addChild(XmlNode("resolutionId", boost::lexical_cast<std::string>(i->first)));
		entry.addChild(XmlNode("width", boost::lexical_cast<std::string>(i->second.getWidth())));
		entry.addChild(XmlNode("height", boost::lexical_cast<std::string>(i->second.getHeight())));
		objectSizeMap.addChild(entry);
	}
	n.addChild(objectSizeMap);
	
	return n;
}


void ObjectSizeStorage::updateResolution(const boost::uuids::uuid resolutionId) {
	for(std::map<const boost::uuids::uuid, const boost::shared_ptr<const ObjectSize> >::const_iterator i = instance().getItemMap().begin(); i != instance().getItemMap().end(); i++) {
		i->second->updateResolution(resolutionId);
	}
	currentResolutionId = resolutionId;
}

boost::uuids::uuid ObjectSizeStorage::currentResolutionId;