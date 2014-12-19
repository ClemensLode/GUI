#include "dc.hpp"

void DC::Draw_VLine_32bit(const Sint16 x0, const Sint16 y0, const Sint16 y1) const
{
	BOOST_ASSERT(static_cast<Sint16>(y1+1) > y0);
	Uint32 pen_col = static_cast<Uint32>(getPenColor());

	register Uint8 *p = static_cast<Uint8*>(surface->pixels) + y0 * surface->pitch + (x0 << 2);
	int i = y1 - y0 + 1;

	Lock();

	if(pen->getStyle() == SHORT_DASH_PEN_STYLE)
	{
		for(;i--;)
		{
			if(((i%5) != 2) && ((i%5) != 3)) {
				*reinterpret_cast<Uint32*>(p) = pen_col;
			}
			p += surface->pitch;
		}
	} else
	{
		for(;i--; p+=surface->pitch) {
			*reinterpret_cast<Uint32*>(p) = pen_col;
		}
	}

	Unlock();
}


void DC::Draw_HLine_32bit(const Sint16 x0, const Sint16 y0, const Sint16 x1) const
{
	BOOST_ASSERT(static_cast<Sint16>(x1+1) > x0);
	Uint32 pen_col = static_cast<Uint32>(getPenColor());

	Lock();

# pragma warning( push )
# pragma warning( disable:4127 )
	if (sizeof(wchar_t) == sizeof(Uint32)) { 
# pragma warning( pop )

#if defined(__linux__)
		wmemset(reinterpret_cast<wchar_t*>( static_cast<Uint8*>(surface->pixels) +  y0 * surface->pitch + (x0 << 2)), pen_col, x1-x0+1);
#elif defined(WIN32)
		memset(reinterpret_cast<wchar_t*>( static_cast<Uint8*>(surface->pixels) +  y0 * surface->pitch + (x0 << 2)), pen_col, x1-x0+1);
#endif
	} else 
	{
		register Uint8* p = static_cast<Uint8*>(surface->pixels) + y0 * surface->pitch + (x0 << 2);
		int i = x1 - x0 + 1;
		for(; i--; p+=4) {
			*reinterpret_cast<Uint32*>(p) = pen_col;
		}
	}

	Unlock();
}





void DC::Draw_Line_32bit(const Sint16 x0, const Sint16 y0, const Sint16& dx, const Sint16& dy, const Sint16& pixx, const Sint16& pixy) const
{
	Uint32 col = static_cast<Uint32>(getPenColor());
	int x = 0;
	int y = 0;
	Uint8* pixel = (static_cast<Uint8*>(surface->pixels)) + pixx * x0 + pixy * y0;
	Lock();
	for (; x < dx; ++x, pixel += pixx) {
		*reinterpret_cast<Uint32*>(pixel) = static_cast<Uint32>(col);
		y += dy;
		if (y >= dx) {
			y -= dx;
			pixel += pixy;
		}
	}
	Unlock();
}




// -------- ------------ --------
// -------- FILLED ROUND --------
// -------- ------------ --------







