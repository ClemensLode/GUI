#include "sound_storage.hpp"
#include "sound.hpp"

#include <misc/miscellaneous.hpp>
#include <misc/io.hpp>

template<> const std::string SingleStorage<Sound>::DATA_FILE_NAME_BASE = IO::getDirectory(boost::assign::list_of("data")("storage")("sound")) + "sound.xml";
template<> const std::string SingleStorage<Sound>::DATA_FILE_IDENTIFIER = "SoundStorage";

template<> boost::shared_ptr<Sound> NodeCreator<Sound>::createObjectFromNode(const std::vector<XmlNode>& node) {
	return boost::shared_ptr<Sound>(new Sound(Misc::uuid(node[0]), node[1]));
}

template<> XmlNode NodeCreator<Sound>::createNodeFromObject(const Sound& t) {
	XmlNode n("sound");
	n.addChild(XmlNode("id", boost::lexical_cast<std::string>(t.getId())));
	n.addChild(XmlNode("fileName", t.getFileName()));
	return n;
}