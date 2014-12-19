#include "text.hpp"

#include <misc/miscellaneous.hpp>


Text::Text(const std::map<const boost::uuids::uuid, const std::string>& textMap):
	UUID<Text>(),
	textMap(textMap),
	languageId(),
	currentText()
{ }

Text::Text(const boost::uuids::uuid id, const std::map<const boost::uuids::uuid, const std::string>& textMap):
	UUID<Text>(id),
	textMap(textMap),
	languageId(),
	currentText()
{ }


void Text::updateLanguage(const boost::uuids::uuid languageId) const {
	if(this->languageId == languageId) {
		return;
	}
	this->languageId = languageId;

	const std::map<const boost::uuids::uuid, const std::string>::const_iterator i = textMap.find(languageId);
	BOOST_ASSERT(i != textMap.end());

	currentText = i->second;

	updateText(currentText);
}

void Text::updateParameters(const std::list<std::string> parameterList) const {
	currentText = textMap.find(languageId)->second;
	Misc::formatString(currentText, parameterList);
	updateText(currentText);
}



const std::string Text::getText(const std::list<std::string> parameterList) const {
	currentText = textMap.find(languageId)->second;
	Misc::formatString(currentText, parameterList);
	return currentText;
}


// signals all (UI) Objects that have registered this text that the text has changed TODO hack?
void Text::updateText(const std::string& text) const {
	sig(text);
}

boost::signals::connection Text::connect(boost::signal<void (std::string)>::slot_function_type subscriber) const {
	return sig.connect(subscriber);
}