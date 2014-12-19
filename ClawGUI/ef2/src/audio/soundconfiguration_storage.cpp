#include "soundconfiguration_storage.hpp"
#include "soundconfiguration.hpp"

#include <misc/io.hpp>

template<> const std::string SingleStorage<SoundConfiguration>::DATA_FILE_NAME_BASE = IO::getDirectory(boost::assign::list_of("data")("storage")("sound")) + "soundconfiguration.xml";
template<> const std::string SingleStorage<SoundConfiguration>::DATA_FILE_IDENTIFIER = "SoundConfigurationStorage";

template<> boost::shared_ptr<SoundConfiguration> NodeCreator<SoundConfiguration>::createObjectFromNode(const std::vector<XmlNode>& node) {
	return boost::shared_ptr<SoundConfiguration>(new SoundConfiguration(
		Misc::uuid(node[0]), 
		node[1].getValue(),
		boost::lexical_cast<unsigned int>(node[2].getValue()),
		boost::lexical_cast<unsigned int>(node[3].getValue()),
		boost::lexical_cast<unsigned int>(node[4].getValue())
		));
}

template<> XmlNode NodeCreator<SoundConfiguration>::createNodeFromObject(const SoundConfiguration& t) {
	XmlNode n("soundconfiguration");
	n.addChild(XmlNode("id", boost::lexical_cast<std::string>(t.getId())));
	n.addChild(XmlNode("name", t.getName()));
	n.addChild(XmlNode("MusicVolume", boost::lexical_cast<std::string>(t.getMusicVolume())));	
	n.addChild(XmlNode("SoundVolume", boost::lexical_cast<std::string>(t.getSoundVolume())));	
	n.addChild(XmlNode("SoundChannels", boost::lexical_cast<std::string>(t.getSoundChannels())));
	return n;
}