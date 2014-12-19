// ------------------------------------------
// ------ PARSING TOOLS AND ERROR LOGS ------
// ------------------------------------------
#include "miscellaneous.hpp"

#include <sstream>
#include <iomanip>

#pragma warning(push, 0)  
#include <boost/algorithm/string.hpp>
#pragma warning(pop)

#include "exceptions.hpp"


/**
* Taken from http://en.wikipedia.org/wiki/Knuth_shuffle
* @return A random permutation array
*/
std::vector<int> Misc::getRandomArray(int length) {
	std::vector<int> random_array(length);
	for (int i = 0; i < length; i++) {
		random_array[i] = i;
	}

	int n = length;        // The number of items left to shuffle (loop invariant).
	while (n > 1) {
		int k = rand()%n;  // 0 <= k < n.
		n--;                     // n is now the last pertinent index;
		int temp = random_array[n];     // swap array[n] with array[k] (does nothing if k == n).
		random_array[n] = random_array[k];
		random_array[k] = temp;
	}

	return random_array;
}



std::string Misc::formatTime(const int time, const unsigned int speed)
{
	std::ostringstream os;
	os.str("");
	if(time < 0) {
		os << "- ";
	}
	int my_time = time / (6+speed*3);
	os << my_time/60 << ":" << std::setfill('0') << std::setw(2) << my_time%60;
	return os.str();
}


void Misc::formatString(std::string& text, std::list<std::string> parameterList) {
	for(std::list<std::string>::const_iterator i = parameterList.begin(); i != parameterList.end(); i++) {
		boost::replace_first(text, "%s", *i);
	}
}


boost::uuids::uuid Misc::uuid(const std::string& string) {
	if(string.empty()) {
		return boost::uuids::uuid();
	} else {
		return uuidgen(string);
	}
}

boost::uuids::uuid Misc::randomUuid() {
	return boost::uuids::random_generator()();
}


boost::uuids::string_generator Misc::uuidgen;