#ifndef _MISC_FIXTURE_OBJECTNODEFIXTURE_HPP
#define _MISC_FIXTURE_OBJECTNODEFIXTURE_HPP

#pragma warning(push, 0)  
#include <boost/smart_ptr.hpp>
#include <boost/uuid/uuid.hpp>
#pragma warning(pop)

#include <misc/objectnode.hpp>

struct ObjectNode_Fixture
{
	ObjectNode_Fixture();	
	~ObjectNode_Fixture();

	ObjectNode* test_parent;
	ObjectNode* test_child1;
	ObjectNode* test_child2;
	ObjectNode* test_child11;
	ObjectNode* test_child12;
	ObjectNode* test_child13;
private:
};

#endif // _MISC_FIXTURE_OBJECTNODEFIXTURE_HPP