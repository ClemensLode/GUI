#include "messagehandler_fixture.hpp"

MessageHandler_Fixture::MessageHandler_Fixture():
	test_message1("my message1"),
	test_message2("my message 2"),
	test_message3("Last MESSAGE"),
	test_messageHandler(new MessageHandler())
{ }

MessageHandler_Fixture::~MessageHandler_Fixture() 
{ }