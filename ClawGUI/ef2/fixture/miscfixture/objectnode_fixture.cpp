#include "objectnode_fixture.hpp"

#include <string>

#pragma warning(push, 0) 
#include <boost/lexical_cast.hpp>
#pragma warning(pop)

ObjectNode_Fixture::ObjectNode_Fixture():
	test_parent(new ObjectNode(NULL)),
	test_child1(new ObjectNode(test_parent)),
	test_child2(new ObjectNode(test_parent)),
	test_child11(new ObjectNode(test_child1)),
	test_child12(new ObjectNode(test_child1)),
	test_child13(new ObjectNode(test_child1))
{ }

ObjectNode_Fixture::~ObjectNode_Fixture() 
{ 
	delete test_parent;
	delete test_child1;
	delete test_child2;
	delete test_child11;
	delete test_child12;
	delete test_child13;
}