void DC::DrawRound_32bit(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height, const Uint16 corner) const
{
	// Ecke links oben
	Sint16 Xcenter = static_cast<Sint16>(x+corner);
	Sint16 Ycenter = static_cast<Sint16>(y+corner);
	// Kantenlaengen
	Uint16 dx = static_cast<Uint16>(width - (corner << 1));
	Uint16 dy = static_cast<Uint16>(height - (corner << 1));
	// Ecke rechts unten
	Sint16 X2center = static_cast<Sint16>(Xcenter + dx - 1);
	Sint16 Y2center = static_cast<Sint16>(Ycenter + dy - 1);

	if(brush->getStyle() != TRANSPARENT_BRUSH_STYLE) {
		Uint32 col = static_cast<Uint32>(getBrushColor());

		// FILLED
		// Rechteck von linker Kante nach rechter Kante
		if(dy > 0)
		{
			SDL_Rect r;
			r.x = static_cast<Sint16>(x+1); 
			r.y = Ycenter;
			r.w = static_cast<Uint16>(width-1); 
			r.h = dy;
			SDL_FillRect(surface, &r, col);
		}

		// Rechteck entlang der oberen und entlang der unteren Kante
		if((corner > 0) && (dx > 0))
		{
			SDL_Rect r;
			r.x = Xcenter; 
			r.y = static_cast<Sint16>(y+1);
			r.w = dx; 
			r.h = static_cast<Uint16>(corner-1);
			SDL_FillRect(surface, &r, col);

			r.x = Xcenter; r.y = Y2center;
			r.w = dx; r.h = corner;
			SDL_FillRect(surface, &r, col);
		}

		Uint16 rightInc = 6;
		Sint16 diagonalInc = static_cast<Sint16>(10 - (corner << 2));
		Sint16 d = static_cast<Sint16>(3 - (corner << 1));
		Uint16 radius = corner;
		int i = 0;

		Lock();
		while (i <= radius) 
		{

			// Nur Ecken:
#if defined(__linux__)
			// links oben
			wmemset(reinterpret_cast<wchar_t*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + ((Xcenter - i +1)<<2) ), col, i);
			wmemset(reinterpret_cast<wchar_t*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + ((Xcenter - radius + 1)<<2) ), col, radius);
			// rechts oben
			wmemset(reinterpret_cast<wchar_t*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + (X2center<<2) ), col, i);
			wmemset(reinterpret_cast<wchar_t*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + (X2center<<2) ), col, radius);
			// links unten
			wmemset(reinterpret_cast<wchar_t*>(static_cast<Uint8*>(surface->pixels) + (Y2center+radius)*surface->pitch + ((Xcenter - i + 1)<<2) ), col, i);
			wmemset(reinterpret_cast<wchar_t*>(static_cast<Uint8*>(surface->pixels) + (Y2center+i)*surface->pitch + ((Xcenter - radius + 1)<<2) ), col, radius);
			// rechts unten
			wmemset(reinterpret_cast<wchar_t*>(static_cast<Uint8*>(surface->pixels) + (Y2center+radius)*surface->pitch + (X2center<<2) ), col, i);
			wmemset(reinterpret_cast<wchar_t*>(static_cast<Uint8*>(surface->pixels) + (Y2center+i)*surface->pitch + (X2center<<2) ), col, radius);
#elif defined(WIN32)
			for(int k=i; k--;)
			{
				*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + k+ (Ycenter-radius)*surface->pitch + ((Xcenter - i)<<2) )) = col;
				*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + k+(Ycenter-radius)*surface->pitch + (X2center<<2) )) = col;
				*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + k+(Y2center+radius)*surface->pitch + (X2center<<2) )) = col;
				*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + k+(Y2center+radius)*surface->pitch + ((Xcenter-i)<<2) )) = col;

			}
			for(int k=radius; k--;)
			{
				*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + k+(Ycenter-i)*surface->pitch + ((Xcenter - radius)<<2) )) = col;
				*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + k+(Ycenter-i)*surface->pitch + (X2center<<2) )) = col;
				*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + k+(Y2center+i)*surface->pitch + (X2center<<2) )) = col;
				*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + k+(Y2center+i)*surface->pitch + ((Xcenter-radius)<<2) )) = col;
			}
