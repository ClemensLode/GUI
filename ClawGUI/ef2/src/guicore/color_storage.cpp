#include "color_storage.hpp"
#include "color.hpp"

#include <misc/miscellaneous.hpp>
#include <misc/io.hpp>

template<> const std::string SingleStorage<Color>::DATA_FILE_NAME_BASE = IO::getDirectory(boost::assign::list_of("data")("storage")("guicore")) + "color.xml";
template<> const std::string SingleStorage<Color>::DATA_FILE_IDENTIFIER = "ColorStorage";

template<> boost::shared_ptr<Color> NodeCreator<Color>::createObjectFromNode(const std::vector<XmlNode>& node) {

	std::map<const boost::uuids::uuid, const SDL_Color> sdlColorMap;

	for(std::vector<XmlNode>::const_iterator i = node[1].getChildren().begin(); i != node[1].getChildren().end(); i++) {
		Uint8 r = static_cast<Uint8>(boost::lexical_cast<unsigned int>(i->getChildren()[1].getValue()));
		Uint8 g = static_cast<Uint8>(boost::lexical_cast<unsigned int>(i->getChildren()[2].getValue()));
		Uint8 b = static_cast<Uint8>(boost::lexical_cast<unsigned int>(i->getChildren()[3].getValue()));
		Uint8 a = static_cast<Uint8>(boost::lexical_cast<unsigned int>(i->getChildren()[4].getValue()));
		sdlColorMap.insert(std::pair<const boost::uuids::uuid, const SDL_Color>(Misc::uuid(i->getChildren()[0]), Color::toSDL_Color(r, g, b, a)));
	}

	return boost::shared_ptr<Color>(new Color(Misc::uuid(node[0]), sdlColorMap));
}

template<> XmlNode NodeCreator<Color>::createNodeFromObject(const Color& t) {
	XmlNode n("color");
	n.addChild(XmlNode("id", boost::lexical_cast<std::string>(t.getId())));
	XmlNode colorMap("colorMap");
	for(std::map<const boost::uuids::uuid, const SDL_Color>::const_iterator i = t.getColorMap().begin(); i != t.getColorMap().end(); i++) {
		XmlNode entry("entry");
		entry.addChild(XmlNode("themeId", boost::lexical_cast<std::string>(i->first)));
		entry.addChild(XmlNode("r", boost::lexical_cast<std::string>(static_cast<unsigned int>(i->second.r))));
		entry.addChild(XmlNode("g", boost::lexical_cast<std::string>(static_cast<unsigned int>(i->second.g))));
		entry.addChild(XmlNode("b", boost::lexical_cast<std::string>(static_cast<unsigned int>(i->second.b))));
		entry.addChild(XmlNode("a", boost::lexical_cast<std::string>(static_cast<unsigned int>(i->second.unused))));
		colorMap.addChild(entry);
	}

	n.addChild(colorMap);
	return n;
}

// call when sdl_surface has changed (e.g. new bit depth)
// TODO devise a function to update only colors of children of an object (difficult!)
void ColorStorage::updateTheme(const SDL_PixelFormat* pixelFormat, const boost::uuids::uuid themeId) {
	for(std::map<const boost::uuids::uuid, const boost::shared_ptr<const Color> >::const_iterator i = instance().getItemMap().begin(); i != instance().getItemMap().end(); i++) {
		i->second->updateTheme(pixelFormat, themeId);
	}
	currentThemeId = themeId;
}

boost::uuids::uuid ColorStorage::currentThemeId;