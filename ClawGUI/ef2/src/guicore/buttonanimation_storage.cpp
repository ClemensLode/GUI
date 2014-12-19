#include "buttonanimation_storage.hpp"
#include "buttonanimation.hpp"

#include <misc/miscellaneous.hpp>
#include <misc/io.hpp>

#include "brush_storage.hpp"
#include "color_storage.hpp"
#include "pen_storage.hpp"
#include "bitmap_storage.hpp"

template<> const std::string SingleStorage<ButtonAnimation>::DATA_FILE_NAME_BASE = IO::getDirectory(boost::assign::list_of("data")("storage")("guicore")) + "buttonanimation.xml";
template<> const std::string SingleStorage<ButtonAnimation>::DATA_FILE_IDENTIFIER = "ButtonAnimationStorage";

template<> boost::shared_ptr<ButtonAnimation> NodeCreator<ButtonAnimation>::createObjectFromNode(const std::vector<XmlNode>& node) {
	std::string id;
	std::string startBrushID;
	std::string endBrushID;
	std::string startTextColorID;
	std::string endTextColorID;
	std::string startBorderPenID;
	std::string endBorderPenID;
	std::string bitmapID;

	for(std::vector<XmlNode>::const_iterator i = node.begin(); i != node.end(); i++) {
		if(i->getName() == ButtonAnimationStorage::id_string) {
			id = i->getValue();
		} else if(i->getName() == ButtonAnimationStorage::startBrushID_string) {
			startBrushID = i->getValue();
		} else if(i->getName() == ButtonAnimationStorage::endBrushID_string) {
			endBrushID = i->getValue();
		} else if(i->getName() == ButtonAnimationStorage::startTextColorID_string) {
			startTextColorID = i->getValue();
		} else if(i->getName() == ButtonAnimationStorage::endTextColorID_string) {
			endTextColorID = i->getValue();
		} else if(i->getName() == ButtonAnimationStorage::startBorderPenID_string) {
			startBorderPenID = i->getValue();
		} else if(i->getName() == ButtonAnimationStorage::endBorderPenID_string) {
			endBorderPenID = i->getValue();
		} else if(i->getName() == ButtonAnimationStorage::bitmapID_string) {
			bitmapID = i->getValue();
		}
	}

	return boost::shared_ptr<ButtonAnimation>(new ButtonAnimation(Misc::uuid(id),
		BrushStorage::instance().get(startBrushID),
		BrushStorage::instance().get(endBrushID),
		ColorStorage::instance().get(startTextColorID),
		ColorStorage::instance().get(endTextColorID),
		PenStorage::instance().get(startBorderPenID),
		PenStorage::instance().get(endBorderPenID),
		BitmapStorage::instance().get(bitmapID)));
}

template<> XmlNode NodeCreator<ButtonAnimation>::createNodeFromObject(const ButtonAnimation& t) {
	XmlNode n(ButtonAnimationStorage::node_string);
	n.addChild(XmlNode(ButtonAnimationStorage::id_string, boost::lexical_cast<std::string>(t.getId())));
	n.addChild(XmlNode(ButtonAnimationStorage::startBrushID_string, boost::lexical_cast<std::string>(t.getStartBrush()->getId())));
	n.addChild(XmlNode(ButtonAnimationStorage::endBrushID_string, boost::lexical_cast<std::string>(t.getEndBrush()->getId())));
	n.addChild(XmlNode(ButtonAnimationStorage::startTextColorID_string, boost::lexical_cast<std::string>(t.getStartTextColor()->getId())));
	n.addChild(XmlNode(ButtonAnimationStorage::endTextColorID_string, boost::lexical_cast<std::string>(t.getEndTextColor()->getId())));
	n.addChild(XmlNode(ButtonAnimationStorage::startBorderPenID_string, boost::lexical_cast<std::string>(t.getStartBorderPen()->getId())));
	n.addChild(XmlNode(ButtonAnimationStorage::endBorderPenID_string, boost::lexical_cast<std::string>(t.getEndBorderPen()->getId())));
	n.addChild(XmlNode(ButtonAnimationStorage::bitmapID_string, boost::lexical_cast<std::string>(t.getBitmap()->getId())));
	return n;
}


const std::string ButtonAnimationStorage::node_string = "buttonAnimation";
const std::string ButtonAnimationStorage::id_string = "id";
const std::string ButtonAnimationStorage::startBrushID_string = "startBrushID";
const std::string ButtonAnimationStorage::endBrushID_string = "endBrushID";
const std::string ButtonAnimationStorage::startTextColorID_string = "startTextColorID";
const std::string ButtonAnimationStorage::endTextColorID_string = "endTextColorID";
const std::string ButtonAnimationStorage::startBorderPenID_string = "startBorderPenID";
const std::string ButtonAnimationStorage::endBorderPenID_string = "endBorderPenID";
const std::string ButtonAnimationStorage::bitmapID_string = "bitmapID";
