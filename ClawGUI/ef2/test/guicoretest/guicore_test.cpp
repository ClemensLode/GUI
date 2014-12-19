#ifndef WIN32
#define BOOST_TEST_NO_MAIN
#define BOOST_TEST_DYN_LINK
#else
#undef main
#endif

#define BOOST_TEST_MAIN

#pragma warning(push, 0) 
#include <boost/test/unit_test.hpp>
#pragma warning(pop)
#include "SDL.h"
#include <guicorefixture/bitmap_fixture.hpp>
#include <guicorefixture/brush_fixture.hpp>
#include <guicorefixture/buttonanimation_fixture.hpp>
#include <guicorefixture/buttoncolors_fixture.hpp>
#include <guicorefixture/color_fixture.hpp>
#include <guicorefixture/color_fixture_helper.hpp>
#include <guicorefixture/cursor_fixture.hpp>
#include <guicorefixture/font_fixture.hpp>
#include <guicorefixture/fonttype_fixture.hpp>
#include <guicorefixture/pen_fixture.hpp>
#include <guicorefixture/windowcolors_fixture.hpp>
#include <guicorefixture/theme_fixture.hpp>

#include <guicore/animation_storage.hpp>
#include <guicore/bitmap_storage.hpp>
#include <guicore/brush_storage.hpp>
#include <guicore/buttonanimation_storage.hpp>
#include <guicore/buttoncolors_storage.hpp>
#include <guicore/color_storage.hpp>
#include <guicore/cursor_storage.hpp>
#include <guicore/font_storage.hpp>
#include <guicore/fonttype_storage.hpp>
#include <guicore/pen_storage.hpp>
#include <guicore/windowcolors_storage.hpp>
#include <guicore/theme_storage.hpp>
#include <misc/randomgenerator.hpp>
#include <geometry/objectsize_storage.hpp>
// --- Bitmap ---

BOOST_FIXTURE_TEST_SUITE( Bitmap_test, Bitmap_Fixture )

	BOOST_AUTO_TEST_CASE (Bitmap_constructor)
{
	ObjectSizeStorage::updateResolution(test_objectSizeFixture1.TEST_RESOLUTION1_ID);

	BOOST_CHECK_EQUAL(test_bitmap1->getFileName(), test_fileName1);
	BOOST_CHECK_EQUAL(test_bitmap2->getFileName(), test_fileName2);
	BOOST_CHECK_EQUAL(test_bitmap1->getObjectSize()->getSize(), test_objectSizeFixture1.test_objectsize1_size);
	BOOST_CHECK_EQUAL(test_bitmap2->getObjectSize()->getSize(), test_objectSizeFixture2.test_objectsize1_size);
	BOOST_CHECK_EQUAL(test_bitmap1->isTransparent(), test_transparent1);
	BOOST_CHECK_EQUAL(test_bitmap2->isTransparent(), test_transparent2);
	BOOST_CHECK_EQUAL((*test_bitmap1)->w, 302);
	BOOST_CHECK_EQUAL((*test_bitmap2)->w, 320);
}

BOOST_AUTO_TEST_CASE (Bitmap_storage)
{
	ObjectSizeStorage::updateResolution(test_objectSizeFixture1.TEST_RESOLUTION1_ID);

	BOOST_CHECK_EQUAL(BitmapStorage::instance().get(test_bitmap1->getId())->getFileName(), test_fileName1);
	BOOST_CHECK_EQUAL(BitmapStorage::instance().get(test_bitmap2->getId())->getFileName(), test_fileName2);
	BOOST_CHECK_EQUAL(BitmapStorage::instance().get(test_bitmap1->getId())->getObjectSize()->getSize(), test_objectSizeFixture1.test_objectsize1_size);
	BOOST_CHECK_EQUAL(BitmapStorage::instance().get(test_bitmap2->getId())->getObjectSize()->getSize(), test_objectSizeFixture2.test_objectsize1_size);
	BOOST_CHECK_EQUAL(BitmapStorage::instance().get(test_bitmap1->getId())->isTransparent(), test_transparent1);
	BOOST_CHECK_EQUAL(BitmapStorage::instance().get(test_bitmap2->getId())->isTransparent(), test_transparent2);
	BOOST_CHECK_EQUAL((*BitmapStorage::instance().get(test_bitmap1->getId()))->w, 302);
	BOOST_CHECK_EQUAL((*BitmapStorage::instance().get(test_bitmap2->getId()))->w, 320);

	BitmapStorage::saveToXML();
	BitmapStorage::reset();

	BOOST_CHECK_EQUAL(BitmapStorage::instance().get(test_bitmap1->getId())->getFileName(), test_fileName1);
	BOOST_CHECK_EQUAL(BitmapStorage::instance().get(test_bitmap2->getId())->getFileName(), test_fileName2);
	BOOST_CHECK_EQUAL(BitmapStorage::instance().get(test_bitmap1->getId())->getObjectSize()->getSize(), test_objectSizeFixture1.test_objectsize1_size);
	BOOST_CHECK_EQUAL(BitmapStorage::instance().get(test_bitmap2->getId())->getObjectSize()->getSize(), test_objectSizeFixture2.test_objectsize1_size);
	BOOST_CHECK_EQUAL(BitmapStorage::instance().get(test_bitmap1->getId())->isTransparent(), test_transparent1);
	BOOST_CHECK_EQUAL(BitmapStorage::instance().get(test_bitmap2->getId())->isTransparent(), test_transparent2);
	BOOST_CHECK_EQUAL((*BitmapStorage::instance().get(test_bitmap1->getId()))->w, 302);
	BOOST_CHECK_EQUAL((*BitmapStorage::instance().get(test_bitmap2->getId()))->w, 320);
}


