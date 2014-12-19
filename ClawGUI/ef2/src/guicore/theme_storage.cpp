#include "theme_storage.hpp"
#include "theme.hpp"

#include <misc/miscellaneous.hpp>
#include <misc/io.hpp>
#include "color_storage.hpp"

template<> const std::string SingleStorage<Theme>::DATA_FILE_NAME_BASE = IO::getDirectory(boost::assign::list_of("data")("storage")("guicore")) + "theme.xml";
template<> const std::string SingleStorage<Theme>::DATA_FILE_IDENTIFIER = "ThemeStorage";

template<> boost::shared_ptr<Theme> NodeCreator<Theme>::createObjectFromNode(const std::vector<XmlNode>& node) {
	return boost::shared_ptr<Theme>(new Theme(Misc::uuid(node[0]), node[1].getValue(), ColorStorage::instance().get(node[2]), ColorStorage::instance().get(node[3])));
}

template<> XmlNode NodeCreator<Theme>::createNodeFromObject(const Theme& t) {
	XmlNode n("theme");
	n.addChild(XmlNode("id", boost::lexical_cast<std::string>(t.getId())));
	n.addChild(XmlNode("name", t.getName()));
	n.addChild(XmlNode("primaryColorID", boost::lexical_cast<std::string>(t.getPrimaryColor()->getId())));
	n.addChild(XmlNode("secondaryColorID", boost::lexical_cast<std::string>(t.getSecondaryColor()->getId())));
	return n;
}