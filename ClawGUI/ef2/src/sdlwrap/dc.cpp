#include "dc.hpp"
#include <cstdlib>

#include <misc/exceptions.hpp>
#include <sstream>
#include <lang/text_storage.hpp>
#include <misc/ids.hpp>
#include <guicore/pen_storage.hpp>
#include "sdl_object.hpp"

#pragma warning(push, 0)  
#include <string.h>
#include <wchar.h>
#pragma warning(pop)


// ---- INIITIALIZATION ----

DC::DC(Uint32 initflags):
surface(NULL),
	oldSurface(NULL),

	// evtl gar nicht initialisieren...
	resolution(Size()),
	bitDepth(DEPTH_32BIT),
	bits(0),

	brush(),
	darkBrush(),
	pen(),
	darkPen(),
	pressedPen(),
	darkPressedPen(),
	textColor(),
	endBrush(),
	endDarkBrush(),
	endPen(),
	endDarkPen(),
	endPressedPen(),
	endDarkPressedPen(),
	endTextColor(),

	font(),
	brightness(100), // 100%
	gradient(0),
	dp(),
	pressedRectangle(false),

	Draw_HLine(NULL),
	Draw_VLine(NULL),
	Draw_Line(NULL),
	DrawRound(NULL),
	DrawEdgedRound(NULL),
	DrawTab(NULL),
	changedRectangles(0),
	max_x(0),
	max_y(0),
	max_width(0),
	max_height(0),

	defaultCursor(initAndGetDefaultCursor(initflags))
{
	atexit(SDL_Quit);
}

SDL_Cursor* DC::initAndGetDefaultCursor(Uint32 initflags) {
	if ( SDL_Init(initflags) < 0 ) {
		throw SDLException("ERROR (DC::initSDL()): Could not initialize SDL (" + std::string(SDL_GetError()) + ").");
	}
	return SDL_GetCursor();
}


DC::~DC()
{
	SDL_SetCursor(defaultCursor);
	//	SDL_FreeSurface(surface); TODO?
}


bool DC::setScreen(const Size current_resolution, const eBitDepth bit_depth, const Uint32 nflags)
{
	// no action
	if((current_resolution == resolution) && (bit_depth == bitDepth) && (surface != NULL)) {
		return false;
	}

	resolution = current_resolution;
	max_width = resolution.getWidth();
	max_height = resolution.getHeight();
	max_x = static_cast<Sint16>(max_width - 1);
	max_y = static_cast<Sint16>(max_height - 1);

	switch(bit_depth)
	{
	case DEPTH_8BIT:bits = 8;break;
	case DEPTH_16BIT:bits = 16;break;
	case DEPTH_24BIT:bits = 24;break;
	case DEPTH_32BIT:bits = 32;break;
	case MAX_BITDEPTHS:
	default:
		std::ostringstream os;
		os << "Error creating screen, invalid bit depth (" << static_cast<unsigned int>(bit_depth) << ", see " << SingleStorage<Pen>::DATA_FILE_NAME_BASE << ")";
		throw FileException(os.str());break;
	}

	surface = SDL_SetVideoMode(max_width, max_height, bits, nflags);
	if(surface == NULL) {
		toErrorLog("ERROR (DC::setScreen()): Could not set video mode (" + std::string(SDL_GetError()) + ").");
		return false;
	}

	changedRectangles.push_back(Rect(0, 0, max_width, max_height));

	switch(surface->format->BitsPerPixel)
	{
	case 8:	bitDepth = DEPTH_8BIT;
		Draw_HLine = &DC::Draw_HLine_8bit;
		Draw_VLine = &DC::Draw_VLine_8bit;
		Draw_Line = &DC::Draw_Line_8bit;
		DrawRound = &DC::DrawRound_8bit;
		DrawEdgedRound = &DC::DrawEdgedRound_8bit;
		DrawTab = &DC::DrawTab_8bit;
		break;

	case 16:bitDepth = DEPTH_16BIT;
		Draw_HLine = &DC::Draw_HLine_16bit;
		Draw_VLine = &DC::Draw_VLine_16bit;
		Draw_Line = &DC::Draw_Line_16bit;
		DrawRound = &DC::DrawRound_16bit;
		DrawEdgedRound = &DC::DrawEdgedRound_16bit;
		DrawTab = &DC::DrawTab_16bit;
		break;

	case 24:bitDepth = DEPTH_24BIT;
		Draw_HLine = &DC::Draw_HLine_24bit;
		Draw_VLine = &DC::Draw_VLine_24bit;
		Draw_Line = &DC::Draw_Line_24bit;
		DrawRound = &DC::DrawRound_24bit;
		DrawEdgedRound = &DC::DrawEdgedRound_24bit;
		DrawTab = &DC::DrawTab_24bit;
		break;

	case 32:bitDepth = DEPTH_32BIT;
		Draw_HLine = &DC::Draw_HLine_32bit;
		Draw_VLine = &DC::Draw_VLine_32bit;
		Draw_Line = &DC::Draw_Line_32bit;
		DrawRound = &DC::DrawRound_32bit;
		DrawEdgedRound = &DC::DrawEdgedRound_32bit;
		DrawTab = &DC::DrawTab_32bit;
		break;

	default:BOOST_ASSERT(false);break;
	}

	SDL_Object::deleteAllRootObjectBuffers();

	return true;
}



