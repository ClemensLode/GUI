#ifndef _MISC_MISC_HPP
#define _MISC_MISC_HPP

// ------------------------------------------
// ------ PARSING TOOLS AND ERROR LOGS ------
// ------------------------------------------
#include <list>
#include <vector>
#include <string>

#pragma warning(push, 0) 
#include <boost/uuid/uuid_generators.hpp> // generators
#pragma warning(pop)

class Misc
{
public:
	static std::string formatTime(const int time, const unsigned int speed);
	static std::vector<int> getRandomArray(int length);
	static void formatString(std::string& text, std::list<std::string> parameterList);
	static boost::uuids::uuid uuid(const std::string& string);
	static boost::uuids::uuid randomUuid();
		
	// -----------------------------------------------
	// ------  END PARSING TOOLS AND ERROR LOGS ------
	// -----------------------------------------------
private:
	Misc();
	~Misc();

	static boost::uuids::string_generator uuidgen;
	
};

#endif // _MISC_MISC_HPP

