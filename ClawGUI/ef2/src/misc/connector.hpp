#ifndef _MISC_CONNECTOR_HPP
#define _MISC_CONNECTOR_HPP

class Connector
{
public:
	Connector() {}
	~Connector() {}
// use public boost::signals::trackable on the object wanting to connect to test
		// .connect(boost::bind(&CLASS::function, this, _1));
		boost::signals::connection connect(boost::signal<void (std::string)>::slot_function_type subscriber) const;
};

#endif // _MISC_CONNECTOR_HPP