BOOST_AUTO_TEST_SUITE_END( )

	// --- END Bitmap ---

	// --- Brush ---

	BOOST_FIXTURE_TEST_SUITE( Brush_test, Brush_Fixture )

	BOOST_AUTO_TEST_CASE (Brush_constructor)
{
	BOOST_CHECK_EQUAL(test_brush->getColor(), colorFixture.test_color);
	BOOST_CHECK_EQUAL(test_brush->getStyle(), test_style);
}

BOOST_AUTO_TEST_CASE (Brush_storage)
{
	BOOST_CHECK_EQUAL(BrushStorage::instance().get(test_brush->getId())->getColor(), colorFixture.test_color);
	BOOST_CHECK_EQUAL(BrushStorage::instance().get(test_brush->getId())->getStyle(), test_style);

	BrushStorage::saveToXML();
	BrushStorage::reset();

	BOOST_CHECK_EQUAL(BrushStorage::instance().get(test_brush->getId())->getColor(), colorFixture.test_color);
	BOOST_CHECK_EQUAL(BrushStorage::instance().get(test_brush->getId())->getStyle(), test_style);
}

BOOST_AUTO_TEST_SUITE_END( )

	// --- END Brush ---

	// --- ButtonAnimation ---

	BOOST_FIXTURE_TEST_SUITE( ButtonAnimation_test, ButtonAnimation_Fixture )


	BOOST_AUTO_TEST_CASE (ButtonAnimation_constructor)
{
	BOOST_CHECK_EQUAL(static_cast<Uint32> (*test_buttonanimation->getStartBrush()->getColor()), static_cast<Uint32> (*startBrushFixture.colorFixture.test_color));
	BOOST_CHECK_EQUAL(static_cast<Uint32> (*test_buttonanimation->getEndBrush()->getColor()), static_cast<Uint32> (*endBrushFixture.colorFixture.test_color));
	BOOST_CHECK_EQUAL(static_cast<Uint32> (*test_buttonanimation->getStartTextColor()), static_cast<Uint32> (*startTextColorFixture.test_color));
	BOOST_CHECK_EQUAL(static_cast<Uint32> (*test_buttonanimation->getEndTextColor()), static_cast<Uint32> (*endTextColorFixture.test_color));
	BOOST_CHECK_EQUAL(static_cast<Uint32> (*test_buttonanimation->getStartBorderPen()->getColor()), static_cast<Uint32> (*startBorderPenFixture.colorFixture.test_color));
	BOOST_CHECK_EQUAL(static_cast<Uint32> (*test_buttonanimation->getEndBorderPen()->getColor()), static_cast<Uint32> (*endBorderPenFixture.colorFixture.test_color));
	BOOST_CHECK_EQUAL((*test_buttonanimation->getBitmap())->w, (*bitmapFixture.test_bitmap1)->w);
}

BOOST_AUTO_TEST_CASE (ButtonAnimation_storage)
{
	BOOST_CHECK_EQUAL(static_cast<Uint32> (*ButtonAnimationStorage::instance().get(test_buttonanimation->getId())->getStartBrush()->getColor()), static_cast<Uint32> (*startBrushFixture.colorFixture.test_color));
	BOOST_CHECK_EQUAL(static_cast<Uint32> (*ButtonAnimationStorage::instance().get(test_buttonanimation->getId())->getEndBrush()->getColor()), static_cast<Uint32> (*endBrushFixture.colorFixture.test_color));
	BOOST_CHECK_EQUAL(static_cast<Uint32> (*ButtonAnimationStorage::instance().get(test_buttonanimation->getId())->getStartTextColor()), static_cast<Uint32> (*startTextColorFixture.test_color));
	BOOST_CHECK_EQUAL(static_cast<Uint32> (*ButtonAnimationStorage::instance().get(test_buttonanimation->getId())->getEndTextColor()), static_cast<Uint32> (*endTextColorFixture.test_color));
	BOOST_CHECK_EQUAL(static_cast<Uint32> (*ButtonAnimationStorage::instance().get(test_buttonanimation->getId())->getStartBorderPen()->getColor()), static_cast<Uint32> (*startBorderPenFixture.colorFixture.test_color));
	BOOST_CHECK_EQUAL(static_cast<Uint32> (*ButtonAnimationStorage::instance().get(test_buttonanimation->getId())->getEndBorderPen()->getColor()), static_cast<Uint32> (*endBorderPenFixture.colorFixture.test_color));
	BOOST_CHECK_EQUAL((*ButtonAnimationStorage::instance().get(test_buttonanimation->getId())->getBitmap())->w, (*bitmapFixture.test_bitmap1)->w);

	ButtonAnimationStorage::saveToXML();
	ButtonAnimationStorage::reset();

	BOOST_CHECK_EQUAL(static_cast<Uint32> (*ButtonAnimationStorage::instance().get(test_buttonanimation->getId())->getStartBrush()->getColor()), static_cast<Uint32> (*startBrushFixture.colorFixture.test_color));
	BOOST_CHECK_EQUAL(static_cast<Uint32> (*ButtonAnimationStorage::instance().get(test_buttonanimation->getId())->getEndBrush()->getColor()), static_cast<Uint32> (*endBrushFixture.colorFixture.test_color));
	BOOST_CHECK_EQUAL(static_cast<Uint32> (*ButtonAnimationStorage::instance().get(test_buttonanimation->getId())->getStartTextColor()), static_cast<Uint32> (*startTextColorFixture.test_color));
	BOOST_CHECK_EQUAL(static_cast<Uint32> (*ButtonAnimationStorage::instance().get(test_buttonanimation->getId())->getEndTextColor()), static_cast<Uint32> (*endTextColorFixture.test_color));
	BOOST_CHECK_EQUAL(static_cast<Uint32> (*ButtonAnimationStorage::instance().get(test_buttonanimation->getId())->getStartBorderPen()->getColor()), static_cast<Uint32> (*startBorderPenFixture.colorFixture.test_color));
	BOOST_CHECK_EQUAL(static_cast<Uint32> (*ButtonAnimationStorage::instance().get(test_buttonanimation->getId())->getEndBorderPen()->getColor()), static_cast<Uint32> (*endBorderPenFixture.colorFixture.test_color));
	BOOST_CHECK_EQUAL((*ButtonAnimationStorage::instance().get(test_buttonanimation->getId())->getBitmap())->w, (*bitmapFixture.test_bitmap1)->w);
}

