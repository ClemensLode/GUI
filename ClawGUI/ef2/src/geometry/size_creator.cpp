#include "size_creator.hpp"
#include "size.hpp"

#include <misc/miscellaneous.hpp>
#include <misc/uuid.hpp>

template<> boost::shared_ptr<Size> NodeCreator<Size>::createObjectFromNode(const std::vector<XmlNode>& node) {
	return boost::shared_ptr<Size>(new Size(boost::lexical_cast<Uint16>(node[0].getValue()), boost::lexical_cast<Uint16>(node[1].getValue())));
}

template<> XmlNode NodeCreator<Size>::createNodeFromObject(const Size& t) {
	XmlNode n("size");
	n.addChild(XmlNode("w", boost::lexical_cast<std::string>(t.getWidth())));
	n.addChild(XmlNode("h", boost::lexical_cast<std::string>(t.getHeight())));
	return n;
}