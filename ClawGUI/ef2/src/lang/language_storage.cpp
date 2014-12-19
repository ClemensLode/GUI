#include "language_storage.hpp"
#include <lang/language.hpp>

#include <misc/miscellaneous.hpp>
#include <misc/io.hpp>
#include <misc/xmlnode.hpp>

template<> const std::string SingleStorage<Language>::DATA_FILE_NAME_BASE = IO::getDirectory(boost::assign::list_of("data")("storage")("lang")) + "lang.xml";
template<> const std::string SingleStorage<Language>::DATA_FILE_IDENTIFIER = "LanguageStorage";

template<> boost::shared_ptr<Language> NodeCreator<Language>::createObjectFromNode(const std::vector<XmlNode>& node) {
	return boost::shared_ptr<Language>(new Language(Misc::uuid(node[0]), TextStorage::instance().get(Misc::uuid(node[1]))));
}

template<> XmlNode NodeCreator<Language>::createNodeFromObject(const Language& t) {
	XmlNode n("language");
	n.addChild(XmlNode("id", boost::lexical_cast<std::string>(t.getId())));
	n.addChild(XmlNode("nameID", boost::lexical_cast<std::string>(t.getName()->getId())));
	return n;
}