BOOST_AUTO_TEST_SUITE_END( )

	// --- END ButtonAnimation ---

	// --- ButtonColors ---

	BOOST_FIXTURE_TEST_SUITE( ButtonColors_test, ButtonColors_Fixture )

	BOOST_AUTO_TEST_CASE (ButtonColors_constructor)
{
	BOOST_CHECK_EQUAL(test_buttoncolors->getSpeed(), test_speed);
	BOOST_CHECK_EQUAL(test_buttoncolors->getAnimationType(), test_animationType);

	BOOST_CHECK_EQUAL(test_buttoncolors->getButtonAnimation(DISABLED_BUTTON_PHASE)->getId(), buttonAnimationDisabledFixture.test_buttonanimation->getId());
	BOOST_CHECK_EQUAL(test_buttoncolors->getButtonAnimation(NORMAL_BUTTON_PHASE)->getId(), buttonAnimationNormalFixture.test_buttonanimation->getId());
	BOOST_CHECK_EQUAL(test_buttoncolors->getButtonAnimation(PRESSED_BUTTON_PHASE)->getId(), buttonAnimationPressedFixture.test_buttonanimation->getId());
	BOOST_CHECK_EQUAL(test_buttoncolors->getButtonAnimation(HIGHLIGHT_BUTTON_PHASE)->getId(), buttonAnimationHighlightFixture.test_buttonanimation->getId());
	BOOST_CHECK_EQUAL(test_buttoncolors->getButtonAnimation(PRESSED_HIGHLIGHTED_BUTTON_PHASE)->getId(), buttonAnimationPressedHighlightedFixture.test_buttonanimation->getId());
}

BOOST_AUTO_TEST_CASE (ButtonColors_storage)
{
	BOOST_CHECK_EQUAL(ButtonColorsStorage::instance().get(test_buttoncolors->getId())->getSpeed(), test_speed);
	BOOST_CHECK_EQUAL(ButtonColorsStorage::instance().get(test_buttoncolors->getId())->getAnimationType(), test_animationType);
	BOOST_CHECK_EQUAL(ButtonColorsStorage::instance().get(test_buttoncolors->getId())->getButtonAnimation(DISABLED_BUTTON_PHASE)->getId(), buttonAnimationDisabledFixture.test_buttonanimation->getId());
	BOOST_CHECK_EQUAL(ButtonColorsStorage::instance().get(test_buttoncolors->getId())->getButtonAnimation(NORMAL_BUTTON_PHASE)->getId(), buttonAnimationNormalFixture.test_buttonanimation->getId());
	BOOST_CHECK_EQUAL(ButtonColorsStorage::instance().get(test_buttoncolors->getId())->getButtonAnimation(PRESSED_BUTTON_PHASE)->getId(), buttonAnimationPressedFixture.test_buttonanimation->getId());
	BOOST_CHECK_EQUAL(ButtonColorsStorage::instance().get(test_buttoncolors->getId())->getButtonAnimation(HIGHLIGHT_BUTTON_PHASE)->getId(), buttonAnimationHighlightFixture.test_buttonanimation->getId());
	BOOST_CHECK_EQUAL(ButtonColorsStorage::instance().get(test_buttoncolors->getId())->getButtonAnimation(PRESSED_HIGHLIGHTED_BUTTON_PHASE)->getId(), buttonAnimationPressedHighlightedFixture.test_buttonanimation->getId());

	ButtonColorsStorage::saveToXML();
	ButtonColorsStorage::reset();

	BOOST_CHECK_EQUAL(ButtonColorsStorage::instance().get(test_buttoncolors->getId())->getSpeed(), test_speed);
	BOOST_CHECK_EQUAL(ButtonColorsStorage::instance().get(test_buttoncolors->getId())->getAnimationType(), test_animationType);
	BOOST_CHECK_EQUAL(ButtonColorsStorage::instance().get(test_buttoncolors->getId())->getButtonAnimation(DISABLED_BUTTON_PHASE)->getId(), buttonAnimationDisabledFixture.test_buttonanimation->getId());
	BOOST_CHECK_EQUAL(ButtonColorsStorage::instance().get(test_buttoncolors->getId())->getButtonAnimation(NORMAL_BUTTON_PHASE)->getId(), buttonAnimationNormalFixture.test_buttonanimation->getId());
	BOOST_CHECK_EQUAL(ButtonColorsStorage::instance().get(test_buttoncolors->getId())->getButtonAnimation(PRESSED_BUTTON_PHASE)->getId(), buttonAnimationPressedFixture.test_buttonanimation->getId());
	BOOST_CHECK_EQUAL(ButtonColorsStorage::instance().get(test_buttoncolors->getId())->getButtonAnimation(HIGHLIGHT_BUTTON_PHASE)->getId(), buttonAnimationHighlightFixture.test_buttonanimation->getId());
	BOOST_CHECK_EQUAL(ButtonColorsStorage::instance().get(test_buttoncolors->getId())->getButtonAnimation(PRESSED_HIGHLIGHTED_BUTTON_PHASE)->getId(), buttonAnimationPressedHighlightedFixture.test_buttonanimation->getId());
}

