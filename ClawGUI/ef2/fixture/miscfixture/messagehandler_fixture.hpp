#ifndef _MISC_FIXTURE_MESSAGEHANDLERFIXTURE_HPP
#define _MISC_FIXTURE_MESSAGEHANDLERFIXTURE_HPP

#include <misc/messagehandler.hpp>

#pragma warning(push, 0) 
#include <boost/scoped_ptr.hpp>
#pragma warning(pop)

struct MessageHandler_Fixture
{
	MessageHandler_Fixture();	
	~MessageHandler_Fixture();

	const std::string test_message1;
	const std::string test_message2;
	const std::string test_message3;

	boost::scoped_ptr<MessageHandler> test_messageHandler;
private:
};

#endif // _MISC_FIXTURE_MESSAGEHANDLERFIXTURE_HPP