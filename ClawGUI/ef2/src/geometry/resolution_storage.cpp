#include "resolution_storage.hpp"
#include "resolution.hpp"

#include <misc/miscellaneous.hpp>
#include <misc/io.hpp>

template<> const std::string SingleStorage<Resolution>::DATA_FILE_NAME_BASE = IO::getDirectory(boost::assign::list_of("data")("storage")("geometry")) + "resolution.xml";
template<> const std::string SingleStorage<Resolution>::DATA_FILE_IDENTIFIER = "ResolutionStorage";

template<> boost::shared_ptr<Resolution> NodeCreator<Resolution>::createObjectFromNode(const std::vector<XmlNode>& node) {
	return boost::shared_ptr<Resolution>(new Resolution(Misc::uuid(node[0]), node[1].getValue(), Size(boost::lexical_cast<Uint16>(node[2].getValue()), boost::lexical_cast<Uint16>(node[3].getValue()))));
}

template<> XmlNode NodeCreator<Resolution>::createNodeFromObject(const Resolution& t) {
	XmlNode n("resolution");
	n.addChild(XmlNode("id", boost::lexical_cast<std::string>(t.getId())));
	n.addChild(XmlNode("name", t.getName()));
	n.addChild(XmlNode("width", boost::lexical_cast<std::string>(t.getSize().getWidth())));
	n.addChild(XmlNode("height", boost::lexical_cast<std::string>(t.getSize().getHeight())));
	return n;
}