#include "windowcolors_storage.hpp"
#include "windowcolors.hpp"

#include <misc/miscellaneous.hpp>
#include <misc/io.hpp>

#include "font_storage.hpp"
#include "color_storage.hpp"
#include "brush_storage.hpp"
#include "pen_storage.hpp"

template<> const std::string SingleStorage<WindowColors>::DATA_FILE_NAME_BASE = IO::getDirectory(boost::assign::list_of("data")("storage")("guicore")) + "windowcolors.xml";
template<> std::string SingleStorage<WindowColors>::DATA_FILE_NAME = DATA_FILE_NAME_BASE;
template<> const std::string SingleStorage<WindowColors>::DATA_FILE_IDENTIFIER = "WindowColorsStorage";


template<> boost::shared_ptr<WindowColors> NodeCreator<WindowColors>::createObjectFromNode(const std::vector<XmlNode>& node) {
	return boost::shared_ptr<WindowColors>(new WindowColors(Misc::uuid(node[0]),
		FontStorage::instance().get(node[1]),
		ColorStorage::instance().get(node[2]),
		BrushStorage::instance().get(node[3]),
		PenStorage::instance().get(node[4]),
		PenStorage::instance().get(node[5]),
		PenStorage::instance().get(node[6])));
}

template<> XmlNode NodeCreator<WindowColors>::createNodeFromObject(const WindowColors& t) {
	XmlNode n("windowColors");
	n.addChild(XmlNode("id", boost::lexical_cast<std::string>(t.getId())));
	n.addChild(XmlNode("fontID", boost::lexical_cast<std::string>(t.getFont()->getId())));
	n.addChild(XmlNode("textColorID", boost::lexical_cast<std::string>(t.getTextColor()->getId())));
	n.addChild(XmlNode("backgroundBrushID", boost::lexical_cast<std::string>(t.getBackgroundBrush()->getId())));
	n.addChild(XmlNode("borderPenID", boost::lexical_cast<std::string>(t.getBorderPen()->getId())));
	n.addChild(XmlNode("outerBorderPenID", boost::lexical_cast<std::string>(t.getOuterBorderPen()->getId())));
	n.addChild(XmlNode("highlightedBorderPenID", boost::lexical_cast<std::string>(t.getHighlightedBorderPen()->getId())));
	return n;
}