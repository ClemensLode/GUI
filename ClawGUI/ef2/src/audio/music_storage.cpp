#include "music_storage.hpp"
#include "music.hpp"

#include <misc/miscellaneous.hpp>
#include <misc/io.hpp>

template<> const std::string SingleStorage<Music>::DATA_FILE_NAME_BASE = IO::getDirectory(boost::assign::list_of("data")("storage")("sound")) + "music.xml";
template<> const std::string SingleStorage<Music>::DATA_FILE_IDENTIFIER = "MusicStorage";

template<> boost::shared_ptr<Music> NodeCreator<Music>::createObjectFromNode(const std::vector<XmlNode>& node) {
	return boost::shared_ptr<Music>(new Music(Misc::uuid(node[0]), node[1]));
}

template<> XmlNode NodeCreator<Music>::createNodeFromObject(const Music& t) {
	XmlNode n("music");
	n.addChild(XmlNode("id", boost::lexical_cast<std::string>(t.getId())));
	n.addChild(XmlNode("fileName", t.getFileName()));
	return n;
}