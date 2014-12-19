#include "miscellaneous_fixture.hpp"

#include <string>

#pragma warning(push, 0) 
#include <boost/lexical_cast.hpp>
#pragma warning(pop)

Miscellaneous_Fixture::Miscellaneous_Fixture():
	test_uuid(boost::uuids::random_generator()())
{ }

Miscellaneous_Fixture::~Miscellaneous_Fixture() 
{ }