// ----- SURFACE OPERATIONS


void DC::switchToSurface(SDL_Surface* temp_surface) 
{
	BOOST_ASSERT(oldSurface == NULL);
	oldSurface = surface;
	surface = temp_surface;
}

void DC::switchToOriginalSurface()
{
	BOOST_ASSERT(oldSurface);
	surface = oldSurface;
	oldSurface = NULL;
}


bool DC::setFullScreen(const bool full_screen)
{
	BOOST_ASSERT(surface);
	if(isFullScreen() != full_screen)
	{
#if defined(__linux__)
		SDL_WM_ToggleFullScreen(surface);
#elif defined(WIN32)
		Uint32 nflags = surface->flags;
		nflags ^= SDL_FULLSCREEN;
		surface = SDL_SetVideoMode(surface->w, surface->h, surface->format->BitsPerPixel, nflags);
#endif
		return true;
	}				
	return false;
}



// ----- DC INTERFACE: -----

const std::string DC::printHardwareInformation()
{
	// TODO: uebersetzen bzw. dem Aufrufer nur Daten uebergeben
	SDL_Rect **modes;
	std::ostringstream os;
	os.str("");
	modes = SDL_ListModes(NULL, SDL_SWSURFACE);
	if(modes == reinterpret_cast<SDL_Rect **>(0)) {
		os << "* " << TextStorage::instance().get(IDS::START_SDL_NO_MODES_AVAILABLE_TEXT_ID)->getText() << std::endl;
	} else {
		if(modes == reinterpret_cast<SDL_Rect **>(-1)) {
			os << "* " << TextStorage::instance().get(IDS::START_SDL_ALL_RESOLUTIONS_AVAILABLE_TEXT_ID)->getText() << std::endl;
		} else
		{
			os << "* " << TextStorage::instance().get(IDS::START_SDL_AVAILABLE_MODES_TEXT_ID)->getText();
			for(unsigned int i = 0; modes[i]; ++i) {
				os << "  " << modes[i]->w << " x " << modes[i]->h;
			}
			os << std::endl;
		}
	}

	const SDL_VideoInfo* hardware = SDL_GetVideoInfo();
	os << " - " << TextStorage::instance().get(IDS::START_SDL_MAX_COLOR_DEPTH_TEXT_ID)->getText() << static_cast<unsigned int>(hardware->vfmt->BitsPerPixel);
	
	if(hardware->hw_available) {
		os << std::endl << "- " << TextStorage::instance().get(IDS::START_SDL_HARDWARE_SURFACES_POSSIBLE_TEXT_ID)->getText();
	}

	if(hardware->wm_available) {
		os << std::endl << "- " << TextStorage::instance().get(IDS::START_SDL_WINDOW_MANAGER_AVAILABLE_TEXT_ID)->getText();
	}

	if(hardware->blit_hw) {
		os << std::endl << "- " << TextStorage::instance().get(IDS::START_SDL_HARDWARE_TO_HARDWARE_BLITS_ACCELERATED_TEXT_ID)->getText();
	}

	if(hardware->blit_hw_CC) {
		os << std::endl << "- " << TextStorage::instance().get(IDS::START_SDL_HARDWARE_TO_HARDWARE_COLORKEY_BLITS_ACCELERATED_TEXT_ID)->getText();
	}

	if(hardware->blit_hw_A) {
		os << std::endl << "- " << TextStorage::instance().get(IDS::START_SDL_HARDWARE_TO_HARDWARE_ALPHA_BLITS_ACCELERATED_TEXT_ID)->getText();
	}

	if(hardware->blit_sw) {
		os << std::endl << "- " << TextStorage::instance().get(IDS::START_SDL_SOFTWARE_TO_HARDWARE_BLITS_ACCELERATED_TEXT_ID)->getText();
	}

	if(hardware->blit_sw_CC) {
		os << std::endl << "- " << TextStorage::instance().get(IDS::START_SDL_SOFTWARE_TO_HARDWARE_COLORKEY_BLITS_ACCELERATED_TEXT_ID)->getText();
	}

	if(hardware->blit_sw_A)	{
		os << std::endl << "- " << TextStorage::instance().get(IDS::START_SDL_SOFTWARE_TO_HARDWARE_ALPHA_BLITS_ACCELERATED_TEXT_ID)->getText();
	}

	if(hardware->blit_fill)	{
		os << std::endl << "- " << TextStorage::instance().get(IDS::START_SDL_COLOR_FILLS_ACCELERATED_TEXT_ID)->getText();
	}

	if(hardware->video_mem > 0) {
		std::string memoryString = TextStorage::instance().get(IDS::START_SDL_TOTAL_VIDEO_MEMORY_TEXT_ID)->getText();
		std::list<std::string> parameterList;
		parameterList.push_back(boost::lexical_cast<std::string>(hardware->video_mem));
		Misc::formatString(memoryString, parameterList);
		os << std::endl << "- " << memoryString;
	}

	return os.str();
}




