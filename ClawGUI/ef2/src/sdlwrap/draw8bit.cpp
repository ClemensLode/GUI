#include "dc.hpp"

void DC::Draw_VLine_8bit(const Sint16 x0, const Sint16 y0, const Sint16 y1) const
{
	BOOST_ASSERT(static_cast<Sint16>(y1+1) > y0);
	Uint8 pen_col = static_cast<Uint8>(getPenColor());
	register Uint8 *p = static_cast<Uint8*>(surface->pixels) + y0 * surface->pitch + x0;
	int i = y1 - y0 + 1;
	Lock();

	if(pen->getStyle() == SHORT_DASH_PEN_STYLE)
	{
		for(;i--;)
		{
			if(((i%5) != 2)&&((i%5) != 3)) {
				*p = pen_col;
			}
			p += surface->pitch;
		}
	} else
	{
		switch( i % 4 ) {					
			do{								 
		case 0: *p = pen_col; p+=surface->pitch;
		case 3: *p = pen_col; p+=surface->pitch;
		case 2: *p = pen_col; p+=surface->pitch;
		case 1: *p = pen_col; p+=surface->pitch;
			}while( (i-=4) > 0 );
		default:break;
		}
	}
	Unlock();
}

void DC::Draw_HLine_8bit(const Sint16 x0, const Sint16 y0, const Sint16 x1) const
{
	Uint32 col = static_cast<Uint32>(getPenColor());
	register Uint8* p = static_cast<Uint8*>(surface->pixels) + y0 * surface->pitch + x0;
	memset(p, col, x1-x0+1);
}

void DC::Draw_Line_8bit(const Sint16 x0, const Sint16 y0, const Sint16& dx, const Sint16& dy, const Sint16& pixx, const Sint16& pixy) const
{
	Uint8* pixel = (static_cast<Uint8*>(surface->pixels)) + pixx * x0 + pixy * y0;
	int x = 0;
	int y = 0;
	Uint8 col = static_cast<Uint8>(getPenColor());

	Lock();
	for (; x < dx; ++x, pixel += pixx) {
		*pixel = col;
		y += dy;
		if (y >= dx) {
			y -= dx;
			pixel += pixy;
		}
	}
	Unlock();
}


void DC::DrawRound_8bit(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height, const Uint16 corner) const
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
		Uint8 col = static_cast<Uint8>(getBrushColor());

		// Rechteck von linker Kante nach rechter Kante
		if(dy > 0)
		{
			SDL_Rect r;
			r.x = static_cast<Sint16>(x+1); r.y = Ycenter;
			r.w = static_cast<Uint16>(width-1); r.h = dy;
			SDL_FillRect(surface, &r, col);
		}

		// Rechteck entlang der oberen und entlang der unteren Kante
		if((corner > 0)&&(dx>0))
		{
			SDL_Rect r;
			r.x = Xcenter; r.y = static_cast<Sint16>(y+1);
			r.w = dx; r.h = static_cast<Uint16>(corner-1);
			SDL_FillRect(surface, &r, col);

			r.x = Xcenter; r.y = Y2center;
			r.w = dx; r.h = corner;
			SDL_FillRect(surface, &r, col);
		}

		Uint16 rightInc = 6;
		Sint16 diagonalInc = static_cast<Sint16>(10 - (corner << 2));
		Sint16 d = static_cast<Sint16>(3 - (corner << 1));
		int radius = corner;
		int i = 0;

		Lock();
		while (i <= radius) 
		{
			// TODO optimieren evtl 4 bytes zusammenfassen
			// Nur Ecken:
			for(int k = i; k--;)
			{
				*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + k+ (Ycenter-radius)*surface->pitch + (Xcenter - i))) = col;
				*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + k+(Ycenter-radius)*surface->pitch + X2center)) = col;
				*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + k+(Y2center+radius)*surface->pitch + X2center)) = col;
				*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + k+(Y2center+radius)*surface->pitch + (Xcenter-i))) = col;

			}
			for(int k = radius; k--;)
			{
				*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + k+(Ycenter-i)*surface->pitch + (Xcenter - radius))) = col;
				*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + k+(Ycenter-i)*surface->pitch + X2center)) = col;
				*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + k+(Y2center+i)*surface->pitch + X2center)) = col;
				*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + k+(Y2center+i)*surface->pitch + (Xcenter-radius))) = col;
			}
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
		}/*while*/
		Unlock();
	}

	if(pen->getStyle() != TRANSPARENT_PEN_STYLE) {
		Uint8 col = static_cast<Uint8>(getPenColor());

		Lock();
		{
			register Uint8* p0 = static_cast<Uint8*>(surface->pixels) +	y	* surface->pitch + Xcenter;
			register Uint8* p1 = static_cast<Uint8*>(surface->pixels) + (y+height-1) * surface->pitch + Xcenter;
			int i = dx;
			switch( i % 4 ) { 
				do{			
			case 0:	 
				*p0 = col; ++p0;		 
				*p1 = col; ++p1;		
			case 3:								
				*p0 = col; ++p0;		
				*p1 = col; ++p1;	 
			case 2:						 
				*p0 = col; ++p0;	 
				*p1 = col; ++p1;
			case 1:						
				*p0 = col; ++p0;
				*p1 = col; ++p1;
				}while( (i-=4) > 0 );	
			default:break;
			}											 
		}
		{
			register Uint8* p0 = static_cast<Uint8*>(surface->pixels) + Ycenter*surface->pitch + x;
			register Uint8* p1 = static_cast<Uint8*>(surface->pixels) + Ycenter*surface->pitch + (x+width-1);
			int i = dy;
			switch( i % 4 ) {							 
				do{										
			case 0:								 
				*p0 = col; p0+=surface->pitch;
				*p1 = col; p1+=surface->pitch;
			case 3:								 
				*p0 = col; p0+=surface->pitch;
				*p1 = col; p1+=surface->pitch;
			case 2:								 
				*p0 = col; p0+=surface->pitch;
				*p1 = col; p1+=surface->pitch;
			case 1:								 
				*p0 = col; p0+=surface->pitch;
				*p1 = col; p1+=surface->pitch;
				}while( (i-=4) > 0 );	
			default:break;
			}
		}		

		//	rounded corners 
		{
			Uint16 rightInc = 6;
			Sint16 diagonalInc = static_cast<Sint16>( 10 - (corner<<2));
			Sint16 d = static_cast<Sint16>(3 - (corner << 1));
			Uint16 radius = corner;
			int i = 0;

			while (i <= radius) 
			{
				*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + (Xcenter - radius))) = col;
				*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + (Xcenter - i))) = col;

				*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + (X2center + i))) = col;
				*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + (X2center + radius))) = col;

				*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + (Y2center+radius)*surface->pitch + (X2center + i))) = col;
				*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + (Y2center+i)*surface->pitch + (X2center + radius))) = col;

				*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + (Y2center+radius)*surface->pitch + (Xcenter - i))) = col;
				*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + (Y2center+i)*surface->pitch + (Xcenter - radius))) = col;

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


