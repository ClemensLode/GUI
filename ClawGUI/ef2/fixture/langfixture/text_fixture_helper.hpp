#ifndef _LANG_FIXTURE_TEXTFIXTUREHELPER_HPP
#define _LANG_FIXTURE_TEXTFIXTUREHELPER_HPP

#include <lang/text.hpp>
#pragma warning(push, 0)
#include <boost/shared_ptr.hpp>
#include <boost/signals.hpp>
#include <boost/bind.hpp>
#include <boost/bind/placeholders.hpp>
#pragma warning(pop)

class Text_Fixture_Helper
{
public:
	Text_Fixture_Helper(const boost::shared_ptr<const Text>& text) {
		text->connect(boost::bind(&Text_Fixture_Helper::updateText, this, _1));
	}
	~Text_Fixture_Helper() {}
	const std::string& getText() const { return currentText; }

	// this is used for signalling
	void updateText(const std::string& new_text) { currentText = new_text;}

private:
	std::string currentText;
};

#endif // _LANG_FIXTURE_TEXTFIXTUREHELPER_HPP