const std::string DC::printSurfaceInformation()
{
	BOOST_ASSERT(surface);

	std::ostringstream os; os.str("");
	os << surface->w << " x " << surface->h << " @ " << static_cast<unsigned int>(surface->format->BitsPerPixel);
	
	if (surface->flags & SDL_SWSURFACE) {
		os << std::endl << "- " << TextStorage::instance().get(IDS::START_SDL_SURFACE_STORED_IN_SYSTEM_MEMORY_TEXT_ID)->getText();
	} else if(surface->flags & SDL_HWSURFACE) {
		os << std::endl << "- " << TextStorage::instance().get(IDS::START_SDL_SURFACE_STORED_IN_VIDEO_MEMORY_TEXT_ID)->getText();
	}

	if(surface->flags & SDL_ASYNCBLIT) {
		os << std::endl << "- " << TextStorage::instance().get(IDS::START_SDL_SURFACE_USES_ASYNCHRONOUS_BLITS_TEXT_ID)->getText();
	}

	if(surface->flags & SDL_ANYFORMAT) {
		os << std::endl << "- " << TextStorage::instance().get(IDS::START_SDL_SURFACE_ALLOWS_ANY_PIXEL_FORMAT_TEXT_ID)->getText();
	}

	if(surface->flags & SDL_HWPALETTE) {
		os << std::endl << "- " << TextStorage::instance().get(IDS::START_SDL_SURFACE_HAS_EXCLUSIVE_PALETTE_TEXT_ID)->getText();
	}

	if(surface->flags & SDL_DOUBLEBUF) {
		os << std::endl << "- " << TextStorage::instance().get(IDS::START_SDL_SURFACE_IS_DOUBLE_BUFFERED_TEXT_ID)->getText();
	}

	if(surface->flags & SDL_OPENGL) {
		os << std::endl << "- " << TextStorage::instance().get(IDS::START_SDL_SURFACE_HAS_OPENGL_CONTEXT_TEXT_ID)->getText();
	}

	if(surface->flags & SDL_OPENGLBLIT) {
		os << std::endl << "- " << TextStorage::instance().get(IDS::START_SDL_SURFACE_SUPPORTS_OPENGL_BLITTING_TEXT_ID)->getText();
	}

	if(surface->flags & SDL_RESIZABLE) {
		os << std::endl << "- " << TextStorage::instance().get(IDS::START_SDL_SURFACE_IS_RESIZABLE_TEXT_ID)->getText();
	}

	if(surface->flags & SDL_HWACCEL) {
		os << std::endl << "- " << TextStorage::instance().get(IDS::START_SDL_SURFACE_BLIT_USES_HARDWARE_ACCELERATION_TEXT_ID)->getText();
	}

	if(surface->flags & SDL_SRCCOLORKEY) {
		os << std::endl << "- " << TextStorage::instance().get(IDS::START_SDL_SURFACE_USES_COLORKEY_BLITTING_TEXT_ID)->getText();
	}

	if(surface->flags & SDL_RLEACCEL) {
		os << std::endl << "- " << TextStorage::instance().get(IDS::START_SDL_COLORKEY_BLITTING_RLE_ACCELERATED_TEXT_ID)->getText();
	}

	if(surface->flags & SDL_SRCALPHA) {
		os << std::endl << "- " << TextStorage::instance().get(IDS::START_SDL_BLIT_USES_ALPHA_BLENDING_TEXT_ID)->getText();
	}

	if(surface->flags & SDL_PREALLOC) {
		os << std::endl << "- " << TextStorage::instance().get(IDS::START_SDL_SURFACE_USES_PREALLOCATED_MEMORY_TEXT_ID)->getText();
	}
	
	if(SDL_MUSTLOCK(surface)) {
		os << std::endl << "- " << TextStorage::instance().get(IDS::START_SDL_SURFACE_NEEDS_LOCKING_TEXT_ID)->getText();
	}

	return os.str();
}






// ----- SCREEN UPDATE 