#endif
			if (d >= 0) 
			{
				d = static_cast<Sint16>(d + diagonalInc);
				diagonalInc = static_cast<Sint16>(diagonalInc + 8);
				--radius;
			} else {
				d = static_cast<Sint16>(d + rightInc);
				diagonalInc = static_cast<Sint16>(diagonalInc + 4);
			}
			rightInc = static_cast<Uint16>(rightInc + 4);
			++i;
		}
		Unlock();
	}

	if(pen->getStyle() != TRANSPARENT_PEN_STYLE) {
		Uint32 pen_col = *pen->getColor();

		{
			register Uint8* p0 = static_cast<Uint8*>(surface->pixels) +	y	* surface->pitch + (Xcenter<<2);
			register Uint8* p1 = static_cast<Uint8*>(surface->pixels) + (y+height-1) * surface->pitch + (Xcenter<<2);
			Lock();
# pragma warning( push )
# pragma warning( disable:4127 )
			if (sizeof(wchar_t) == sizeof(Uint32))
# pragma warning( pop )

			{
#if defined(__linux__)
				wmemset(reinterpret_cast<wchar_t*>(p0), pen_col, dx);
				wmemset(reinterpret_cast<wchar_t*>(p1), pen_col, dx);
#elif defined(WIN32)
				memset(reinterpret_cast<wchar_t*>(p0), pen_col, dx);
				memset(reinterpret_cast<wchar_t*>(p1), pen_col, dx);
#endif
			} else 
			{
				int i = dx;				
				switch( i % 4 ) { 
					do{			
				case 0:	 
					*reinterpret_cast<Uint32*>(p0) = pen_col; p0+=4;		 
					*reinterpret_cast<Uint32*>(p1) = pen_col; p1+=4;		
				case 3:								
					*reinterpret_cast<Uint32*>(p0) = pen_col; p0+=4;		
					*reinterpret_cast<Uint32*>(p1) = pen_col; p1+=4;	 
				case 2:							 
					*reinterpret_cast<Uint32*>(p0) = pen_col; p0+=4;	 
					*reinterpret_cast<Uint32*>(p1) = pen_col; p1+=4;
				case 1:							
					*reinterpret_cast<Uint32*>(p0) = pen_col; p0+=4;
					*reinterpret_cast<Uint32*>(p1) = pen_col; p1+=4;
					}while( (i-=4) > 0 );	
				default:break;
				}
			}
		}
		{ 
			register Uint8* p0 = static_cast<Uint8*>(surface->pixels) + Ycenter*surface->pitch + (x<<2);	 
			register Uint8* p1 = static_cast<Uint8*>(surface->pixels) + Ycenter*surface->pitch + ((x+width-1)<<2);
			int i = dy;
			switch( i % 4 ) {							 
				do{										
			case 0:								 
				*reinterpret_cast<Uint32*>(p0) = pen_col; p0+=surface->pitch;
				*reinterpret_cast<Uint32*>(p1) = pen_col; p1+=surface->pitch;
			case 3:								 
				*reinterpret_cast<Uint32*>(p0) = pen_col; p0+=surface->pitch;
				*reinterpret_cast<Uint32*>(p1) = pen_col; p1+=surface->pitch;
			case 2:								 
				*reinterpret_cast<Uint32*>(p0) = pen_col; p0+=surface->pitch;
				*reinterpret_cast<Uint32*>(p1) = pen_col; p1+=surface->pitch;
			case 1:								 
				*reinterpret_cast<Uint32*>(p0) = pen_col; p0+=surface->pitch;
				*reinterpret_cast<Uint32*>(p1) = pen_col; p1+=surface->pitch;
				}while( (i-=4) > 0 );	
			default:break;
			}
		}	
		{
			Uint16 rightInc = 6;
			Sint16 d = static_cast<Sint16>(3 - (corner << 1));
			Sint16 diagonalInc = static_cast<Sint16>( 10 - (corner<<2));	
			int radius = corner;
			int i = 0;	

			while (i <= radius) 
			{
				*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + ((Xcenter - radius)<<2) )) = pen_col;
				*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + ((Xcenter - i)<<2) )) = pen_col;

				*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + ((X2center + i)<<2) )) = pen_col;
				*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + ((X2center + radius)<<2) )) = pen_col;

				*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + (Y2center+radius)*surface->pitch + ((X2center + i)<<2) )) = pen_col;
				*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + (Y2center+i)*surface->pitch + ((X2center + radius)<<2) )) = pen_col;

				*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + (Y2center+radius)*surface->pitch + ((Xcenter - i)<<2) )) = pen_col;
				*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + (Y2center+i)*surface->pitch + ((Xcenter - radius)<<2) )) = pen_col;

				if (d >= 0) {
					d = static_cast<Sint16>(d + diagonalInc);
					diagonalInc = static_cast<Sint16>(diagonalInc + 8);
					--radius;
				} else {
					d = static_cast<Sint16>(d + rightInc);
					diagonalInc = static_cast<Sint16>(diagonalInc + 4);
				}
				rightInc = static_cast<Uint16>(rightInc + 4);
				++i;
			}
		}		
		Unlock();	

	}

}


// -------- ------------------- --------
// -------- FILLED EDGED BORDER --------
// -------- ------------------- --------




