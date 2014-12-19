#ifndef _MISC_RANDOMGENERATOR_HPP
#define _MISC_RANDOMGENERATOR_HPP

#pragma warning(push, 0)
#include <boost/random/variate_generator.hpp>
#include <boost/random.hpp> 
#include <boost/uuid/uuid_generators.hpp>
#pragma warning(pop)

#include <misc/singleton.hpp>


class RandomGenerator : public Singleton<RandomGenerator>
{
	friend class Singleton<RandomGenerator>;
public:
	unsigned int rnd();
	unsigned int rndBool();
	std::string rndString();
	const boost::uuids::uuid uuid(std::string string);
	~RandomGenerator();
	
	std::vector<int> getRandomArray(int length);
protected:		
	RandomGenerator(const RandomGenerator& other):seed(other.seed),generator(other.generator),distribution(other.distribution),rndgenerator(other.rndgenerator){}
private:
	RandomGenerator();
	time_t seed;
	boost::mt19937 generator;
	boost::uniform_int<> distribution;
	boost::variate_generator<boost::mt19937&, boost::uniform_int<> > rndgenerator;
};

#endif // _MISC_RANDOMGENERATOR_HPP