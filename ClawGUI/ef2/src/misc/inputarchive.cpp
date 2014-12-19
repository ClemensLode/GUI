#include "inputarchive.hpp"
#include <iostream>

InputArchive::InputArchive(std::ifstream& inputFile):
inputFile(inputFile) 
{ 
	char a = '.';
	do { 
		inputFile >> a; 
	} while(!inputFile.eof() && a != '>');
}

InputArchive::~InputArchive() 
{ }

InputArchive& InputArchive::operator>>(XmlNode& node)  {
	while(!inputFile.eof()) {
		std::string name = findName();
		if(name.empty()) {
			return *this;
		}
		if(name.at(0) == '/') {
			// std::cout << "<" << name << ">";
			return *this;
		}
		std::string value = findValue();
		node.setName(name);
		node.setValue(value);
		// std::cout << "<" << name << ">" << value;
		{ char a;inputFile >> a;} // '<'
		if(value.empty()) { // -> has children 
			while(!inputFile.eof() && inputFile.peek() != '/') { // no closing statement
				XmlNode n;
				*this >> n;
				node.addChild(n);
			}
			if(inputFile.eof()) {
				return *this;
			}
			// std::cout << "</" << name << ">";
			char a;
			inputFile >> a;
			if(inputFile.eof()) {
				return *this;
			}
			do {
				inputFile >> a;
			} while(!inputFile.eof() && a != '>');
			while(!inputFile.eof() && a != '<') {
				inputFile >> a; // clear empty space and the next '<'
			}
		}
		return *this;
	}
	return *this;
}

std::string InputArchive::findName() {
	char a;
	if(inputFile.peek() == '<') {
		inputFile >> a;
	}

	std::string name;

	while(!inputFile.eof() && inputFile.peek() != '>') {
		inputFile.get(a);
		name += a;
	}
	return name;
}

std::string InputArchive::findValue() {
	std::string value;
	char a;
	inputFile >> a;
	while(!inputFile.eof() && inputFile.peek() != '<') {
		inputFile.get(a);
		value += a;
	}
	if(!value.empty()) { // closing statement
		do {
			inputFile >> a;
		} while(!inputFile.eof() && a != '>');
	}
	return value;
}
