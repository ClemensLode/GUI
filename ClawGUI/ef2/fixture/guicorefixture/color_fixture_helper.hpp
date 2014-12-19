#ifndef _LANG_FIXTURE_COLORFIXTUREHELPER_HPP
#define _LANG_FIXTURE_COLORFIXTUREHELPER_HPP

#include <guicore/color.hpp>
#pragma warning(push, 0)
#include <boost/shared_ptr.hpp>
#include <boost/signals.hpp>
#include <boost/bind.hpp>
#include <boost/bind/placeholders.hpp>
#pragma warning(pop)

class Color_Fixture_Helper
{
public:
	Color_Fixture_Helper(const boost::shared_ptr<const Color>& color) {
		color->connect(boost::bind(&Color_Fixture_Helper::updateColor, this, _1));
	}
	~Color_Fixture_Helper() {}
	Uint32 getColor() const { return currentColor; }

	// this is used for signalling
	void updateColor(const Uint32 new_color) { currentColor = new_color;}

private:
	Uint32 currentColor;
};

#endif // _LANG_FIXTURE_COLORFIXTUREHELPER_HPP