void DC::DrawEdgedRound_8bit(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height, const Uint16 corner) const
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
		Uint8 brush_col;
		if(!pressedRectangle) {
			brush_col = static_cast<Uint8>(getBrushColor());
		}
		else {
			brush_col = static_cast<Uint8>(getDarkBrushColor());
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
		Lock();
		// Halbkreis
		{
			Uint16 rightInc = 6;
			Sint16 diagonalInc = static_cast<Sint16>( 10 - (corner<<2));
			Sint16 d = static_cast<Sint16>(3 - (corner<<1));
			int radius = corner;
			int i = 0;

			while (i <= radius) 
			{
				for(int k = i; k--;)
				{
					*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + k + Xcenter - i)) = brush_col;
					*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + k + X2center)) = brush_col;
					*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + (Y2center+radius)*surface->pitch + k + X2center)) = brush_col;
				}

				for(int k = radius; k--;)
				{
					*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + k + Xcenter - radius)) = brush_col;
					*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + k + X2center)) = brush_col;
					*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + (Y2center+i)*surface->pitch + k + X2center)) = brush_col;
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
	// ------- END OF Rechteck oben und unten ------


	// ------ TOP AND LOWER HORIZONTAL LINE ------
	if(pen->getStyle() != TRANSPARENT_PEN_STYLE) {
		Uint8 dark_pen_col, pen_col;
		if(pressedRectangle)
		{
			dark_pen_col = static_cast<Uint8>(getDarkPressedPenColor());
			pen_col = static_cast<Uint8>(getPressedPenColor());

		} else
		{
			dark_pen_col = static_cast<Uint8>(getDarkPenColor());
			pen_col = static_cast<Uint8>(getPenColor());
		}

		Lock();
		{
			memset(static_cast<Uint8*>(surface->pixels) + y * surface->pitch + Xcenter, pen_col, dx);
			memset(static_cast<Uint8*>(surface->pixels) + (y+height-1) * surface->pitch + x, dark_pen_col, dx+corner);
		}
		// ------ END OF TOP AND LOWER HORIZONTAL LINE ------


		// ------ LEFT AND RIGHT VERTICAL LINE ------
		{
			register Uint8* p0 = static_cast<Uint8*>(surface->pixels) + Ycenter*surface->pitch + x;	 
			register Uint8* p1 = static_cast<Uint8*>(surface->pixels) + Ycenter*surface->pitch + x+width-1;
			int i = dy;
			for(;i--;p0+=surface->pitch, p1+=surface->pitch)
			{
				*p0 = pen_col;
				*p1 = dark_pen_col;
			}
			i = corner;
			for(;i--; p0+=surface->pitch) {
				*p0 = pen_col;	
			}
		}
		// ------ END OF LEFT AND RIGHT VERTICAL LINE ------


		{
			Uint16 rightInc = 6;
			Sint16 diagonalInc = static_cast<Sint16>( 10 - (corner<<2));
			Sint16 d = static_cast<Sint16>(3 - (corner<<1));
			int radius = corner;
			int i = 0;

			while (i <= radius) 
			{
				*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + Xcenter - i)) = pen_col;
				*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + Xcenter - radius)) = pen_col;

				*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + X2center + i)) = pen_col;
				*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + X2center + radius)) = pen_col;

				*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + (Y2center+radius)*surface->pitch + X2center + i)) = dark_pen_col;
				*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + (Y2center+i)*surface->pitch + X2center + radius)) = dark_pen_col;

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


