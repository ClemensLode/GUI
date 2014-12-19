#pragma warning(push, 0)  
#include <boost/random.hpp>
#include <boost/generator_iterator.hpp>
#pragma warning(pop)

#include "randomgenerator.hpp"
#include <time.h>
#include <sstream>

RandomGenerator::RandomGenerator():
	seed(time(0)),
	generator(static_cast<boost::uint32_t>(seed)),
	distribution(1, 100),
	rndgenerator(generator,  distribution)
{
	std::cout << "[Fixture seed " << seed << "]" << std::endl;
}

RandomGenerator::~RandomGenerator()
{ }

unsigned int RandomGenerator::rnd() {
	return rndgenerator();
}

unsigned int RandomGenerator::rndBool() {
	return rndgenerator() <= 50;
}

std::string RandomGenerator::rndString() {
	std::ostringstream os;
	os << rnd();
	return os.str();
}