BOOST_AUTO_TEST_SUITE_END( )

	// --- END ButtonColors ---


	// --- Theme ---

BOOST_FIXTURE_TEST_SUITE( Theme_test, Theme_Fixture )

	BOOST_AUTO_TEST_CASE (Theme_constructor)
{
	BOOST_CHECK_EQUAL(test_theme->getName(), test_name);
	BOOST_CHECK_EQUAL(test_theme->getPrimaryColor(), primaryColorFixture.test_color);
	BOOST_CHECK_EQUAL(test_theme->getSecondaryColor(), secondaryColorFixture.test_color);
}

BOOST_AUTO_TEST_CASE (Theme_storage)
{
	BOOST_CHECK_EQUAL(ThemeStorage::instance().get(test_theme->getId())->getName(), test_name);
	BOOST_CHECK_EQUAL(ThemeStorage::instance().get(test_theme->getId())->getPrimaryColor(), primaryColorFixture.test_color);
	BOOST_CHECK_EQUAL(ThemeStorage::instance().get(test_theme->getId())->getSecondaryColor(), secondaryColorFixture.test_color);

	ThemeStorage::saveToXML();
	ThemeStorage::reset();

	BOOST_CHECK_EQUAL(ThemeStorage::instance().get(test_theme->getId())->getName(), test_name);
	BOOST_CHECK_EQUAL(ThemeStorage::instance().get(test_theme->getId())->getPrimaryColor(), primaryColorFixture.test_color);
	BOOST_CHECK_EQUAL(ThemeStorage::instance().get(test_theme->getId())->getSecondaryColor(), secondaryColorFixture.test_color);}


BOOST_AUTO_TEST_SUITE_END( )