void DC::DrawEdgedRound_32bit(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height, const Uint16 corner) const
{
	// Ecke links oben
	Sint16 Xcenter = static_cast<Sint16>(x+corner);
	Sint16 Ycenter = static_cast<Sint16>(y+corner);
	// Kantenlaengen
	Uint16 dx = static_cast<Uint16>(width - (corner << 1));
	Uint16 dy = static_cast<Uint16>(height - (corner << 1));
	// Ecke rechts unten
	Sint16 X2center = static_cast<Sint16>(Xcenter + dx - 1);
	Sint16 Y2center = static_cast<Sint16>(Ycenter + dy - 1);

	if(brush->getStyle() != TRANSPARENT_BRUSH_STYLE) {
		Uint32 brush_col;
		if(!pressedRectangle) {
			brush_col = static_cast<Uint32>(getBrushColor());
		}
		else {
			brush_col = static_cast<Uint32>(getDarkBrushColor());
		}

		// Rechteck von linker Kante nach rechter Kante
		if(dy > 0)
		{
			SDL_Rect r;
			r.x = static_cast<Sint16>(x+1); r.y = Ycenter;
			r.w = static_cast<Uint16>(width-1); r.h = dy;
			SDL_FillRect(surface, &r, brush_col);
		}

		// ------ Rechteck entlang der oberen und entlang der unteren Kante ------
		if((corner > 0)&&(dx>0))
		{
			SDL_Rect r;
			r.x = Xcenter; r.y = static_cast<Sint16>(y+1);
			r.w = dx; r.h = static_cast<Uint16>(corner-1);
			SDL_FillRect(surface, &r, brush_col);

			r.x = static_cast<Sint16>(x+1); r.y = Y2center;
			r.w = static_cast<Uint16>(width-corner-1); r.h = corner;
			SDL_FillRect(surface, &r, brush_col);
		}
		// ------- END OF Rechteck oben und unten ------
		Lock();


		// Halbkreis
		{
			Uint16 rightInc = 6;
			Sint16 diagonalInc = static_cast<Sint16>(10 - (corner << 2));
			Sint16 d = static_cast<Sint16>(3 - (corner << 1));
			int radius = corner;
			int i = 0;

			while (i <= radius) 
			{
				for(int k=i; k--;)
				{
					*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + ((k + Xcenter - i)<<2) )) = brush_col;
					*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + ((k + X2center)<<2) )) = brush_col;
					*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + (Y2center+radius)*surface->pitch + ((k + X2center)<<2) )) = brush_col;
				}
				for(int k=radius; k--;)
				{
					*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + ((k + Xcenter - radius)<<2) )) = brush_col;
					*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + ((k + X2center)<<2) )) = brush_col;
					*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + (Y2center+i)*surface->pitch + ((k + X2center)<<2) )) = brush_col;
				}
				if (d >= 0) 
				{
					d = static_cast<Sint16>(d + diagonalInc);
					diagonalInc = static_cast<Sint16>(diagonalInc + 8);
					--radius;
				} else 
				{
					d = static_cast<Sint16>(d + rightInc);
					diagonalInc = static_cast<Sint16>(diagonalInc + 4);
				}
				rightInc = static_cast<Uint16>(rightInc + 4);
				++i;
			}
		}

		Unlock();
	}

	if(pen->getStyle() != TRANSPARENT_PEN_STYLE) {
		Uint32 dark_pen_col, pen_col;
		if(pressedRectangle)
		{
			dark_pen_col = static_cast<Uint32>(getDarkPressedPenColor());
			pen_col = static_cast<Uint32>(getPressedPenColor());

		} else
		{
			dark_pen_col = static_cast<Uint32>(getDarkPenColor());
			pen_col = static_cast<Uint32>(getPenColor());
		}
		// ------ TOP AND LOWER HORIZONTAL LINE ------
		{
			register Uint8* p0 = static_cast<Uint8*>(surface->pixels) + y * surface->pitch + (Xcenter<<2);
			register Uint8* p1 = static_cast<Uint8*>(surface->pixels) + (y+height-1) * surface->pitch + (x<<2);
			int xxx1 = x;
			int xxx2 = y;
			Lock();
# pragma warning( push )
# pragma warning( disable:4127 )
			if (sizeof(wchar_t) == sizeof(Uint32)) { 
# pragma warning( pop )

#if defined(__linux__)
				wmemset(reinterpret_cast<wchar_t*>(p0), pen_col, dx);
				wmemset(reinterpret_cast<wchar_t*>(p1), dark_pen_col, width - corner);
#elif defined(WIN32)
				memset(reinterpret_cast<wchar_t*>(p0), pen_col, dx);
				memset(reinterpret_cast<wchar_t*>(p1), dark_pen_col, width - corner);
#endif
			} else 
			{
				int i = corner;
				for(; i--; p1+=4) {
					*reinterpret_cast<Uint32*>(p1) = dark_pen_col;
				}
				i = dx;
				for(; i--; p0+=4, p1+=4)
				{
					xxx1++;xxx2++;
					*reinterpret_cast<Uint32*>(p0) = pen_col;
					*reinterpret_cast<Uint32*>(p1) = dark_pen_col;
				}
			}
		}
		// ------ END OF TOP AND LOWER HORIZONTAL LINE ------


		// ------ LEFT AND RIGHT VERTICAL LINE ------
		{
			register Uint8* p0 = static_cast<Uint8*>(surface->pixels) + Ycenter*surface->pitch + (x<<2);	 
			register Uint8* p1 = static_cast<Uint8*>(surface->pixels) + Ycenter*surface->pitch + ((x+width-1)<<2);
			int i = dy;

			for(; i--; p0+=surface->pitch, p1+=surface->pitch)
			{
				*reinterpret_cast<Uint32*>(p0) = pen_col;
				*reinterpret_cast<Uint32*>(p1) = dark_pen_col;
			}

			i = corner;
			for(; i--; p0+=surface->pitch) {
				*reinterpret_cast<Uint32*>(p0) = pen_col;
			}
		}
		// ------ END OF LEFT AND RIGHT VERTICAL LINE ------


		{
			Uint16 rightInc = 6;
			Sint16 diagonalInc = static_cast<Sint16>( 10 - (corner<<2));
			Sint16 d = static_cast<Sint16>(3 - (corner << 1));
			int radius = corner;
			int i = 0;

			while (i <= radius) 
			{	
				*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + ((Xcenter - i)<<2))) = pen_col;
				*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + ((Xcenter - radius)<<2))) = pen_col;

				*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + ((X2center + i)<<2))) = pen_col;
				*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + ((X2center + radius)<<2))) = pen_col;

				*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + (Y2center+radius)*surface->pitch + ((X2center + i)<<2))) = dark_pen_col;
				*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + (Y2center+i)*surface->pitch + ((X2center + radius)<<2))) = dark_pen_col;

				if (d >= 0) 
				{
					d = static_cast<Sint16>(d + diagonalInc);
					diagonalInc = static_cast<Sint16>(diagonalInc + 8);
					--radius;
				} else 
				{
					d = static_cast<Sint16>(d + rightInc);
					diagonalInc = static_cast<Sint16>(diagonalInc + 4);
				}
				rightInc = static_cast<Uint16>(rightInc + 4);
				++i;
			}
		}


		Unlock();
	}

}




