#ifndef _GUICORE_FONTTYPE_HPP
#define _GUICORE_FONTTYPE_HPP

#include "font.hpp"

#include <misc/uuid.hpp>

class FontType : public UUID<FontType>
{
public:
	FontType(const boost::uuids::uuid id,
		const boost::shared_ptr<const Font>& font,
		const boost::shared_ptr<const Font>& boldFont,
		const boost::shared_ptr<const Font>& shadowFont,
		const boost::shared_ptr<const Font>& underlinedFont,
		const boost::shared_ptr<const Font>& shadowBoldFont,
		const boost::shared_ptr<const Font>& shadowUnderlinedFont,
		const boost::shared_ptr<const Font>& underlinedBoldFont,
		const boost::shared_ptr<const Font>& shadowUnderlinedBoldFont
		);
	FontType(const boost::shared_ptr<const Font>& font,
		const boost::shared_ptr<const Font>& boldFont,
		const boost::shared_ptr<const Font>& shadowFont,
		const boost::shared_ptr<const Font>& underlinedFont,
		const boost::shared_ptr<const Font>& shadowBoldFont,
		const boost::shared_ptr<const Font>& shadowUnderlinedFont,
		const boost::shared_ptr<const Font>& underlinedBoldFont,
		const boost::shared_ptr<const Font>& shadowUnderlinedBoldFont
		);
	~FontType();

	const boost::shared_ptr<const Font>& getNormalFont() const {return font;}
	const boost::shared_ptr<const Font>& getBoldFont() const {return boldFont;}
	const boost::shared_ptr<const Font>& getShadowFont() const {return shadowFont;}
	const boost::shared_ptr<const Font>& getUnderlinedFont() const {return underlinedFont;}
	const boost::shared_ptr<const Font>& getShadowBoldFont() const {return shadowBoldFont;}
	const boost::shared_ptr<const Font>& getShadowUnderlinedFont() const {return shadowUnderlinedFont;}
	const boost::shared_ptr<const Font>& getUnderlinedBoldFont() const {return underlinedBoldFont;}
	const boost::shared_ptr<const Font>& getShadowUnderlinedBoldFont() const {return shadowUnderlinedBoldFont;}

private:


	const boost::shared_ptr<const Font> font;
	const boost::shared_ptr<const Font> boldFont;
	const boost::shared_ptr<const Font> shadowFont;
	const boost::shared_ptr<const Font> underlinedFont;
	const boost::shared_ptr<const Font> shadowBoldFont;
	const boost::shared_ptr<const Font> shadowUnderlinedFont;
	const boost::shared_ptr<const Font> underlinedBoldFont;
	const boost::shared_ptr<const Font> shadowUnderlinedBoldFont;
};

#endif // _GUICORE_FONTTYPE_HPP