// --- END Theme ---

	// --- Color ---

	BOOST_FIXTURE_TEST_SUITE( Color_test, Color_Fixture )

	BOOST_AUTO_TEST_CASE (Color_constructor)
{
	Color_Fixture_Helper testFixtureHelper(test_color);

	test_color->updateTheme(dcFixture.test_dc->getSurface()->format, TEST_THEME2_ID);
	BOOST_CHECK_EQUAL(testFixtureHelper.getColor(), *test_color);
	test_color->updateTheme(dcFixture.test_dc->getSurface()->format, TEST_THEME1_ID);
	BOOST_CHECK_EQUAL(testFixtureHelper.getColor(), *test_color);

	// TODO Test other functions
	BOOST_CHECK_EQUAL(test_color->r(), test_sdlcolor1.r);
	BOOST_CHECK_EQUAL(test_color->g(), test_sdlcolor1.g);
	BOOST_CHECK_EQUAL(test_color->b(), test_sdlcolor1.b);
	// TODO ucolor?
	BOOST_CHECK_EQUAL((static_cast<SDL_Color>(*test_color)).r, test_sdlcolor1.r);
	BOOST_CHECK_EQUAL((static_cast<SDL_Color>(*test_color)).g, test_sdlcolor1.g);
	BOOST_CHECK_EQUAL((static_cast<SDL_Color>(*test_color)).b, test_sdlcolor1.b);
}
/*
	BOOST_AUTO_TEST_CASE (Color_mix)
{
	test_color->updateTheme(dcFixture.test_dc->getSurface()->format, TEST_THEME1_ID);
	Color temp_color(dcFixture.test_dc->getSurface()->format, test_sdlcolor2.r, test_sdlcolor2.g, test_sdlcolor2.b, test_sdlcolor2.unused);
	Color result_color(dcFixture.test_dc->getSurface()->format, (test_color->r() + temp_color.r())/2, (test_color->g() + temp_color.g())/2, (test_color->b() + temp_color.b())/2);

	SDL_Color new_color = Color::toSDL_Color(dcFixture.test_dc->getSurface()->format, test_color->mixColor(temp_color));
	
	BOOST_CHECK_EQUAL(result_color.r(), new_color.r);
	BOOST_CHECK_EQUAL(result_color.g(), new_color.g);
	BOOST_CHECK_EQUAL(result_color.b(), new_color.b);
}

	BOOST_AUTO_TEST_CASE (Color_mixGradient)
{
	test_color->updateTheme(dcFixture.test_dc->getSurface()->format, TEST_THEME1_ID);
	Color temp_color(dcFixture.test_dc->getSurface()->format, test_sdlcolor2.r, test_sdlcolor2.g, test_sdlcolor2.b);
	Color result_color(dcFixture.test_dc->getSurface()->format, (test_color->r()*40 + temp_color.r()*60)/100, (test_color->g()*40 + temp_color.g()*60)/100, (test_color->b()*40 + temp_color.b()*60)/100);

	// TODO: mixColor seems to screw up translation from and two Uint32
	SDL_Color new_color = Color::toSDL_Color(dcFixture.test_dc->getSurface()->format, test_color->mixColor(temp_color, 40));
	
	BOOST_CHECK_EQUAL(result_color.r(), new_color.r);
	BOOST_CHECK_EQUAL(result_color.g(), new_color.g);
	BOOST_CHECK_EQUAL(result_color.b(), new_color.b);
}

	BOOST_AUTO_TEST_CASE (Color_absoluteBrightness)
{
	unsigned int changeBrightness = RandomGenerator::instance().rnd();
	test_color->updateTheme(dcFixture.test_dc->getSurface()->format, TEST_THEME1_ID);
	Color result_color(dcFixture.test_dc->getSurface()->format, 
		test_color->r()+changeBrightness>255?255:test_color->r()+changeBrightness, 
		test_color->g()+changeBrightness>255?255:test_color->g()+changeBrightness, 
		test_color->b()+changeBrightness>255?255:test_color->b()+changeBrightness);
	// TODO: mixColor seems to screw up translation from and two Uint32
	SDL_Color new_color = Color::toSDL_Color(dcFixture.test_dc->getSurface()->format, test_color->changeAbsoluteBrightness(changeBrightness));
	
	BOOST_CHECK_EQUAL(result_color.r(), new_color.r);
	BOOST_CHECK_EQUAL(result_color.g(), new_color.g);
	BOOST_CHECK_EQUAL(result_color.b(), new_color.b);
}
*/
BOOST_AUTO_TEST_CASE(Color_absoluteBrightness_nop)
{
	test_color->updateTheme(dcFixture.test_dc->getSurface()->format, TEST_THEME1_ID);
	Uint32 temp_color = test_color->changeAbsoluteBrightness(0);
	BOOST_CHECK_EQUAL(temp_color, *test_color);
}

BOOST_AUTO_TEST_CASE (Color_relativeBrightness)
{
	test_color->updateTheme(dcFixture.test_dc->getSurface()->format, TEST_THEME1_ID);
	Uint32 temp_color1 = test_color->changeRelativeBrightness(10);
	Uint32 temp_color2 = test_color->changeRelativeBrightness(150);

	Color result_color1(dcFixture.test_dc->getSurface()->format, 
		test_color->r()/10, 
		test_color->g()/10, 
		test_color->b()/10);
	Color result_color2(dcFixture.test_dc->getSurface()->format, 
		test_color->r()*3/2>255?255:test_color->r()*3/2, 
		test_color->g()*3/2>255?255:test_color->g()*3/2, 
		test_color->b()*3/2>255?255:test_color->b()*3/2);
	
	BOOST_CHECK_EQUAL(temp_color1, result_color1);
	BOOST_CHECK_EQUAL(temp_color2, result_color2);
}

BOOST_AUTO_TEST_CASE (Color_relativeBrightness_nop)
{
	test_color->updateTheme(dcFixture.test_dc->getSurface()->format, TEST_THEME1_ID);
	Uint32 temp_color = test_color->changeAbsoluteBrightness(0);
	BOOST_CHECK_EQUAL(temp_color, *test_color);


	Uint32 temp_color1 = test_color->changeRelativeBrightness(100);
	Uint32 temp_color2 = test_color->changeRelativeBrightness(0);

	BOOST_CHECK_EQUAL(temp_color1, *test_color);
	BOOST_CHECK_EQUAL(temp_color2, 0);
}

// TODO check Uint32 transformation
/*
BOOST_AUTO_TEST_CASE (Color_storage)
{

	ColorStorage::updateTheme(dcFixture.test_dc->getSurface()->format, TEST_THEME1_ID);

	BOOST_CHECK_EQUAL(*ColorStorage::instance().get(test_color->getId()), *test_color);

	ColorStorage::saveToXML();
	ColorStorage::reset();
	ColorStorage::updateTheme(dcFixture.test_dc->getSurface()->format, TEST_THEME1_ID);

	BOOST_CHECK_EQUAL(*ColorStorage::instance().get(test_color->getId()), *test_color);

	ColorStorage::updateTheme(dcFixture.test_dc->getSurface()->format, TEST_THEME2_ID);
	
	BOOST_CHECK_EQUAL(*ColorStorage::instance().get(test_color->getId()), *test_color);
}*/