void DC::DrawTab_8bit(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height) const
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
		Uint8 brush_col;
		if(pressedRectangle) {
			brush_col = static_cast<Uint8>(getBrushColor());
		} else {
			brush_col = static_cast<Uint8>(getDarkBrushColor());
		}

		// Rechteck von linker Kante nach rechter Kante
		if(dy > 0)
		{
			SDL_Rect r;
			r.x = static_cast<Sint16>(x+1); 
			r.y = Ycenter;
			r.w = static_cast<Uint16>(width-1); 
			r.h = static_cast<Uint16>(dy + corner);
			SDL_FillRect(surface, &r, brush_col);
		}

		// ------ Rechteck entlang der oberen und entlang der unteren Kante ------
		if((corner > 0)&&(dx>0))
		{
			SDL_Rect r;
			r.x = Xcenter; 
			r.y = static_cast<Sint16>(y+1);
			r.w = dx; 
			r.h = static_cast<Uint16>(corner-1);
			SDL_FillRect(surface, &r, brush_col);
		}

		// Halbkreis
		Lock();
		{
			Uint16 rightInc = 6;
			Sint16 diagonalInc = static_cast<Sint16>( 10 - (corner<<2));
			Sint16 d = static_cast<Sint16>(3 - (corner<<1));
			int radius = corner;
			int i = 0;

			while (i <= radius) 
			{
				for(int k = i; k--;)
				{
					*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + k + Xcenter - i)) = brush_col;
					*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + k + X2center)) = brush_col;
				}
				for(int k = radius; k--;)
				{
					*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + k + Xcenter - radius)) = brush_col;
					*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + k + X2center)) = brush_col;
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
		// ------- END OF Rechteck oben und unten ------
	}

	if(pen->getStyle() != TRANSPARENT_PEN_STYLE) {

		// ------ TOP AND LOWER HORIZONTAL LINE ------
		Uint8 dark_pen_col, pen_col;
		if(pressedRectangle)
		{
			dark_pen_col = static_cast<Uint8>(getDarkPressedPenColor());
			pen_col = static_cast<Uint8>(getPressedPenColor());

		} else
		{
			dark_pen_col = static_cast<Uint8>(getDarkPenColor());
			pen_col = static_cast<Uint8>(getPenColor());
		}

		Lock();
		{
			memset(static_cast<Uint8*>(surface->pixels) + y * surface->pitch + Xcenter, pen_col, dx);
		}
		// ------ END OF TOP AND LOWER HORIZONTAL LINE ------


		// ------ LEFT AND RIGHT VERTICAL LINE ------
		{
			register Uint8* p0 = static_cast<Uint8*>(surface->pixels) + Ycenter*surface->pitch + x;	 
			register Uint8* p1 = static_cast<Uint8*>(surface->pixels) + Ycenter*surface->pitch + x+width-1;
			int i = dy + corner;
			for(; i--; p0+=surface->pitch, p1+=surface->pitch)
			{
				*p0 = pen_col;
				*p1 = dark_pen_col;
			}
		}
		// ------ END OF LEFT AND RIGHT VERTICAL LINE ------


		{
			Uint16 rightInc = 6;
			Sint16 diagonalInc = static_cast<Sint16>( 10 - (corner<<2));
			Sint16 d = static_cast<Sint16>(3 - (corner<<1));
			int radius = corner;
			int i = 0;

			while (i <= radius) 
			{
				*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + Xcenter - i)) = pen_col;
				*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + Xcenter - radius)) = pen_col;

				*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + X2center + i)) = pen_col;
				*(reinterpret_cast<Uint8*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + X2center + radius)) = pen_col;

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