void DC::addRectangle(const Rect& rect)
{
	//Größe des Rechtecks (größere testen ob sie es beinhalten, kleinere testen ob sie umgeben werden)
	//Position des Rechtecks: rechte untere Ecke, linke obere Ecke, Quadtrees, dynamisch angepasste Trees

	if(isRectOutside(rect)) {
		return;
	}

	// cut borders
	Point p = Point(cutLeft(rect.getLeft()), cutTop(rect.getTop()));
	Size s = Size(cutWidth(rect.getLeft(), rect.getWidth()), cutHeight(rect.getTop(), rect.getHeight()));

	std::list<Rect> rects = Rect(p, s).removeRects(changedRectangles);
	changedRectangles.insert(changedRectangles.end(), rects.begin(), rects.end());
}



void DC::updateScreen()
{
	BOOST_ASSERT(surface);

	int changedRectanglesCount = changedRectangles.size();

	if(changedRectanglesCount > 0) {
		if ( (surface->flags & SDL_DOUBLEBUF) == SDL_DOUBLEBUF ) {
			SDL_Flip(surface);
			std::cout << "Flip!" << std::endl;
		} else 
		{
			SDL_Rect* changedSDLRectangles = new SDL_Rect[changedRectanglesCount];
			int j = 0;
			for(std::list<Rect>::const_iterator i = changedRectangles.begin(); i != changedRectangles.end(); i++) {
				/*std::ostringstream os;
				os << i->toString() << std::endl;
				std::cout << os.str();*/
				changedSDLRectangles[j] = Rect::createRect(*i);
				j++;
			}
			SDL_UpdateRects(surface, changedRectanglesCount, changedSDLRectangles);
			delete[] changedSDLRectangles; 
		}
	}
	changedRectangles.clear();
}



// ---- DRAWING

void DC::DrawBitmap(const SDL_Surface* bitmap, const Sint16 x, const Sint16 y) const
{
	// outside of screen
	if(x > max_x || y > max_y || static_cast<Sint16>(x + bitmap->w) <= ZERO_SINT16 || static_cast<Sint16>(y + bitmap->h) <= ZERO_SINT16) {
		return;
	}

	Sint16 sx = cutLeft(x);
	Sint16 sy = cutTop(y);
	Sint16 cx = static_cast<Sint16>(sx - x);
	Sint16 cy = static_cast<Sint16>(sy - y);
	Uint16 cw = cutWidth(x, static_cast<Uint16>(bitmap->w));
	Uint16 ch = cutHeight(y, static_cast<Uint16>(bitmap->h));

	// clip the rect?
	if(sx != cx || sy != cy || cw != static_cast<Uint16>(bitmap->w) || ch != static_cast<Uint16>(bitmap->h)) {
		DrawBitmap(bitmap, sx, sy, Rect(Point(cx, cy), Size(cw, ch)));
	} else {
		SDL_Rect drect = Rect::createRect(Point(x, y), Size());
		SDL_BlitSurface(const_cast<SDL_Surface*>(bitmap), NULL, surface, &drect);
	}
}


// clipped bitmap
void DC::DrawBitmap(const SDL_Surface* bitmap, const Sint16 x, const Sint16 y, const Rect& clip_rect) const
{
	SDL_Rect srect = Rect::createRect(clip_rect);
	// size of drect is ignored by SDL_BlitSurface
	SDL_Rect drect = Rect::createRect(Point(x, y), Size());

	if((clip_rect.getLeft() > static_cast<Sint16>(x + srect.w)) || (clip_rect.getTop() > static_cast<Sint16>(y + srect.h)) || (clip_rect.getBottom() < y) || (clip_rect.getRight() < x)) {
		return;
	}

	if(clip_rect.getLeft() > 0)
	{
		drect.x = static_cast<Sint16>(x + clip_rect.getLeft());
	}

	if(clip_rect.getTop() > 0)
	{
		drect.y = static_cast<Sint16>(y + clip_rect.getTop());
	}

	SDL_BlitSurface(const_cast<SDL_Surface*>(bitmap), &srect, surface, &drect);
}