BOOST_AUTO_TEST_SUITE_END( )

	// --- END Color ---

	// --- Cursor ---
	// TODO: User proper mouse pointer images in fixture

	/*
	BOOST_FIXTURE_TEST_SUITE( Cursor_test, Cursor_Fixture )

	BOOST_AUTO_TEST_CASE (Cursor_constructor)
{
	// actual testing is done in sdlwraptest because cursor needs an initialized SDL environment
	BOOST_CHECK_EQUAL(test_cursor1->getBitmap()->getId(), test_bitmapFixture.test_bitmap1->getId());
	BOOST_CHECK_EQUAL(test_cursor2->getBitmap()->getId(), test_bitmapFixture.test_bitmap2->getId());

	BOOST_REQUIRE((static_cast<SDL_Cursor*>(*test_cursor1)) != NULL);
	BOOST_REQUIRE((static_cast<SDL_Cursor*>(*test_cursor2)) != NULL);
	
	BOOST_CHECK_EQUAL((static_cast<SDL_Cursor*>(*test_cursor1))->area.w, test_bitmapFixture.test_bitmap1->getSize().getWidth() - test_bitmapFixture.test_bitmap1->getSize().getWidth()%8);
	BOOST_CHECK_EQUAL((static_cast<SDL_Cursor*>(*test_cursor2))->area.w, test_bitmapFixture.test_bitmap2->getSize().getWidth() - test_bitmapFixture.test_bitmap2->getSize().getWidth()%8);
	BOOST_CHECK_EQUAL((static_cast<SDL_Cursor*>(*test_cursor1))->area.h, test_bitmapFixture.test_bitmap1->getSize().getHeight());
	BOOST_CHECK_EQUAL((static_cast<SDL_Cursor*>(*test_cursor2))->area.h, test_bitmapFixture.test_bitmap2->getSize().getHeight());
}

BOOST_AUTO_TEST_CASE (Cursor_storage)
{
	BOOST_CHECK_EQUAL(CursorStorage::instance().get(test_cursor1->getId())->getBitmap()->getId(), test_bitmapFixture.test_bitmap1->getId());
	BOOST_CHECK_EQUAL(CursorStorage::instance().get(test_cursor2->getId())->getBitmap()->getId(), test_bitmapFixture.test_bitmap2->getId());

	CursorStorage::saveToXML();
	CursorStorage::reset();

	BOOST_CHECK_EQUAL(CursorStorage::instance().get(test_cursor1->getId())->getBitmap()->getId(), test_bitmapFixture.test_bitmap1->getId());
	BOOST_CHECK_EQUAL(CursorStorage::instance().get(test_cursor2->getId())->getBitmap()->getId(), test_bitmapFixture.test_bitmap2->getId());
}

BOOST_AUTO_TEST_SUITE_END( )
*/
	// --- END Cursor ---

	// --- Font ---

	BOOST_FIXTURE_TEST_SUITE( Font_test, Font_Fixture )

	BOOST_AUTO_TEST_CASE (Font_constructor)
{
	BOOST_CHECK_EQUAL(test_font->getFileName(), test_fileName);
	BOOST_CHECK_EQUAL(test_font->getSize(), test_size);
	BOOST_CHECK_EQUAL(test_font->isShadow(), test_shadow);
	BOOST_CHECK_EQUAL(test_font->isUnderlined(), test_underlined);
}

BOOST_AUTO_TEST_CASE (Font_storage)
{
	BOOST_CHECK_EQUAL(FontStorage::instance().get(test_font->getId())->getFileName(), test_fileName);
	BOOST_CHECK_EQUAL(FontStorage::instance().get(test_font->getId())->getSize(), test_size);
	BOOST_CHECK_EQUAL(FontStorage::instance().get(test_font->getId())->isShadow(), test_shadow);
	BOOST_CHECK_EQUAL(FontStorage::instance().get(test_font->getId())->isUnderlined(), test_underlined);

	FontStorage::saveToXML();
	FontStorage::reset();

	BOOST_CHECK_EQUAL(FontStorage::instance().get(test_font->getId())->getFileName(), test_fileName);
	BOOST_CHECK_EQUAL(FontStorage::instance().get(test_font->getId())->getSize(), test_size);
	BOOST_CHECK_EQUAL(FontStorage::instance().get(test_font->getId())->isShadow(), test_shadow);
	BOOST_CHECK_EQUAL(FontStorage::instance().get(test_font->getId())->isUnderlined(), test_underlined);
}

BOOST_AUTO_TEST_CASE (Font_getTextExtent)
{
	Font* test_font2 = new Font(test_fileName, 16);
	/*BOOST_CHECK_EQUAL(test_font2->getTextExtent("Test").getWidth(), 34); // TODO different sizes win32/linux?
	BOOST_CHECK_EQUAL(test_font2->getTextExtent("Test").getHeight(), 25);
	BOOST_CHECK_EQUAL(test_font2->getTextExtent("Test a long string").getWidth(), 123);
	BOOST_CHECK_EQUAL(test_font2->getTextExtent("Test a long string").getHeight(), 25);*/
	delete test_font2;
}

