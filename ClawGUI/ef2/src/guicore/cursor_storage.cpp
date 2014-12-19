#include "cursor_storage.hpp"
#include "cursor.hpp"

#include <misc/miscellaneous.hpp>
#include <misc/io.hpp>
#include "bitmap_storage.hpp"

template<> const std::string SingleStorage<Cursor>::DATA_FILE_NAME_BASE = IO::getDirectory(boost::assign::list_of("data")("storage")("guicore")) + "cursor.xml";
template<> const std::string SingleStorage<Cursor>::DATA_FILE_IDENTIFIER = "CursorStorage";

template<> boost::shared_ptr<Cursor> NodeCreator<Cursor>::createObjectFromNode(const std::vector<XmlNode>& node) {
	return boost::shared_ptr<Cursor>(new Cursor(Misc::uuid(node[0]), BitmapStorage::instance().get(node[1])));
}

template<> XmlNode NodeCreator<Cursor>::createNodeFromObject(const Cursor& t) {
	XmlNode n("cursor");
	n.addChild(XmlNode("id", boost::lexical_cast<std::string>(t.getId())));
	n.addChild(XmlNode("bitmapID", boost::lexical_cast<std::string>(t.getBitmap()->getId())));
	return n;
}