void DC::DrawLine(const Sint16 x0, const Sint16 y0, const Sint16 x1, const Sint16 y1) const
{
	BOOST_ASSERT(x0 >= ZERO_SINT16 && y0 >= ZERO_SINT16 && x0 <= max_x && y0 <= max_y && x1 >= ZERO_SINT16 && y1 >= ZERO_SINT16 && x1 <= max_x && y1 <= max_y);

	if(pen->getStyle() == TRANSPARENT_PEN_STYLE) {
		return;
	}
	Sint16 xx1, xx2, yy1, yy2;
	if(x0>x1) {
		xx1 = x1; xx2 = x0; yy1 = y1; yy2 = y0;
	} else {
		xx1 = x0; xx2 = x1; yy1 = y0; yy2 = y1;
	}

	if((xx1 < static_cast<Sint16>(pen->getWidth()/2)) || (yy1 < static_cast<Sint16>(pen->getWidth()/2+1)) || (yy2 < static_cast<Sint16>(pen->getWidth()/2)) ||
		(xx2 > static_cast<Sint16>(max_x - pen->getWidth()/2)) || (yy1 > static_cast<Sint16>(max_y - pen->getWidth()/2)) || (yy2 >= static_cast<Sint16>(max_y - pen->getWidth()/2))) {
			return;
	}

	if(yy1 == yy2)
	{
		if(xx1 == xx2) {
			return;
		}
		if(pen->getWidth()>1)
		{
			SDL_Rect rc = Rect::createRect(xx1/*-pen->getWidth()/2*/, yy1/*-pen->getWidth()/2*/, static_cast<Sint16>(xx2 - xx1/*+pen->getWidth()*/), pen->getWidth());
			SDL_FillRect(surface, &rc, static_cast<Uint32>(getPenColor()));
		} else {
			(*this.*Draw_HLine)(xx1, yy1, xx2);
		}
	} else
		if(xx1 == xx2)
		{
			if(yy1>yy2) {
				{Sint16 swp=yy1;yy1=yy2;yy2=swp;}
			}
			if(pen->getWidth()>1)
			{
				SDL_Rect rc = Rect::createRect(xx1/*-pen->getWidth()/2*/, yy1/*-pen->getWidth()/2*/, pen->getWidth(), static_cast<Sint16>(yy2-yy1/*+pen->getWidth()*/));
				SDL_FillRect(surface, &rc, static_cast<Uint32>(getPenColor()));
			} else {
				(*this.*Draw_VLine)(xx1, yy1, yy2);
			}
		} else
		{
			callDrawLine(xx1, yy1, xx2, yy2);
			if(pen->getWidth()==2)
			{
				//			const Color c = getPenColor();
				//			const_cast<DC*>(this)->pen->setColor(Color(surface, static_cast<Uint8>(c->r()*0.5),  static_cast<Uint8>(c->g()*0.5), static_cast<Uint8>(c->b()*0.5)));
				callDrawLine(xx1, static_cast<Sint16>(yy1+1), xx2, static_cast<Sint16>(yy2+1));
				callDrawLine(xx1, yy1, xx2, yy2);
				callDrawLine(xx1, static_cast<Sint16>(yy1-1), xx2, static_cast<Sint16>(yy2-1));
				//			const_cast<DC*>(this)->pen->setColor(c);
			}
		}
}

void DC::callDrawLine(const Sint16 x0, const Sint16 y0, const Sint16 x1, const Sint16 y1) const {
	BOOST_ASSERT(static_cast<Uint16>(x1+1) >= x0 && y1 >= 0);
	Sint16 dx = static_cast<Uint16>(x1 - x0 + 1);
	Sint16 dy = static_cast<Uint16>(y1 - y0);
	Sint16 sy = (dy >= 0) ? 1 : -1;
	dy = static_cast<Sint16>(sy * dy + 1);
	Sint16 pixx = 2;
	Sint16 pixy = surface->pitch;
	pixy = static_cast<Sint16>(pixy * sy);
	if (dx < dy) {
		Sint16 swaptmp = dx; dx = dy; dy = swaptmp;
		swaptmp = pixx; pixx = pixy; pixy = swaptmp;
	}

	(*this.*Draw_Line)(x0, y0, dx, dy, pixx, pixy);
}

// TODO dp!
void DC::DrawSpline(const unsigned int c, const Point* p) const
{
	if((pen->getStyle() == TRANSPARENT_PEN_STYLE) || (c < 2)) {
		return;
	}
	for(unsigned int i = c-1; i--;)
		//	{
		//		aalineColor(surface, p[i].x, p[i].y, p[i+1].x, p[i+1].y, static_cast<Uint32>(getPenColor()));
		//		aalineColor(surface, p[i].x, p[i].y+1, p[i+1].x, p[i+1].y+1, static_cast<Uint32>(getPenColor()));
		//	}
	{
		/*		if((i>0)&&(i<c-2))
		{
		DrawLine(p[i].x, p[i].y + (p[i].y < p[i-1].y) + (p[i].y < p[i+1].y) - (p[i].y > p[i-1].y) - (p[i].y > p[i+1].y),
		p[i+1].x, p[i+1].y + (p[i+1].y < p[i].y) + (p[i+1].y < p[i+2].y) - (p[i+1].y > p[i].y) - (p[i+1].y > p[i+2].y));
		DrawLine(p[i].x, p[i].y + (p[i].y < p[i-1].y) + (p[i].y < p[i+1].y) - (p[i].y > p[i-1].y) - (p[i].y > p[i+1].y) + 1,
		p[i+1].x, p[i+1].y + (p[i+1].y < p[i].y) + (p[i+1].y < p[i+2].y) - (p[i+1].y > p[i].y) - (p[i+1].y > p[i+2].y) + 1);
		} else*/
		{
			Point p1 = dp + p[i];
			Point p2 = dp + p[i+1];
			DrawLine(p1.getX(), p1.getY(), p2.getX(), p2.getY());
			//			DrawLine(p[i].x, p[i].y+1, p[i+1].x, p[i+1].y+1);
		}
	}
}

