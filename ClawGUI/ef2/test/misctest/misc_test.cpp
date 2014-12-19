#ifndef WIN32
#define BOOST_TEST_DYN_LINK
#endif
#define BOOST_TEST_MODULE Misc

#pragma warning(push, 0) 
#include <boost/test/unit_test.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <string>
#pragma warning(pop)

#include <miscfixture/miscellaneous_fixture.hpp>
#include <miscfixture/io_fixture.hpp>
#include <miscfixture/loadsave_fixture.hpp>
#include <miscfixture/messagehandler_fixture.hpp>
#include <miscfixture/objectnode_fixture.hpp>

#include <sstream>


// --- MessageHandler ---

BOOST_FIXTURE_TEST_SUITE( MessageHandler_test, MessageHandler_Fixture )


	BOOST_AUTO_TEST_CASE (MessageHandler_addMessage)
{
	BOOST_CHECK_EQUAL(test_messageHandler->getRemainingMessages().size(), 0);
	test_messageHandler->clearMessages();
	BOOST_CHECK_EQUAL(test_messageHandler->getRemainingMessages().size(), 0);
	test_messageHandler->addMessage(test_message1);
	test_messageHandler->addMessage(test_message2);
	test_messageHandler->addMessage(test_message3);
	BOOST_CHECK_EQUAL(test_messageHandler->getRemainingMessages().size(), 3);
	std::vector<std::string> test_messageVector;
	for(std::list<std::string>::const_iterator i = test_messageHandler->getRemainingMessages().begin(); i != test_messageHandler->getRemainingMessages().end(); i++) {
		test_messageVector.push_back(*i);
	}
	BOOST_CHECK_EQUAL(test_messageVector[0], test_message1);
	BOOST_CHECK_EQUAL(test_messageVector[1], test_message2);
	BOOST_CHECK_EQUAL(test_messageVector[2], test_message3);
	
	test_messageHandler->clearMessages();
	BOOST_CHECK_EQUAL(test_messageHandler->getRemainingMessages().size(), 0);
}

BOOST_AUTO_TEST_SUITE_END( )

// --- END MessageHandler ---



// --- Miscellaneous ---

BOOST_FIXTURE_TEST_SUITE( Miscellaneous_test, Miscellaneous_Fixture )


	BOOST_AUTO_TEST_CASE (Miscellaneous_randomArray)
{
	std::vector<int> random_array1 = Misc::getRandomArray(100);
	std::vector<int> random_array2 = Misc::getRandomArray(100);

	bool equal = true;

	for(int i = 0; i < 100; i++) {
		if(random_array1[i] != random_array2[i]) {
			equal = false;
			break;
		}
	}

	BOOST_CHECK(!equal);
}


BOOST_AUTO_TEST_CASE (Miscellaneous_formatTime)
{
	BOOST_CHECK_EQUAL(Misc::formatTime(162, 4), "0:09");
	BOOST_CHECK_EQUAL(Misc::formatTime(2987, 2), "4:08");
}	


BOOST_AUTO_TEST_CASE (Miscellaneous_formatString)
{
	std::string test_myString = "Hi %s, hello my %s world.";
	std::list<std::string> test_parameterList;
	test_parameterList.push_back("peter");
	test_parameterList.push_back("super");
	Misc::formatString(test_myString, test_parameterList);

	BOOST_CHECK_EQUAL(test_myString, "Hi peter, hello my super world.");
}	



BOOST_AUTO_TEST_CASE (Miscellaneous_uuid)
{
	BOOST_CHECK_EQUAL(Misc::uuid(boost::lexical_cast<std::string>(test_uuid)), test_uuid);
}	


BOOST_AUTO_TEST_SUITE_END( )

	// --- END Miscellaneous ---


	// --- BEGIN IO ---
	BOOST_FIXTURE_TEST_SUITE( IO_test, IO_Fixture )


BOOST_AUTO_TEST_SUITE_END( )
	// --- END IO ---



// --- BEGIN LoadSave ---

BOOST_FIXTURE_TEST_SUITE( LoadSave_test, LoadSave_Fixture )


BOOST_AUTO_TEST_CASE (LoadSave_simpleNode)
{
	XmlNode n(test_nodeName, test_nodeValue);

	LoadSave::saveToXML(n, test_fileName, test_fileIdentifier);
	
	XmlNode new2 = LoadSave::loadFromXML(test_fileName, test_fileIdentifier);

	BOOST_CHECK_EQUAL(new2.getName(), test_nodeName);
	BOOST_CHECK_EQUAL(new2.getValue(), test_nodeValue);
	BOOST_CHECK_EQUAL(new2.getChildren().size(), 0);

	IO::removeFile(test_fileName);
}	


