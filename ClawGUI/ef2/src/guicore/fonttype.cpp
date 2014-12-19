#include "fonttype.hpp"

#include "font_storage.hpp"

FontType::FontType(const boost::uuids::uuid id,
			const boost::shared_ptr<const Font>& font,
			const boost::shared_ptr<const Font>& boldFont,
			const boost::shared_ptr<const Font>& shadowFont,
			const boost::shared_ptr<const Font>& underlinedFont,
			const boost::shared_ptr<const Font>& shadowBoldFont,
			const boost::shared_ptr<const Font>& shadowUnderlinedFont,
			const boost::shared_ptr<const Font>& underlinedBoldFont,
			const boost::shared_ptr<const Font>& shadowUnderlinedBoldFont
		):
	UUID<FontType>(id),
	font(font),
	boldFont(boldFont),
	shadowFont(shadowFont),
	underlinedFont(underlinedFont),
	shadowBoldFont(shadowBoldFont),
	shadowUnderlinedFont(shadowUnderlinedFont),
	underlinedBoldFont(underlinedBoldFont),
	shadowUnderlinedBoldFont(shadowUnderlinedBoldFont)
{ }

FontType::FontType(const boost::shared_ptr<const Font>& font,
		 const boost::shared_ptr<const Font>& boldFont,
		 const boost::shared_ptr<const Font>& shadowFont,
		 const boost::shared_ptr<const Font>& underlinedFont,
		 const boost::shared_ptr<const Font>& shadowBoldFont,
		 const boost::shared_ptr<const Font>& shadowUnderlinedFont,
		 const boost::shared_ptr<const Font>& underlinedBoldFont,
		 const boost::shared_ptr<const Font>& shadowUnderlinedBoldFont
		 ):
	font(font),
	boldFont(boldFont),
	shadowFont(shadowFont),
	underlinedFont(underlinedFont),
	shadowBoldFont(shadowBoldFont),
	shadowUnderlinedFont(shadowUnderlinedFont),
	underlinedBoldFont(underlinedBoldFont),
	shadowUnderlinedBoldFont(shadowUnderlinedBoldFont)
{ }

FontType::~FontType() 
{ }


