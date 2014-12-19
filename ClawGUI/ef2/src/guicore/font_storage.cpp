#include "font_storage.hpp"
#include "font.hpp"

#include <misc/miscellaneous.hpp>
#include <misc/io.hpp>

template<> const std::string SingleStorage<Font>::DATA_FILE_NAME_BASE = IO::getDirectory(boost::assign::list_of("data")("storage")("guicore")) + "font.xml";
template<> const std::string SingleStorage<Font>::DATA_FILE_IDENTIFIER = "FontStorage";

template<> boost::shared_ptr<Font> NodeCreator<Font>::createObjectFromNode(const std::vector<XmlNode>& node) {
	return boost::shared_ptr<Font>(new Font(Misc::uuid(node[0]), node[1], boost::lexical_cast<Uint16>(node[2].getValue()), boost::lexical_cast<bool>(node[3].getValue()), boost::lexical_cast<bool>(node[4].getValue())));
}

template<> XmlNode NodeCreator<Font>::createNodeFromObject(const Font& t) {
	XmlNode n("font");
	n.addChild(XmlNode("id", boost::lexical_cast<std::string>(t.getId())));
	n.addChild(XmlNode("fileName", t.getFileName()));
	n.addChild(XmlNode("size", boost::lexical_cast<std::string>(t.getSize())));
	n.addChild(XmlNode("underlined", boost::lexical_cast<std::string>(t.isUnderlined())));
	n.addChild(XmlNode("shadow", boost::lexical_cast<std::string>(t.isShadow())));
	return n;
}