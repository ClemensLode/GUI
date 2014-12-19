#include "fonttype_storage.hpp"
#include "fonttype.hpp"

#include <misc/miscellaneous.hpp>
#include <misc/io.hpp>

#include "font_storage.hpp"

template<> const std::string SingleStorage<FontType>::DATA_FILE_NAME_BASE = IO::getDirectory(boost::assign::list_of("data")("storage")("guicore")) + "fonttype.xml";
template<> const std::string SingleStorage<FontType>::DATA_FILE_IDENTIFIER = "FontTypeStorage";

template<> boost::shared_ptr<FontType> NodeCreator<FontType>::createObjectFromNode(const std::vector<XmlNode>& node) {
	return boost::shared_ptr<FontType>(new FontType(Misc::uuid(node[0]), 
		FontStorage::instance().get(node[1]), 
		FontStorage::instance().get(node[2]), 
		FontStorage::instance().get(node[3]), 
		FontStorage::instance().get(node[4]), 
		FontStorage::instance().get(node[5]), 
		FontStorage::instance().get(node[6]), 
		FontStorage::instance().get(node[7]), 
		FontStorage::instance().get(node[8])));
}

template<> XmlNode NodeCreator<FontType>::createNodeFromObject(const FontType& t) {
	XmlNode n("fontType");
	n.addChild(XmlNode("id", boost::lexical_cast<std::string>(t.getId())));
	n.addChild(XmlNode("fontID", boost::lexical_cast<std::string>(t.getNormalFont()->getId())));
	n.addChild(XmlNode("boldFontID", boost::lexical_cast<std::string>(t.getBoldFont()->getId())));
	n.addChild(XmlNode("shadowFontID", boost::lexical_cast<std::string>(t.getShadowFont()->getId())));
	n.addChild(XmlNode("underlinedFontID", boost::lexical_cast<std::string>(t.getUnderlinedFont()->getId())));
	n.addChild(XmlNode("shadowBoldFontID", boost::lexical_cast<std::string>(t.getShadowBoldFont()->getId())));
	n.addChild(XmlNode("shadowUnderlinedFontID", boost::lexical_cast<std::string>(t.getShadowUnderlinedFont()->getId())));
	n.addChild(XmlNode("underlinedBoldFontID", boost::lexical_cast<std::string>(t.getUnderlinedBoldFont()->getId())));
	n.addChild(XmlNode("shadowUnderlinedBoldFontID", boost::lexical_cast<std::string>(t.getShadowUnderlinedBoldFont()->getId())));
	return n;
}