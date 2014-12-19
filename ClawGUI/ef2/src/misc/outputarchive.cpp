#include "outputarchive.hpp"


OutputArchive::OutputArchive(std::ofstream& outputFile):
	outputFile(outputFile) 
{ 
	outputFile << "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>"; 
}

OutputArchive::~OutputArchive() { }

OutputArchive& OutputArchive::operator<<(const XmlNode& node) 
{
	outputFile << "<" << node.getName() << ">"; 
	if(node.isLeaf()) {	
		outputFile << node.getValue() << "</" << node.getName() << ">";	
	} else { 
		for(std::vector<XmlNode>::const_iterator i = node.getChildren().begin(); i != node.getChildren().end(); i++) { 
			*this << *i; 
		} 
		outputFile << "</" << node.getName() << ">"; 
	} 
	return *this; 
}
