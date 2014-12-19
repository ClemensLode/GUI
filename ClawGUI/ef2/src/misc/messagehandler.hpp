#ifndef _MISC_MESSAGEHANDLER_HPP
#define _MISC_MESSAGEHANDLER_HPP

#include <list>
#include <string>

class MessageHandler
{
public:
	MessageHandler();
	~MessageHandler();

	void addMessage(const std::string& msg);
	const std::list<std::string>& getRemainingMessages() const;
	void clearMessages();

private:
	std::list<std::string> remainingMessages;
};

inline void MessageHandler::addMessage(const std::string& msg) {
	remainingMessages.push_back(msg);
}

inline const std::list<std::string>& MessageHandler::getRemainingMessages() const {
	return remainingMessages;
}

inline void MessageHandler::clearMessages() {
	remainingMessages.clear();
}

#endif // _MISC_MESSAGEHANDLER_HPP