BOOST_AUTO_TEST_SUITE_END( )

	// --- END Font ---

	// --- FontType ---

	BOOST_FIXTURE_TEST_SUITE( FontType_test, FontType_Fixture )

	BOOST_AUTO_TEST_CASE (FontType_constructor)
{
	BOOST_CHECK_EQUAL(test_fonttype->getNormalFont()->getId(), test_fontFixture.test_font->getId());
	BOOST_CHECK_EQUAL(test_fonttype->getBoldFont()->getId(), test_boldFontFixture.test_font->getId());
	BOOST_CHECK_EQUAL(test_fonttype->getShadowFont()->getId(), test_shadowFontFixture.test_font->getId());
	BOOST_CHECK_EQUAL(test_fonttype->getUnderlinedFont()->getId(), test_underlinedFontFixture.test_font->getId());
	BOOST_CHECK_EQUAL(test_fonttype->getShadowBoldFont()->getId(), test_shadowBoldFontFixture.test_font->getId());
	BOOST_CHECK_EQUAL(test_fonttype->getShadowUnderlinedFont()->getId(), test_shadowUnderlinedFontFixture.test_font->getId());
	BOOST_CHECK_EQUAL(test_fonttype->getUnderlinedBoldFont()->getId(), test_underlinedBoldFontFixture.test_font->getId());
	BOOST_CHECK_EQUAL(test_fonttype->getShadowUnderlinedBoldFont()->getId(), test_shadowUnderlinedBoldFontFixture.test_font->getId());
}

BOOST_AUTO_TEST_CASE (FontType_storage)
{
	BOOST_CHECK_EQUAL(FontTypeStorage::instance().get(test_fonttype->getId())->getNormalFont()->getId(), test_fontFixture.test_font->getId());
	BOOST_CHECK_EQUAL(FontTypeStorage::instance().get(test_fonttype->getId())->getBoldFont()->getId(), test_boldFontFixture.test_font->getId());
	BOOST_CHECK_EQUAL(FontTypeStorage::instance().get(test_fonttype->getId())->getShadowFont()->getId(), test_shadowFontFixture.test_font->getId());
	BOOST_CHECK_EQUAL(FontTypeStorage::instance().get(test_fonttype->getId())->getUnderlinedFont()->getId(), test_underlinedFontFixture.test_font->getId());
	BOOST_CHECK_EQUAL(FontTypeStorage::instance().get(test_fonttype->getId())->getShadowBoldFont()->getId(), test_shadowBoldFontFixture.test_font->getId());
	BOOST_CHECK_EQUAL(FontTypeStorage::instance().get(test_fonttype->getId())->getShadowUnderlinedFont()->getId(), test_shadowUnderlinedFontFixture.test_font->getId());
	BOOST_CHECK_EQUAL(FontTypeStorage::instance().get(test_fonttype->getId())->getUnderlinedBoldFont()->getId(), test_underlinedBoldFontFixture.test_font->getId());
	BOOST_CHECK_EQUAL(FontTypeStorage::instance().get(test_fonttype->getId())->getShadowUnderlinedBoldFont()->getId(), test_shadowUnderlinedBoldFontFixture.test_font->getId());

	FontTypeStorage::saveToXML();
	FontTypeStorage::reset();

	BOOST_CHECK_EQUAL(FontTypeStorage::instance().get(test_fonttype->getId())->getNormalFont()->getId(), test_fontFixture.test_font->getId());
	BOOST_CHECK_EQUAL(FontTypeStorage::instance().get(test_fonttype->getId())->getBoldFont()->getId(), test_boldFontFixture.test_font->getId());
	BOOST_CHECK_EQUAL(FontTypeStorage::instance().get(test_fonttype->getId())->getShadowFont()->getId(), test_shadowFontFixture.test_font->getId());
	BOOST_CHECK_EQUAL(FontTypeStorage::instance().get(test_fonttype->getId())->getUnderlinedFont()->getId(), test_underlinedFontFixture.test_font->getId());
	BOOST_CHECK_EQUAL(FontTypeStorage::instance().get(test_fonttype->getId())->getShadowBoldFont()->getId(), test_shadowBoldFontFixture.test_font->getId());
	BOOST_CHECK_EQUAL(FontTypeStorage::instance().get(test_fonttype->getId())->getShadowUnderlinedFont()->getId(), test_shadowUnderlinedFontFixture.test_font->getId());
	BOOST_CHECK_EQUAL(FontTypeStorage::instance().get(test_fonttype->getId())->getUnderlinedBoldFont()->getId(), test_underlinedBoldFontFixture.test_font->getId());
	BOOST_CHECK_EQUAL(FontTypeStorage::instance().get(test_fonttype->getId())->getShadowUnderlinedBoldFont()->getId(), test_shadowUnderlinedBoldFontFixture.test_font->getId());
}

BOOST_AUTO_TEST_SUITE_END( )

	// --- END FontType ---


	// --- Pen ---

	BOOST_FIXTURE_TEST_SUITE( Pen_test, Pen_Fixture )

	BOOST_AUTO_TEST_CASE (Pen_constructor)
{
	BOOST_CHECK_EQUAL(static_cast<Uint32>(*test_pen->getColor()), static_cast<Uint32> (*colorFixture.test_color));
	BOOST_CHECK_EQUAL(test_pen->getStyle(), test_style);
	BOOST_CHECK_EQUAL(test_pen->getWidth(), test_width);
}

