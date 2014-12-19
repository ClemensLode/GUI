#include "text_storage.hpp"
#include <lang/text.hpp>

#include <misc/miscellaneous.hpp>
#include <misc/io.hpp>

template<> const std::string SingleStorage<Text>::DATA_FILE_NAME_BASE = IO::getDirectory(boost::assign::list_of("data")("storage")("lang")) + "text.xml";
template<> const std::string SingleStorage<Text>::DATA_FILE_IDENTIFIER = "TextStorage";

template<> boost::shared_ptr<Text> NodeCreator<Text>::createObjectFromNode(const std::vector<XmlNode>& node) {
	std::map<const boost::uuids::uuid, const std::string> textMap;
	
	for(std::vector<XmlNode>::const_iterator i = node[1].getChildren().begin(); i != node[1].getChildren().end(); i++) {
		textMap.insert(std::pair<const boost::uuids::uuid, const std::string>(Misc::uuid(i->getChildren()[0]), i->getChildren()[1]));
	}

	return boost::shared_ptr<Text>(new Text(Misc::uuid(node[0]), textMap));
}

template<> XmlNode NodeCreator<Text>::createNodeFromObject(const Text& t) {
	XmlNode n("text");
	n.addChild(XmlNode("id", boost::lexical_cast<std::string>(t.getId())));
	XmlNode textMap("textMap");
	for(std::map<const boost::uuids::uuid, const std::string>::const_iterator i = t.getTextMap().begin(); i != t.getTextMap().end(); i++) {
		XmlNode entry("entry");
		entry.addChild(XmlNode("id", boost::lexical_cast<std::string>(i->first)));
		entry.addChild(XmlNode("value", boost::lexical_cast<std::string>(i->second)));
		textMap.addChild(entry);
	}
	n.addChild(textMap);
	return n;
}


void TextStorage::updateLanguage(const boost::uuids::uuid languageId) {
	for(std::map<const boost::uuids::uuid, const boost::shared_ptr<const Text> >::const_iterator i = instance().getItemMap().begin(); i != instance().getItemMap().end(); i++) {
		i->second->updateLanguage(languageId);
	}
	currentLanguageId = languageId;
}

boost::uuids::uuid TextStorage::currentLanguageId;