void DC::DrawSpline(const unsigned int c, const Point* p, const Point s) const
{
	if((pen->getStyle() == TRANSPARENT_PEN_STYLE) || (c < 2)) {
		return;
	}
	Point sp = s + dp;
	for(unsigned int i = c-1; i--;)
		//	{
		//		aalineColor(surface, p[i].x, p[i].y, p[i+1].x, p[i+1].y, static_cast<Uint32>(getPenColor()));
		//		aalineColor(surface, p[i].x, p[i].y+1, p[i+1].x, p[i+1].y+1, static_cast<Uint32>(getPenColor()));
		//	}
	{
		/*		if((i>0)&&(i<c-2))
		{
		DrawLine(p[i].x, p[i].y + (p[i].y < p[i-1].y) + (p[i].y < p[i+1].y) - (p[i].y > p[i-1].y) - (p[i].y > p[i+1].y),
		p[i+1].x, p[i+1].y + (p[i+1].y < p[i].y) + (p[i+1].y < p[i+2].y) - (p[i+1].y > p[i].y) - (p[i+1].y > p[i+2].y));
		DrawLine(p[i].x, p[i].y + (p[i].y < p[i-1].y) + (p[i].y < p[i+1].y) - (p[i].y > p[i-1].y) - (p[i].y > p[i+1].y) + 1,
		p[i+1].x, p[i+1].y + (p[i+1].y < p[i].y) + (p[i+1].y < p[i+2].y) - (p[i+1].y > p[i].y) - (p[i+1].y > p[i+2].y) + 1);
		} else*/
		{
			Point p1 = sp + p[i];
			Point p2 = sp + p[i+1];
			DrawLine(p1.getX(), p1.getY(), p2.getX(), p2.getY());
			//		DrawLine(s.x + p[i].x, s.y + p[i].y+1, s.x + p[i+1].x, s.y + p[i+1].y+1);
		}
	}

}
void DC::DrawText(const std::string& text, const Sint16 x, const Sint16 y) const 
{
	Size s = font->getTextExtent(text);
	//BOOST_ASSERT(x >= ZERO_SINT16 && y >= ZERO_SINT16 && x <= max_x && y <= max_y && static_cast<Uint16>(x + s.getWidth()) <= max_width && static_cast<Uint16>(y + s.getHeight()) <= max_height);
	if(!(x >= ZERO_SINT16 && y >= ZERO_SINT16 && x <= max_x && y <= max_y && static_cast<Uint16>(x + s.getWidth()) <= max_width && static_cast<Uint16>(y + s.getHeight()) <= max_height)) {
		return;
	}

	if(font->isShadow()) {
		font->DrawText(surface, Color::toSDL_Color(), text, static_cast<Sint16>(x+font->getSize()/6), static_cast<Sint16>(y+font->getSize()/6));
	}

	font->DrawText(surface, *textColor, text, x, y);
	if(font->isUnderlined())
	{		
		SDL_Rect r = Rect::createRect(x, static_cast<Sint16>(y+s.getHeight()*2/3), s.getWidth(), 1);
		SDL_FillRect(surface, &r, *textColor);
	}

}




void DC::DrawEdgedRoundedRectangle(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height, const Uint16 radius) const
{
	BOOST_ASSERT(static_cast<Uint16>(x + width) <= max_width && static_cast<Uint16>(y + height) <= max_height && x >= ZERO_SINT16 && y >= ZERO_SINT16);
	if((width < 2) || (height < 2)|| (x > max_x) || (y > max_y) || (x < ZERO_SINT16) || (y < ZERO_SINT16)) {
		return;
	}

	Uint16 mw = cutWidth(x, width);
	Uint16 mh = cutHeight(y, height);

	if((radius <= 1) || (mw < 2*radius) || (mh < 2*radius))	{
		DrawEmptyRectangle(x, y, mw, mh);
		return;
	}

	(*this.*DrawEdgedRound)(x, y, mw, mh, radius);
}

void DC::DrawRoundedRectangle(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height, const Uint16 radius) const
{
	BOOST_ASSERT(x+width <= max_x && y+height <= max_y && x >= ZERO_SINT16 && y >= ZERO_SINT16);

	if((width < 2) || (height < 2) || (x + width >= getMaxX()) || (y + height >= getMaxY()) || (x < 0) || (y < ZERO_SINT16)) {
		return;
	}

	if((radius <= 1)||(width<2*radius)||(height<2*radius))	{
		DrawRectangle(x,y, width, height);
		return;
	}

	(*this.*DrawRound)(x, y, width, height, radius);
}


