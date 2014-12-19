#ifndef _MISC_NODECREATOR_HPP
#define _MISC_NODECREATOR_HPP

#include "xmlnode.hpp"
#include <vector>

#pragma warning(push, 0)
#include <boost/shared_ptr.hpp>
#include <boost/lexical_cast.hpp>
#pragma warning(pop)

template<class T>
class NodeCreator
{
public:
	static boost::shared_ptr<T> createObjectFromNode(const std::vector<XmlNode>& node);
	static XmlNode createNodeFromObject(const T& t);
};

#endif