#include "pen_storage.hpp"
#include "pen.hpp"

#include <misc/miscellaneous.hpp>
#include <misc/io.hpp>
#include <misc/exceptions.hpp>

#include "color_storage.hpp"

template<> const std::string SingleStorage<Pen>::DATA_FILE_NAME_BASE = IO::getDirectory(boost::assign::list_of("data")("storage")("guicore")) + "pen.xml";
template<> const std::string SingleStorage<Pen>::DATA_FILE_IDENTIFIER = "PenStorage";

template<> boost::shared_ptr<Pen> NodeCreator<Pen>::createObjectFromNode(const std::vector<XmlNode>& node) {
	ePenStyle penStyle = TRANSPARENT_PEN_STYLE;
	std::string styleValue = node[3].getValue();
	if(styleValue == "TRANSPARENT") {
		penStyle = TRANSPARENT_PEN_STYLE;
	} else
	if(styleValue == "SOLID") {
		penStyle = SOLID_PEN_STYLE;
	} else
	if(styleValue == "DOT") {
		penStyle = DOT_PEN_STYLE;
	} else
	if(styleValue == "LONG_DASH") {
		penStyle = LONG_DASH_PEN_STYLE;
	} else
	if(styleValue == "SHORT_DASH") {
		penStyle = SHORT_DASH_PEN_STYLE;
	} else
	if(styleValue == "DOT_DASH") {
		penStyle = DOT_DASH_PEN_STYLE;
	} else {
		throw FileException("Error creating pen from node (" + styleValue + " is unknown style, see " + SingleStorage<Pen>::DATA_FILE_NAME_BASE + ")");
	}
	return boost::shared_ptr<Pen>(new Pen(Misc::uuid(node[0]), ColorStorage::instance().get(node[1]), boost::lexical_cast<Uint16>(node[2].getValue()), penStyle));
}

template<> XmlNode NodeCreator<Pen>::createNodeFromObject(const Pen& t) {
	XmlNode n("pen");
	n.addChild(XmlNode("id", boost::lexical_cast<std::string>(t.getId())));
	n.addChild(XmlNode("colorID", boost::lexical_cast<std::string>(t.getColor()->getId())));
	n.addChild(XmlNode("width", boost::lexical_cast<std::string>(t.getWidth())));
	std::string styleName;
	switch(t.getStyle()) {
		case TRANSPARENT_PEN_STYLE:styleName = "TRANSPARENT";break;
		case SOLID_PEN_STYLE:styleName = "SOLID";break;
		case DOT_PEN_STYLE:styleName = "DOT";break;
		case LONG_DASH_PEN_STYLE:styleName = "LONG_DASH";break;
		case SHORT_DASH_PEN_STYLE:styleName = "SHORT_DASH";break;
		case DOT_DASH_PEN_STYLE:styleName = "DOT_DASH";break;
		case MAX_PEN_STYLE:
		default:
			std::ostringstream os;
			os << "Error creating node from pen " << boost::lexical_cast<std::string>(t.getId()) << "(" << static_cast<unsigned int>(t.getStyle()) << " is invalid style, see " << SingleStorage<Pen>::DATA_FILE_NAME_BASE << ")";
			throw FileException(os.str());
	}
	n.addChild(XmlNode("style", styleName));
	return n;
}