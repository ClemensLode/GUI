#include "buttoncolors_storage.hpp"
#include "buttoncolors.hpp"

#include <misc/io.hpp>

#include "buttonanimation_storage.hpp"
#include "font_storage.hpp"

template<> const std::string SingleStorage<ButtonColors>::DATA_FILE_NAME_BASE = IO::getDirectory(boost::assign::list_of("data")("storage")("guicore")) + "buttoncolors.xml";
template<> const std::string SingleStorage<ButtonColors>::DATA_FILE_IDENTIFIER = "ButtonColorsStorage";

template<> boost::shared_ptr<ButtonColors> NodeCreator<ButtonColors>::createObjectFromNode(const std::vector<XmlNode>& node) {
	std::vector<boost::shared_ptr<const ButtonAnimation> > buttonAnimationVector;
	for(std::vector<XmlNode>::const_iterator i = node[4].getChildren().begin(); i != node[4].getChildren().end(); i++) {
		buttonAnimationVector.push_back(ButtonAnimationStorage::instance().get(i->getValue())); // TODO?
	}
	return boost::shared_ptr<ButtonColors>(new ButtonColors(Misc::uuid(node[0]), FontStorage::instance().get(node[1]), boost::lexical_cast<unsigned int>(node[2].getValue()), static_cast<eButtonAnimationType>(boost::lexical_cast<unsigned int>(node[3].getValue())), buttonAnimationVector));
}

template<> XmlNode NodeCreator<ButtonColors>::createNodeFromObject(const ButtonColors& t) {
	XmlNode n("buttonColors");
	n.addChild(XmlNode("id", boost::lexical_cast<std::string>(t.getId())));
	n.addChild(XmlNode("fontID", boost::lexical_cast<std::string>(t.getFont()->getId())));
	n.addChild(XmlNode("speed", boost::lexical_cast<std::string>(t.getSpeed())));
	n.addChild(XmlNode("animationType",  boost::lexical_cast<std::string>(t.getAnimationType())));
	XmlNode buttonAnimationIdList("buttonAnimationIDs");
	for(std::vector<boost::shared_ptr<const ButtonAnimation> >::const_iterator i = t.getButtonAnimationVector().begin(); i != t.getButtonAnimationVector().end(); i++) {
		buttonAnimationIdList.addChild(XmlNode("id", boost::lexical_cast<std::string>((*i)->getId())));
	}
	n.addChild(buttonAnimationIdList);
	return n;
}