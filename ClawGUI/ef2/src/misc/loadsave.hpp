#ifndef _MISC_LOADSAVE_HPP
#define _MISC_LOADSAVE_HPP

#include <string>
#include "xmlnode.hpp"

class LoadSave
{
public:
	static void saveToXML(const XmlNode& node, const std::string& dataFileName, const std::string& dataFileIdentifier);
	static XmlNode loadFromXML(const std::string& dataFileName, const std::string& dataFileIdentifier);

protected:
	virtual ~LoadSave() {}
};

#endif // _MISC_LOADSAVE_HPP