BOOST_AUTO_TEST_CASE (Pen_storage)
{
	BOOST_CHECK_EQUAL(static_cast<Uint32>(*PenStorage::instance().get(test_pen->getId())->getColor()), static_cast<Uint32> (*colorFixture.test_color));
	BOOST_CHECK_EQUAL(PenStorage::instance().get(test_pen->getId())->getStyle(), test_style);
	BOOST_CHECK_EQUAL(PenStorage::instance().get(test_pen->getId())->getWidth(), test_width);

	PenStorage::saveToXML();
	PenStorage::reset();

	BOOST_CHECK_EQUAL(static_cast<Uint32>(*PenStorage::instance().get(test_pen->getId())->getColor()), static_cast<Uint32> (*colorFixture.test_color));
	BOOST_CHECK_EQUAL(PenStorage::instance().get(test_pen->getId())->getStyle(), test_style);
	BOOST_CHECK_EQUAL(PenStorage::instance().get(test_pen->getId())->getWidth(), test_width);
}

BOOST_AUTO_TEST_SUITE_END( )

	// --- END Pen ---

	// --- WindowColors ---

	BOOST_FIXTURE_TEST_SUITE( WindowColors_test, WindowColors_Fixture )

	BOOST_AUTO_TEST_CASE (WindowColors_constructor)
{
	BOOST_CHECK_EQUAL(test_windowcolors->getFont()->getId(), fontFixture.test_font->getId());
	BOOST_CHECK_EQUAL(test_windowcolors->getTextColor()->getId(), textColorFixture.test_color->getId());
	BOOST_CHECK_EQUAL(test_windowcolors->getBackgroundBrush()->getId(), backgroundBrushFixture.test_brush->getId());
	BOOST_CHECK_EQUAL(test_windowcolors->getBorderPen()->getId(), borderPenFixture.test_pen->getId());
	BOOST_CHECK_EQUAL(test_windowcolors->getOuterBorderPen()->getId(), outerBorderPenFixture.test_pen->getId());
	BOOST_CHECK_EQUAL(test_windowcolors->getHighlightedBorderPen()->getId(), highlightedBorderPenFixture.test_pen->getId());
}

BOOST_AUTO_TEST_CASE (WindowColors_storage)
{
	BOOST_CHECK_EQUAL(WindowColorsStorage::instance().get(test_windowcolors->getId())->getFont()->getId(), fontFixture.test_font->getId());
	BOOST_CHECK_EQUAL(WindowColorsStorage::instance().get(test_windowcolors->getId())->getTextColor()->getId(), textColorFixture.test_color->getId());
	BOOST_CHECK_EQUAL(WindowColorsStorage::instance().get(test_windowcolors->getId())->getBackgroundBrush()->getId(), backgroundBrushFixture.test_brush->getId());
	BOOST_CHECK_EQUAL(WindowColorsStorage::instance().get(test_windowcolors->getId())->getBorderPen()->getId(), borderPenFixture.test_pen->getId());
	BOOST_CHECK_EQUAL(WindowColorsStorage::instance().get(test_windowcolors->getId())->getOuterBorderPen()->getId(), outerBorderPenFixture.test_pen->getId());
	BOOST_CHECK_EQUAL(WindowColorsStorage::instance().get(test_windowcolors->getId())->getHighlightedBorderPen()->getId(), highlightedBorderPenFixture.test_pen->getId());

	WindowColorsStorage::saveToXML();
	WindowColorsStorage::reset();

	BOOST_CHECK_EQUAL(WindowColorsStorage::instance().get(test_windowcolors->getId())->getFont()->getId(), fontFixture.test_font->getId());
	BOOST_CHECK_EQUAL(WindowColorsStorage::instance().get(test_windowcolors->getId())->getTextColor()->getId(), textColorFixture.test_color->getId());
	BOOST_CHECK_EQUAL(WindowColorsStorage::instance().get(test_windowcolors->getId())->getBackgroundBrush()->getId(), backgroundBrushFixture.test_brush->getId());
	BOOST_CHECK_EQUAL(WindowColorsStorage::instance().get(test_windowcolors->getId())->getBorderPen()->getId(), borderPenFixture.test_pen->getId());
	BOOST_CHECK_EQUAL(WindowColorsStorage::instance().get(test_windowcolors->getId())->getOuterBorderPen()->getId(), outerBorderPenFixture.test_pen->getId());
	BOOST_CHECK_EQUAL(WindowColorsStorage::instance().get(test_windowcolors->getId())->getHighlightedBorderPen()->getId(), highlightedBorderPenFixture.test_pen->getId());
}

BOOST_AUTO_TEST_SUITE_END( )

	// --- END WindowColors ---

// required because of SDL
int main( int argc, char* argv[] )
{
#ifdef WIN32
	return ::boost::unit_test::unit_test_main(&init_unit_test_suite, argc, argv); 
#else
	return ::boost::unit_test::unit_test_main(&init_unit_test, argc, argv); 
#endif
}