// -------- --- --------
// -------- TAB --------
// -------- --- --------









void DC::DrawTab_32bit(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height) const
{
	Uint16 corner = 4;
	if(height < (corner << 1) || width < (corner << 1)) {
		return;
	}
	// Ecke links oben
	Sint16 Xcenter = static_cast<Sint16>(x+corner);
	Sint16 Ycenter = static_cast<Sint16>(y+corner);
	// Kantenlaengen
	Uint16 dx = static_cast<Uint16>(width - (corner << 1));
	Uint16 dy = static_cast<Uint16>(height - (corner << 1));
	// Ecke rechts unten
	Sint16 X2center = static_cast<Sint16>(Xcenter + dx - 1);

	if(brush->getStyle() != TRANSPARENT_BRUSH_STYLE) {

		Uint32 brush_col;
		if(pressedRectangle) {
			brush_col = static_cast<Uint32>(getBrushColor());
		} else {
			brush_col = static_cast<Uint32>(getDarkBrushColor());
		}

		// Rechteck von linker Kante nach rechter Kante
		if(dy > 0)
		{
			SDL_Rect r;
			r.x = static_cast<Sint16>(x+1); r.y = Ycenter;
			r.w = static_cast<Uint16>(width-1); r.h = static_cast<Uint16>(dy + corner);
			SDL_FillRect(surface, &r, brush_col);
		}

		// ------ Rechteck entlang der oberen und entlang der unteren Kante ------
		if((corner > 0)&&(dx>0))
		{
			SDL_Rect r;
			r.x = Xcenter; r.y = static_cast<Sint16>(y+1);
			r.w = dx; r.h = static_cast<Uint16>(corner-1);
			SDL_FillRect(surface, &r, brush_col);
		}
		// ------- END OF Rechteck oben und unten ------


		// Halbkreis
		Lock();
		{
			Uint16 rightInc = 6;
			Sint16 diagonalInc = static_cast<Sint16>(10 - (corner << 2));
			Sint16 d = static_cast<Sint16>(3 - (corner << 1));
			int radius = corner;
			int i = 0;

			while (i <= radius) 
			{
				for(int k=i; k--;)
				{
					*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + ((k + Xcenter - i)<<2) )) = brush_col;
					*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + ((k + X2center)<<2) )) = brush_col;
				}
				for(int k=radius; k--;)
				{
					*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + ((k + Xcenter - radius)<<2) )) = brush_col;
					*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + ((k + X2center)<<2) )) = brush_col;
				}
				if (d >= 0) 
				{
					d = static_cast<Sint16>(d + diagonalInc);
					diagonalInc = static_cast<Sint16>(diagonalInc + 8);
					--radius;
				} else 
				{
					d = static_cast<Sint16>(d + rightInc);
					diagonalInc = static_cast<Sint16>(diagonalInc + 4);
				}
				rightInc = static_cast<Uint16>(rightInc + 4);
				++i;
			}
		}
		Unlock();
	}

	Uint32 dark_pen_col, pen_col;
	if(pressedRectangle)
	{
		dark_pen_col = static_cast<Uint32>(getDarkPressedPenColor());
		pen_col = static_cast<Uint32>(getPressedPenColor());
	} else {
		dark_pen_col = static_cast<Uint32>(getDarkPenColor());
		pen_col = static_cast<Uint32>(getPenColor());
	}

	Lock();
	// ------ TOP HORIZONTAL LINE ------
	{
		register Uint8* p0 = static_cast<Uint8*>(surface->pixels) + y * surface->pitch + (Xcenter<<2);

# pragma warning( push )
# pragma warning( disable:4127 )
		if (sizeof(wchar_t) == sizeof(Uint32)) { 
# pragma warning( pop )

#if defined(__linux__)
			wmemset(reinterpret_cast<wchar_t*>(p0), pen_col, dx);
#elif defined(WIN32)
			memset(reinterpret_cast<wchar_t*>(p0), pen_col, dx);
#endif
		} else 
		{
			int i = dx;
			for(; i--; p0+=4) {
				*reinterpret_cast<Uint32*>(p0) = pen_col;
			}
		}
	}
	// ------ END OF TOP HORIZONTAL LINE ------


	// ------ LEFT AND RIGHT VERTICAL LINE ------
	{
		register Uint8* p0 = static_cast<Uint8*>(surface->pixels) + Ycenter*surface->pitch + (x<<2);	 
		register Uint8* p1 = static_cast<Uint8*>(surface->pixels) + Ycenter*surface->pitch + ((x+width-1)<<2);
		int i = dy + corner;
		for(; i--; p0+=surface->pitch, p1+=surface->pitch)
		{
			*reinterpret_cast<Uint32*>(p0) = pen_col;
			*reinterpret_cast<Uint32*>(p1) = dark_pen_col;
		}
	}
	// ------ END OF LEFT AND RIGHT VERTICAL LINE ------

	{
		Uint16 rightInc = 6;
		Sint16 diagonalInc = static_cast<Sint16>( 10 - (corner<<2));
		Sint16 d = static_cast<Sint16>(3 - (corner << 1));
		int radius = corner;
		int i = 0;

		while (i <= radius) 
		{	
			*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + ((Xcenter - i)<<2))) = pen_col;
			*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + ((Xcenter - radius)<<2))) = pen_col;

			*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + ((X2center + i)<<2))) = pen_col;
			*(reinterpret_cast<Uint32*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + ((X2center + radius)<<2))) = pen_col;

			if (d >= 0) 
			{
				d = static_cast<Sint16>(d + diagonalInc);
				diagonalInc = static_cast<Sint16>(diagonalInc + 8);
				--radius;
			} else 
			{
				d = static_cast<Sint16>(d + rightInc);
				diagonalInc = static_cast<Sint16>(diagonalInc + 4);
			}
			rightInc = static_cast<Uint16>(rightInc + 4);
			++i;
		}
	}
	Unlock();

}