BOOST_AUTO_TEST_CASE (LoadSave_complexNode)
{
	XmlNode n(test_nodeName);
	XmlNode n1(test_node1Name);
	XmlNode n2(test_node2Name, test_node2Value);
	XmlNode n11(test_node11Name, test_node11Value);
	XmlNode n12(test_node12Name, test_node12Value);
	XmlNode n13(test_node13Name, test_node13Value);
	n1.addChild(n11);
	n1.addChild(n12);
	n1.addChild(n13);
	n.addChild(n1);
	n.addChild(n2);
	LoadSave::saveToXML(n, test_fileName, test_fileIdentifier);
	
	XmlNode new2 = LoadSave::loadFromXML(test_fileName, test_fileIdentifier);

	BOOST_CHECK_EQUAL(new2.getName(), test_nodeName);
	BOOST_CHECK_EQUAL(new2.getValue(), "");

	BOOST_CHECK_EQUAL(new2.getChildren().at(0).getName(), test_node1Name);
	BOOST_CHECK_EQUAL(new2.getChildren().at(0).getValue(), "");
	BOOST_REQUIRE_EQUAL(new2.getChildren().at(0).getChildren().size(), 3);

	BOOST_CHECK_EQUAL(new2.getChildren().at(0).getChildren().at(0).getName(), test_node11Name);
	BOOST_CHECK_EQUAL(new2.getChildren().at(0).getChildren().at(0).getValue(), test_node11Value);
	BOOST_CHECK_EQUAL(new2.getChildren().at(0).getChildren().at(1).getName(), test_node12Name);
	BOOST_CHECK_EQUAL(new2.getChildren().at(0).getChildren().at(1).getValue(), test_node12Value);
	BOOST_CHECK_EQUAL(new2.getChildren().at(0).getChildren().at(2).getName(), test_node13Name);
	BOOST_CHECK_EQUAL(new2.getChildren().at(0).getChildren().at(2).getValue(), test_node13Value);

	BOOST_CHECK_EQUAL(new2.getChildren().at(1).getName(), test_node2Name);
	BOOST_CHECK_EQUAL(new2.getChildren().at(1).getValue(), test_node2Value);

	IO::removeFile(test_fileName);
}	

BOOST_AUTO_TEST_SUITE_END( )
// --- END LoadSave ---


// --- BEGIN ObjectNode ---

BOOST_FIXTURE_TEST_SUITE( ObjectNode_test, ObjectNode_Fixture )


BOOST_AUTO_TEST_CASE (ObjectNode_simpleNode)
{
	BOOST_CHECK_EQUAL(test_parent->getNextBrother(), test_parent);
	BOOST_CHECK_EQUAL(test_parent->getPrevBrother(), test_parent);
	BOOST_CHECK_EQUAL(test_parent->getParent(), static_cast<ObjectNode*>(NULL));
	BOOST_CHECK_EQUAL(test_parent->getPositionParent(), static_cast<ObjectNode*>(NULL));
	BOOST_CHECK_EQUAL(test_parent->getZ(), 0);
	BOOST_CHECK_EQUAL(test_parent->isTopItem(), true);
	BOOST_CHECK_EQUAL(test_parent->getChildren(), test_child1);

	BOOST_CHECK_EQUAL(test_child1->getChildren(), test_child11);

	BOOST_CHECK_EQUAL(test_child1->getNextBrother(), test_child2);
	BOOST_CHECK_EQUAL(test_child1->getPrevBrother(), test_child2);
	BOOST_CHECK_EQUAL(test_child1->getParent(), test_parent);
	BOOST_CHECK_EQUAL(test_child1->getPositionParent(), test_parent);
	BOOST_CHECK_EQUAL(test_child1->getZ(), ObjectNode::Z_STEP);
	BOOST_CHECK_EQUAL(test_child1->isTopItem(), false);
	BOOST_CHECK_EQUAL(test_child1->getChildren(), test_child11);

	test_child1->setPositionParent(test_child2);
	BOOST_CHECK_EQUAL(test_child1->getPositionParent(), test_child2);

	BOOST_CHECK_EQUAL(test_child2->getNextBrother(), test_child1);
	BOOST_CHECK_EQUAL(test_child2->getPrevBrother(), test_child1);
	BOOST_CHECK_EQUAL(test_child2->getChildren(), static_cast<ObjectNode*>(NULL));

	
	BOOST_CHECK_EQUAL(test_child11->getNextBrother(), test_child12);
	BOOST_CHECK_EQUAL(test_child11->getPrevBrother(), test_child13);
	BOOST_CHECK_EQUAL(test_child13->getPrevBrother(), test_child12);
	BOOST_CHECK_EQUAL(test_child13->getNextBrother(), test_child11);
	BOOST_CHECK_EQUAL(test_child13->getZ(), ObjectNode::Z_STEP*2);

	test_child13->makeFirstChild();
	BOOST_CHECK_EQUAL(test_child1->getChildren(), test_child13);

	test_child13->setZ(ObjectNode::Z_STEP*4);
	BOOST_CHECK_EQUAL(test_child13->getZ(), ObjectNode::Z_STEP*4);

	test_child13->setChildrenWereChanged();

	// TODO rootObjectList, childrenWereChanged
}

BOOST_AUTO_TEST_SUITE_END( )

// --- END ObjectNode ---