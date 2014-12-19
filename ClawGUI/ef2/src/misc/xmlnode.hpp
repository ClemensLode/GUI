#ifndef _MISC_XMLNODE_HPP
#define _MISC_XMLNODE_HPP

#include <string>
#include <list>
#include <vector>

class XmlNode
{
public:
	XmlNode():name(),value(),nodeList() {}
	XmlNode(const std::string& name, const std::string& value):name(name), value(value), nodeList() {}
	XmlNode(const std::string& name):name(name), value(), nodeList() {}
	~XmlNode() {}

	const std::string& getName() const {return name;}
	const std::string& getValue() const {return value;}
	void setName(const std::string& name) {this->name = name;}
	void setValue(const std::string& value) {this->value = value;}
	void addChild(const XmlNode& node) {nodeList.push_back(node);}

	bool isLeaf() const {return nodeList.empty();}
	const std::vector<XmlNode>& getChildren() const {return nodeList;}
	operator std::string() const { return value;}

private:
	std::string name;
	std::string value;
	std::vector<XmlNode> nodeList;
};

#endif // _MISC_XMLNODE_HPP