void DC::DrawTabRectangle(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height) const
{
	BOOST_ASSERT(x+width <= max_x && y+height <= max_y && x >= 0 && y >= ZERO_SINT16);

	if((width<2) || (height<2) || (x+width >= getMaxX()) || (y + height >= getMaxY()) || (x < ZERO_SINT16) || (y < ZERO_SINT16)) {
		return;
	}

	(*this.*DrawTab)(x, y, width, height);
}


void DC::DrawRectangle(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height) const
{
	BOOST_ASSERT((x+width <= max_x) && (y+height <= max_y) && (x >= ZERO_SINT16) && (y >= ZERO_SINT16));

	if((width<2) || (height<2) || (width>getMaxX()) || (height>getMaxY()) || (x<ZERO_SINT16) || (y<ZERO_SINT16)) {
		return;
	}

	if(brush->getStyle() != TRANSPARENT_BRUSH_STYLE) {
		SDL_Rect rc = Rect::createRect(Point(x, y) + Size(pen->getWidth(), pen->getWidth()), Size(width, height) - Size(static_cast<Uint16>(2*pen->getWidth()), static_cast<Uint16>(2*pen->getWidth())));
		SDL_FillRect(surface, &rc, static_cast<Uint32>(getBrushColor()) );
	}
	DrawEmptyRectangle(x, y, width, height);
}

void DC::DrawEmptyRectangle(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height) const
{
	BOOST_ASSERT(static_cast<Uint16>(x+width) <= max_width && static_cast<Uint16>(y+height) <= max_height && x >= ZERO_SINT16 && y >= ZERO_SINT16);

	if(pen->getStyle()==TRANSPARENT_PEN_STYLE)  {
		return;
	}

	if((width<2) || (height<2) || (width>max_width) || (height>max_height) || (x<ZERO_SINT16) || (y<ZERO_SINT16)) {
		return;
	}

	Uint32 pen_col;
	Uint32 dark_pen_col;
	if(pressedRectangle)
	{
		pen_col = static_cast<Uint32>(getPressedPenColor());
		dark_pen_col = static_cast<Uint32>(getDarkPressedPenColor());	
	} else
	{
		pen_col = static_cast<Uint32>(getPenColor());
		dark_pen_col = static_cast<Uint32>(getDarkPenColor());
	}

	Point p(Point(x, y) - Size(static_cast<Uint16>(pen->getWidth()>>1), static_cast<Uint16>(pen->getWidth()>>1)));

	SDL_Rect rc = Rect::createRect(p.getX(), p.getY(), width, pen->getWidth());
	SDL_FillRect(surface, &rc, pen_col);

	rc = Rect::createRect(p.getX(), static_cast<Sint16>(p.getY() + height - 1), width, pen->getWidth());
	SDL_FillRect(surface, &rc, dark_pen_col);

	rc = Rect::createRect(p.getX(), p.getY(), pen->getWidth(), height);
	SDL_FillRect(surface, &rc, pen_col);

	rc = Rect::createRect(static_cast<Sint16>(p.getX() + width - 1), p.getY(), pen->getWidth(), height);
	SDL_FillRect(surface, &rc, dark_pen_col);
}

void DC::DrawVerticalLine(const Sint16 x0, const Sint16 y0, const Sint16 y1) const
{
	BOOST_ASSERT(x0 <= max_x && y0 <= max_y && y1 <= max_y && x0 >= ZERO_SINT16 && y0 >= ZERO_SINT16 && y1 >= ZERO_SINT16);

	(*this.*Draw_VLine)(x0, cutTop(y0), cutBottom(y1));
}

void DC::DrawHorizontalLine(const Sint16 x0, const Sint16 y0, const Sint16 x1) const
{
	BOOST_ASSERT(x0 <= max_x && y0 <= max_y && x1 <= max_x && x0 >= ZERO_SINT16 && y0 >= ZERO_SINT16 && x1 >= ZERO_SINT16);

	(*this.*Draw_HLine)(cutLeft(x0), y0, cutRight(x1));
}


const char* DC::dcVersion = "2.00";
const Sint16 DC::ZERO_SINT16 = static_cast<Sint16>(0);
const Sint16 DC::ZERO_UINT16 = static_cast<Uint16>(0);





