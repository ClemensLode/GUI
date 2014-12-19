#include "brush_storage.hpp"
#include "brush.hpp"

#include <misc/miscellaneous.hpp>
#include <misc/io.hpp>
#include "enums/brushstyle.hpp"
#include <misc/exceptions.hpp>

#include "color_storage.hpp"

template<> const std::string SingleStorage<Brush>::DATA_FILE_NAME_BASE = IO::getDirectory(boost::assign::list_of("data")("storage")("guicore")) + "brush.xml";
template<> const std::string SingleStorage<Brush>::DATA_FILE_IDENTIFIER = "BrushStorage";

template<> boost::shared_ptr<Brush> NodeCreator<Brush>::createObjectFromNode(const std::vector<XmlNode>& node) {
	eBrushStyle brushStyle;
	std::string styleValue = node[2].getValue();

	if(styleValue == "TRANSPARENT") {
		brushStyle = TRANSPARENT_BRUSH_STYLE;
	} else if(styleValue == "SOLID") {
		brushStyle = SOLID_BRUSH_STYLE;
	} else if(styleValue == "BDIAGONAL_HATCH") {
		brushStyle = BDIAGONAL_HATCH_BRUSH_STYLE;
	} else if(styleValue == "CROSSDIAG_HATCH") {
		brushStyle = CROSSDIAG_HATCH_BRUSH_STYLE;
	} else if(styleValue == "FDIAGONAL_HATCH") {
		brushStyle = FDIAGONAL_HATCH_BRUSH_STYLE;
	} else if(styleValue == "CROSS_HATCH") {
		brushStyle = CROSS_HATCH_BRUSH_STYLE;
	} else if(styleValue == "HORIZONTAL_HATCH") {
		brushStyle = HORIZONTAL_HATCH_BRUSH_STYLE;
	} else if(styleValue == "VERTICAL_HATCH") {
		brushStyle = VERTICAL_HATCH_BRUSH_STYLE;
	} else if(styleValue == "STIPPLE") {
		brushStyle = STIPPLE_BRUSH_STYLE;
	} else if(styleValue == "STIPPLE_MASK_OPAQUE") {
		brushStyle = STIPPLE_MASK_OPAQUE_BRUSH_STYLE;
	} else {
		throw FileException("Error creating brush from node " + node[0].getValue() + " (" + styleValue + " is unknown style, see " + SingleStorage<Brush>::DATA_FILE_NAME_BASE + ")");
	}

	return boost::shared_ptr<Brush>(new Brush(Misc::uuid(node[0]), ColorStorage::instance().get(node[1]), brushStyle));
}

template<> XmlNode NodeCreator<Brush>::createNodeFromObject(const Brush& t) {
	XmlNode n("brush");
	n.addChild(XmlNode("id", boost::lexical_cast<std::string>(t.getId())));
	n.addChild(XmlNode("colorID", boost::lexical_cast<std::string>(t.getColor()->getId())));
	std::string styleValue;
	switch(t.getStyle()) {
		case TRANSPARENT_BRUSH_STYLE:styleValue = "TRANSPARENT";break;
		case SOLID_BRUSH_STYLE:styleValue = "SOLID";break;
		case BDIAGONAL_HATCH_BRUSH_STYLE:styleValue = "BDIAGONAL_HATCH";break;
		case CROSSDIAG_HATCH_BRUSH_STYLE:styleValue = "CROSSDIAG_HATCH";break;
		case FDIAGONAL_HATCH_BRUSH_STYLE:styleValue = "FDIAGONAL_HATCH";break;
		case CROSS_HATCH_BRUSH_STYLE:styleValue = "CROSS_HATCH";break;
		case HORIZONTAL_HATCH_BRUSH_STYLE:styleValue = "HORIZONTAL_HATCH";break;
		case VERTICAL_HATCH_BRUSH_STYLE:styleValue = "VERTICAL_HATCH";break;
		case STIPPLE_BRUSH_STYLE:styleValue = "STIPPLE";break;
		case STIPPLE_MASK_OPAQUE_BRUSH_STYLE:styleValue = "STIPPLE_MASK_OPAQUE";break;
		case MAX_BRUSH_STYLES:
		default:
			std::ostringstream os;
			os << "Error creating node from brush " << boost::lexical_cast<std::string>(t.getId()) << "(" << static_cast<unsigned int>(t.getStyle()) << " is invalid style, see " << SingleStorage<Brush>::DATA_FILE_NAME_BASE << ")";
			throw FileException(os.str());break;
	}

	n.addChild(XmlNode("style", styleValue));
	return n;
}