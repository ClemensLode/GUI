#ifndef _MISC_FIXTURE_MISCELLANEOUSFIXTURE_HPP
#define _MISC_FIXTURE_MISCELLANEOUSFIXTURE_HPP

#pragma warning(push, 0)  
#include <boost/smart_ptr.hpp>
#include <boost/uuid/uuid.hpp>
#pragma warning(pop)

#include <misc/miscellaneous.hpp>

struct Miscellaneous_Fixture
{
	Miscellaneous_Fixture();	
	~Miscellaneous_Fixture();

	const boost::uuids::uuid test_uuid;

private:
};

#endif // _MISC_FIXTURE_MISCELLANEOUSFIXTURE_HPP