#if 0
void DC::DrawGridEdgedRoundedRectangle(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height, const Uint16 int radius, std::list<Rect> notDrawRectList) const 
{
	return;
	if((width<2)||(height<2)) return;
	if((x>=getMaxX())||(x<0)) return;
	if((y>=getMaxY())||(y<0)) return;
	unsigned int ww = cutWidth(x, width);
	unsigned int hh = cutHeight(y, height);
	bool rounded = false;
	if((radius <= 1)||(ww<2*radius)||(hh<2*radius))
		rounded=true;

	signed int xx = x;
	signed int yy = y;
	unsigned int lastHeight = 0;

	std::list<Rect>::const_iterator i = notDrawRectList.begin();
	while(i!=notDrawRectList.end())
	{
		lastHeight=0;
		while((i!=notDrawRectList.end())&&(yy == i->getTop()))
		{
			DrawRectangle(xx, yy, i->getLeft() - xx, i->getHeight());
			lastHeight = i->getHeight();
			xx = i->getLeft() + i->getWidth();
			i++;
		}
		// rechter Rand
		DrawRectangle(xx, yy, x+ww - xx, lastHeight);
		// neue Zeile
		xx = x;
		yy += lastHeight;
		if((i!=notDrawRectList.end())&&(yy < i->getTop()))
		{
			DrawRectangle(xx, yy, ww, i->getTop() - yy);
			yy = i->getTop();
			xx = x;
		}
	}
	DrawRectangle(xx, yy, x+ww - xx, y + hh - yy);		

	/*	if(rounded) {
	DrawRectangle(x,y,ww,hh);
	return;
	}

	if (brush->getStyle() != TRANSPARENT_BRUSH_STYLE)
	DrawFilledEdgedRound(x, y, ww, hh, radius);
	if (pen->getStyle() != TRANSPARENT_PEN_STYLE)
	DrawEmptyEdgedRound(x, y, ww, hh, radius);*/
}
#endif



#if 0 
TODO
	void DC::DrawBrightenedBitmap(const SDL_Surface* bitmap, const Sint16 x, const Sint16 y, const Rect& clip_rect, const Uint8 brightness) const
{
	//	if(brightness == 100)
	//	{
	SDL_SetAlpha((SDL_Surface*)bitmap, SDL_SRCALPHA, static_cast<Uint8>(brightness * 255 / 100));
	DrawBitmap(bitmap, x, y, clip_rect);
	SDL_SetAlpha((SDL_Surface*)bitmap, SDL_SRCALPHA, 255);
	return;
	//	}
	//	double brightness_percent = brightness / 100;
	/*	SDL_Surface* neu = SDL_CreateRGBSurface(SDL_SWSURFACE, bitmap->w, bitmap->h, 8, 0, 0, 0, 0);
	Uint32* pc = (Uint32*)(bitmap->pixels);
	Uint32* dst = (Uint32*)(neu->pixels);

	for(unsigned int i = bitmap->w * bitmap->h; i--;)
	{
	Uint8 r,g,b;
	SDL_GetRGB(*pc, bitmap->format, &r, &g, &b);
	//		r = r/2;// * brightness_percent; if(r > 255) r = 255;
	//		g = g/2;// * brightness_percent; if(g > 255) g = 255;
	//		b = b/2;// * brightness_percent; if(b > 255) b = 255;
	*dst = SDL_MapRGB(bitmap->format, r, g, b);
	++pc;
	++dst;
	}
	DrawBitmap(neu, x, y, clip_rect);
	SDL_FreeSurface(neu);*/
	//TODO
}

void DC::DrawBrightenedBitmap(const SDL_Surface* bitmap, const Sint16 x, const Sint16 y, const Uint8 brightness) const
{
	//	if(brightness == 100)
	//	{
	SDL_SetAlpha((SDL_Surface*)bitmap, SDL_SRCALPHA, static_cast<Uint8>(brightness * 255 / 100));
	DrawBitmap(bitmap, x, y);
	SDL_SetAlpha((SDL_Surface*)bitmap, SDL_SRCALPHA, 255);
	return;
	//	}

	//	double brightness_percent = brightness / 100;
	/*	SDL_Surface* neu = SDL_CreateRGBSurface(SDL_SWSURFACE, bitmap->w, bitmap->h, 8, 0, 0, 0, 0);
	Uint32* pc = (Uint32*)(bitmap->pixels);
	Uint32* dst = (Uint32*)(neu->pixels);

	for(unsigned int i = bitmap->w * bitmap->h; i--;)
	{
	Uint8 r,g,b;
	SDL_GetRGB(*pc, bitmap->format, &r, &g, &b);
	//		r = r /2;// *brightness_percent; if(r > 255) r = 255;
	//		g = g /2;// *brightness_percent; if(g > 255) g = 255;
	//		b = b /2;// *brightness_percent; if(b > 255) b = 255;
	//		*((Uint32*)((Uint8*)surface->pixels + (Ycenter-i)*surface->pitch + ((Xcenter - radius)<<2) )) = pen_col;
	*dst = SDL_MapRGB(bitmap->format, r, g, b);
	++pc;
	++dst;
	}
	DrawBitmap(neu, x, y);
	SDL_FreeSurface(neu);*/
}
#endif