#ifndef _LANG_TEXT_HPP
#define _LANG_TEXT_HPP

#include <string>
#include <map>

#pragma warning(push, 0)  
#include <boost/signals.hpp>
#pragma warning(pop)

#include <misc/uuid.hpp>
#include <misc/miscellaneous.hpp>


class Text : public UUID<Text>
{
public:
	Text(const std::map<const boost::uuids::uuid, const std::string>& textMap);
	Text(const boost::uuids::uuid id, const std::map<const boost::uuids::uuid, const std::string>& textMap);
	~Text() { }

	void updateLanguage(const boost::uuids::uuid languageId) const;
	void updateParameters(const std::list<std::string> parameterList) const;

	// use public boost::signals::trackable on the object wanting to connect to test
	// .connect(boost::bind(&CLASS::function, this, _1));
	boost::signals::connection connect(boost::signal<void (std::string)>::slot_function_type subscriber) const;
	const std::map<const boost::uuids::uuid, const std::string>& getTextMap() const;
	const std::string& getText() const;
	const std::string getText(const std::list<std::string> parameterList) const;

private:
	const std::map<const boost::uuids::uuid, const std::string> textMap; // languageId -> string
	mutable std::string currentText;
	// only indirect access via signals!

	void updateText(const std::string& text) const;

	mutable boost::signal<void (std::string)> sig;
	mutable boost::uuids::uuid languageId;
};


inline const std::map<const boost::uuids::uuid, const std::string>& Text::getTextMap() const {
	return textMap;
}

// current Text
inline const std::string& Text::getText() const {
	return currentText;
}

#endif // _LANG_TEXT_HPP
