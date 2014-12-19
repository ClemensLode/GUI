#ifndef _MISC_FIXTURE_LOADSAVEFIXTURE_HPP
#define _MISC_FIXTURE_LOADSAVEFIXTURE_HPP


#include <misc/loadsave.hpp>

struct LoadSave_Fixture : public LoadSave
{
	LoadSave_Fixture();	
	~LoadSave_Fixture();

	std::string test_fileName;
	std::string test_fileIdentifier;

	std::string test_nodeName;
	std::string test_nodeValue;

	std::string test_node1Name;
	std::string test_node2Name;
	std::string test_node2Value;
	
	std::string test_node11Name;
	std::string test_node11Value;
	std::string test_node12Name;
	std::string test_node12Value;
	std::string test_node13Name;
	std::string test_node13Value;
private:
};

#endif // _MISC_FIXTURE_LOADSAVEFIXTURE_HPP