#include "dc.hpp"

// for 24bit:
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
#define SDL_DRAW_PUTPIXEL_BPP_3_AUX \
	{ \
	pixel[0] = colorbyte2;					 \
	pixel[1] = colorbyte1;					 \
	pixel[2] = colorbyte0;					 \
	}
#else
#define SDL_DRAW_PUTPIXEL_BPP_3_AUX \
	{ \
	pixel[0] = colorbyte0;					 \
	pixel[1] = colorbyte1;					 \
	pixel[2] = colorbyte2;					 \
	}
#endif

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
#define SDL_DRAW_BRIGHT_PUTPIXEL_BPP_3_AUX \
	{ \
	pixel[0] = bright_colorbyte2;					 \
	pixel[1] = bright_colorbyte1;					 \
	pixel[2] = bright_colorbyte0;					 \
	}
#else
#define SDL_DRAW_BRIGHT_PUTPIXEL_BPP_3_AUX \
	{ \
	pixel[0] = bright_colorbyte0;					 \
	pixel[1] = bright_colorbyte1;					 \
	pixel[2] = bright_colorbyte2;					 \
	}
#endif

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
#define SDL_DRAW_DARK_PUTPIXEL_BPP_3_AUX \
	{ \
	pixel[0] = dark_colorbyte2;					 \
	pixel[1] = dark_colorbyte1;					 \
	pixel[2] = dark_colorbyte0;					 \
	}
#else
#define SDL_DRAW_DARK_PUTPIXEL_BPP_3_AUX \
	{ \
	pixel[0] = dark_colorbyte0;					 \
	pixel[1] = dark_colorbyte1;					 \
	pixel[2] = dark_colorbyte2;					 \
	}
#endif

#define SDL_DO_DRAWING_X if(k>0) switch( k % 4 ) { do{case 0: SDL_DRAW_PUTPIXEL_BPP_3_AUX pixel+=3; case 3: SDL_DRAW_PUTPIXEL_BPP_3_AUX pixel+=3; case 2: SDL_DRAW_PUTPIXEL_BPP_3_AUX pixel+=3; case 1: SDL_DRAW_PUTPIXEL_BPP_3_AUX pixel+=3; } while( (k-=4) > 0 );default:break;}
#define SDL_DO_BRIGHT_DRAWING_X if(k>0) switch( k % 4 ) { do{case 0: SDL_DRAW_BRIGHT_PUTPIXEL_BPP_3_AUX pixel+=3;case 3: SDL_DRAW_BRIGHT_PUTPIXEL_BPP_3_AUX pixel+=3; case 2: SDL_DRAW_BRIGHT_PUTPIXEL_BPP_3_AUX pixel+=3; case 1: SDL_DRAW_BRIGHT_PUTPIXEL_BPP_3_AUX pixel+=3; } while( (k-=4) > 0 );default:break;}
#define SDL_DO_DARK_DRAWING_X if(k>0) switch( k % 4 ) { do{case 0: SDL_DRAW_DARK_PUTPIXEL_BPP_3_AUX pixel+=3;case 3: SDL_DRAW_DARK_PUTPIXEL_BPP_3_AUX pixel+=3; case 2: SDL_DRAW_DARK_PUTPIXEL_BPP_3_AUX pixel+=3; case 1: SDL_DRAW_DARK_PUTPIXEL_BPP_3_AUX pixel+=3; } while( (k-=4) > 0 );default:break;}

#define SDL_DO_DRAWING_Y if(k>0) switch( k % 4 ) { do{case 0: SDL_DRAW_PUTPIXEL_BPP_3_AUX pixel+=surface->pitch; case 3: SDL_DRAW_PUTPIXEL_BPP_3_AUX pixel+=surface->pitch;case 2: SDL_DRAW_PUTPIXEL_BPP_3_AUX pixel+=surface->pitch;case 1: SDL_DRAW_PUTPIXEL_BPP_3_AUX pixel+=surface->pitch; } while( (k-=4) > 0 );default:break;}
#define SDL_DO_BRIGHT_DRAWING_Y if(k>0) switch( k % 4 ) { do{case 0: SDL_DRAW_BRIGHT_PUTPIXEL_BPP_3_AUX pixel+=surface->pitch; case 3: SDL_DRAW_BRIGHT_PUTPIXEL_BPP_3_AUX pixel+=surface->pitch;case 2: SDL_DRAW_BRIGHT_PUTPIXEL_BPP_3_AUX pixel+=surface->pitch;case 1: SDL_DRAW_BRIGHT_PUTPIXEL_BPP_3_AUX pixel+=surface->pitch; } while( (k-=4) > 0 );default:break;}
#define SDL_DO_DARK_DRAWING_Y if(k>0) switch( k % 4 ) { do{case 0: SDL_DRAW_DARK_PUTPIXEL_BPP_3_AUX pixel+=surface->pitch; case 3: SDL_DRAW_DARK_PUTPIXEL_BPP_3_AUX pixel+=surface->pitch; case 2: SDL_DRAW_DARK_PUTPIXEL_BPP_3_AUX pixel+=surface->pitch; case 1: SDL_DRAW_DARK_PUTPIXEL_BPP_3_AUX pixel+=surface->pitch; } while( (k-=4) > 0 );default:break;}


void DC::Draw_VLine_24bit(const Sint16 x0, const Sint16 y0, const Sint16 y1) const
{
	BOOST_ASSERT(static_cast<Sint16>(y1+1) > y0);

	Uint32 pen_col = static_cast<Uint32>(getPenColor());
	Uint8 colorbyte0 = static_cast<Uint8> (pen_col & 0xff);
	Uint8 colorbyte1 = static_cast<Uint8> ((pen_col >> 8) & 0xff);
	Uint8 colorbyte2 = static_cast<Uint8> ((pen_col >> 16) & 0xff);

	register Uint8 *pixel = static_cast<Uint8*>(surface->pixels) + y0 * surface->pitch + x0 * 3;
	int k = y1 - y0 + 1;

	Lock();
	if(pen->getStyle() == SHORT_DASH_PEN_STYLE)
	{
		for(; k--;)
		{
			if(((k%5) != 2) && ((k%5) != 3))
			{
				SDL_DRAW_PUTPIXEL_BPP_3_AUX
			}
			pixel += surface->pitch;
		}
	} else {
		SDL_DO_DRAWING_Y
	}
	Unlock();
}


void DC::Draw_HLine_24bit(const Sint16 x0, const Sint16 y0, const Sint16 x1) const
{
	BOOST_ASSERT(static_cast<Sint16>(x1+1) >= x0);

	Uint32 col = static_cast<Uint32>(getPenColor());
	Uint8 colorbyte0 = static_cast<Uint8> (col & 0xff);
	Uint8 colorbyte1 = static_cast<Uint8> ((col >> 8) & 0xff);
	Uint8 colorbyte2 = static_cast<Uint8> ((col >> 16) & 0xff);

	register Uint8 *pixel = static_cast<Uint8*>(surface->pixels) + y0 * surface->pitch + x0 * 3;
	int k = x1 - x0 + 1;

	Lock();

	SDL_DO_DRAWING_X

		Unlock();
}


void DC::Draw_Line_24bit(const Sint16 x0, const Sint16 y0, const Sint16& dx, const Sint16& dy, const Sint16& pixx, const Sint16& pixy) const
{
	Uint8* pixel = reinterpret_cast<Uint8*>(surface->pixels) + pixx * x0 + pixy * y0;
	Uint32 col = static_cast<Uint32>(getPenColor());
	Uint8 colorbyte0 = static_cast<Uint8> (col & 0xff);
	Uint8 colorbyte1 = static_cast<Uint8> ((col >> 8) & 0xff);
	Uint8 colorbyte2 = static_cast<Uint8> ((col >> 16) & 0xff);
	int x = 0;
	int y = 0;


	Lock();
	for (; x < dx; ++x, pixel += pixx) {

		SDL_DRAW_PUTPIXEL_BPP_3_AUX

			y = static_cast<Sint16>(y + dy);
		if (y >= dx) {
			y = static_cast<Sint16>(y - dx);
			pixel += pixy;
		}
	}
	Unlock();
}



void DC::DrawRound_24bit(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height, const Uint16 corner) const
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

		Uint8 colorbyte0 = static_cast<Uint8> (col & 0xff);
		Uint8 colorbyte1 = static_cast<Uint8> ((col >> 8) & 0xff);
		Uint8 colorbyte2 = static_cast<Uint8> ((col >> 16) & 0xff);

		Uint16 rightInc = 6;
		Sint16 diagonalInc = static_cast<Sint16>(10 - (corner << 2));
		Sint16 d = static_cast<Sint16>(3 - (corner << 1));
		int radius = corner;
		int i = 0;

		Lock();	
		while (i <= radius) 
		{
			register Uint8* pixel;
			int k;

			pixel = static_cast<Uint8*>(surface->pixels) + (Ycenter - i) * surface->pitch + (Xcenter - radius) * 3;k = radius;SDL_DO_DRAWING_X
				pixel = static_cast<Uint8*>(surface->pixels) + (Ycenter - radius) * surface->pitch + (Xcenter - i) * 3;k = i;SDL_DO_DRAWING_X

				pixel = static_cast<Uint8*>(surface->pixels) + (Ycenter - radius) * surface->pitch + (X2center + i) * 3;k = i;SDL_DO_DRAWING_X
				pixel = static_cast<Uint8*>(surface->pixels) + (Ycenter - i) * surface->pitch + (X2center + radius) * 3;k = radius;SDL_DO_DRAWING_X

				pixel = static_cast<Uint8*>(surface->pixels) + (Y2center + radius) * surface->pitch + (X2center - i) * 3;k = i;SDL_DO_DRAWING_X
				pixel = static_cast<Uint8*>(surface->pixels) + (Y2center + i) * surface->pitch + (X2center + radius) * 3;k = radius;SDL_DO_DRAWING_X

				pixel = static_cast<Uint8*>(surface->pixels) + (Y2center + radius) * surface->pitch + (Xcenter-i) * 3;k = i;SDL_DO_DRAWING_X
				pixel = static_cast<Uint8*>(surface->pixels) + (Y2center + i) * surface->pitch + (Xcenter-radius) * 3;k = radius;SDL_DO_DRAWING_X

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

		const Color& col = *pen->getColor();
		Uint8 colorbyte0 = static_cast<Uint8> (col & 0xff);
		Uint8 colorbyte1 = static_cast<Uint8> ((col >> 8) & 0xff);
		Uint8 colorbyte2 = static_cast<Uint8> ((col >> 16) & 0xff);
		// ------ TOP AND LOWER HORIZONTAL LINE ------
		Lock();
		{
			register Uint8* pixel;
			int k;
			pixel = static_cast<Uint8*>(surface->pixels) + y * surface->pitch + Xcenter * 3;k = dx;SDL_DO_DRAWING_X
				pixel = static_cast<Uint8*>(surface->pixels) + (y+height-1) * surface->pitch + Xcenter * 3;k = dx;SDL_DO_DRAWING_X
		}
		// ------ END OF TOP AND LOWER HORIZONTAL LINE ------


		// ------ LEFT AND RIGHT VERTICAL LINE ------
		{
			register Uint8* pixel;
			int k;
			pixel = static_cast<Uint8*>(surface->pixels) + Ycenter * surface->pitch + x * 3;k = dy;SDL_DO_DRAWING_Y
				pixel = static_cast<Uint8*>(surface->pixels) + Ycenter * surface->pitch + (x+width-1) * 3;k = dy;SDL_DO_DRAWING_Y
		}
		// ------ END OF LEFT AND RIGHT VERTICAL LINE ------

		Uint16 rightInc = 6;
		Sint16 d = static_cast<Sint16>(3 - (corner << 1));
		Sint16 diagonalInc = static_cast<Sint16>( 10 - (corner<<2));	
		int radius = corner;
		int i = 0;

		register Uint8* pixel;
		while (i <= radius) 
		{
			pixel = static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + (Xcenter - radius)*3; SDL_DRAW_PUTPIXEL_BPP_3_AUX
				pixel = static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + (Xcenter - i)*3; SDL_DRAW_PUTPIXEL_BPP_3_AUX

				pixel = static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + (X2center + i)*3; SDL_DRAW_PUTPIXEL_BPP_3_AUX
				pixel = static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + (X2center + radius)*3; SDL_DRAW_PUTPIXEL_BPP_3_AUX

				pixel = static_cast<Uint8*>(surface->pixels) + (Y2center+radius)*surface->pitch + (X2center + i)*3; SDL_DRAW_PUTPIXEL_BPP_3_AUX
				pixel = static_cast<Uint8*>(surface->pixels) + (Y2center+i)*surface->pitch + (X2center + radius)*3; SDL_DRAW_PUTPIXEL_BPP_3_AUX

				pixel = static_cast<Uint8*>(surface->pixels) + (Y2center+radius)*surface->pitch + (Xcenter - i)*3; SDL_DRAW_PUTPIXEL_BPP_3_AUX
				pixel = static_cast<Uint8*>(surface->pixels) + (Y2center+i)*surface->pitch + (Xcenter - radius)*3; SDL_DRAW_PUTPIXEL_BPP_3_AUX

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
		Unlock();
	}
}


void DC::DrawEdgedRound_24bit(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height, const Uint16 corner) const
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
		} else {
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
			r.x = Xcenter; 
			r.y = static_cast<Sint16>(y+1);
			r.w = dx; 
			r.h = static_cast<Uint16>(corner-1);
			SDL_FillRect(surface, &r, brush_col);

			r.x = static_cast<Sint16>(x+1); 
			r.y = Y2center;
			r.w = static_cast<Uint16>(width-corner-1); 
			r.h = corner;
			SDL_FillRect(surface, &r, brush_col);
		}
		// ------- END OF Rechteck oben und unten ------

		// Halbkreis
		Lock();
		Uint8 colorbyte0 = static_cast<Uint8> (brush_col & 0xff);
		Uint8 colorbyte1 = static_cast<Uint8> ((brush_col >> 8) & 0xff);
		Uint8 colorbyte2 = static_cast<Uint8> ((brush_col >> 16) & 0xff);
		{
			Uint16 rightInc = 6;
			Sint16 diagonalInc = static_cast<Sint16>(10 - (corner << 2));
			Sint16 d = static_cast<Sint16>(3 - (corner << 1));
			int radius = corner;
			int i = 0;

			while (i <= radius)
			{
				register Uint8 *pixel;
				int k;
				pixel = static_cast<Uint8*>(surface->pixels) + (Ycenter-radius) * surface->pitch + (Xcenter-i) * 3; k = i; SDL_DO_DRAWING_X
					pixel = static_cast<Uint8*>(surface->pixels) + (Ycenter-radius) * surface->pitch + (X2center) * 3; k = i; SDL_DO_DRAWING_X
					pixel = static_cast<Uint8*>(surface->pixels) + (Y2center+radius) * surface->pitch + (X2center) * 3; k = i; SDL_DO_DRAWING_X
					pixel = static_cast<Uint8*>(surface->pixels) + (Ycenter-i) * surface->pitch + (Xcenter-radius) * 3; k = radius; SDL_DO_DRAWING_X
					pixel = static_cast<Uint8*>(surface->pixels) + (Ycenter-i) * surface->pitch + (X2center) * 3; k = radius; SDL_DO_DRAWING_X
					pixel = static_cast<Uint8*>(surface->pixels) + (Y2center+i) * surface->pitch + (X2center) * 3; k = radius; SDL_DO_DRAWING_X

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

		//	Uint32 pen_col = static_cast<Uint32>(getPenColor());

		Uint8 colorbyte0 = static_cast<Uint8> (pen_col & 0xff);
		Uint8 colorbyte1 = static_cast<Uint8> ((pen_col >> 8) & 0xff);
		Uint8 colorbyte2 = static_cast<Uint8> ((pen_col >> 16) & 0xff);

		Uint8 dark_colorbyte0 = static_cast<Uint8> (dark_pen_col & 0xff);
		Uint8 dark_colorbyte1 = static_cast<Uint8> ((dark_pen_col >> 8) & 0xff);
		Uint8 dark_colorbyte2 = static_cast<Uint8> ((dark_pen_col >> 16) & 0xff);

		Uint8 bright_colorbyte0 = static_cast<Uint8> (pen_col & 0xff);
		Uint8 bright_colorbyte1 = static_cast<Uint8> ((pen_col >> 8) & 0xff);
		Uint8 bright_colorbyte2 = static_cast<Uint8> ((pen_col >> 16) & 0xff);

		// ------ TOP AND LOWER HORIZONTAL LINE ------
		Lock();
		{
			register Uint8* pixel;
			int k;
			pixel = static_cast<Uint8*>(surface->pixels) + y * surface->pitch + Xcenter * 3;k = dx;SDL_DO_BRIGHT_DRAWING_X
				pixel = static_cast<Uint8*>(surface->pixels) + (y+height-1) * surface->pitch + x * 3;k = dx+corner;SDL_DO_DARK_DRAWING_X
		}
		// ------ END OF TOP AND LOWER HORIZONTAL LINE ------


		// ------ LEFT AND RIGHT VERTICAL LINE ------
		{
			register Uint8* pixel;
			int k;

			pixel = static_cast<Uint8*>(surface->pixels) + Ycenter * surface->pitch + x * 3;k = height-corner-1;SDL_DO_BRIGHT_DRAWING_Y
				pixel = static_cast<Uint8*>(surface->pixels) + Ycenter * surface->pitch + (x+width-1) * 3;k = dy;SDL_DO_DARK_DRAWING_Y
		}
		// ------ END OF LEFT AND RIGHT VERTICAL LINE ------




		colorbyte0 = static_cast<Uint8> (pen_col & 0xff);
		colorbyte1 = static_cast<Uint8> ((pen_col >> 8) & 0xff);
		colorbyte2 = static_cast<Uint8> ((pen_col >> 16) & 0xff);

		{
			Uint16 rightInc = 6;
			Sint16 diagonalInc = static_cast<Sint16>(10 - (corner << 2));
			Sint16 d = static_cast<Sint16>(3 - (corner << 1));
			int radius = corner;
			register Uint8 *pixel;

			int i = 0;
			while (i <= radius) 
			{
				pixel = static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + (Xcenter - i)*3; SDL_DRAW_BRIGHT_PUTPIXEL_BPP_3_AUX
					pixel = static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + (Xcenter - radius)*3; SDL_DRAW_BRIGHT_PUTPIXEL_BPP_3_AUX

					pixel = static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + (X2center + i)*3; SDL_DRAW_PUTPIXEL_BPP_3_AUX
					pixel = static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + (X2center + radius)*3; SDL_DRAW_PUTPIXEL_BPP_3_AUX

					pixel = static_cast<Uint8*>(surface->pixels) + (Y2center+radius)*surface->pitch + (X2center + i)*3; SDL_DRAW_DARK_PUTPIXEL_BPP_3_AUX
					pixel = static_cast<Uint8*>(surface->pixels) + (Y2center+i)*surface->pitch + (X2center + radius)*3; SDL_DRAW_DARK_PUTPIXEL_BPP_3_AUX
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

void DC::DrawTab_24bit(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height) const
{
	Uint16 corner = 4;
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

			r.x = static_cast<Sint16>(x+1); r.y = Y2center;
			r.w = static_cast<Uint16>(width-corner-1); r.h = corner;
			SDL_FillRect(surface, &r, brush_col);
		}
		Lock();
		Uint8 colorbyte0 = static_cast<Uint8> (brush_col & 0xff);
		Uint8 colorbyte1 = static_cast<Uint8> ((brush_col >> 8) & 0xff);
		Uint8 colorbyte2 = static_cast<Uint8> ((brush_col >> 16) & 0xff);
		{
			Uint16 rightInc = 6;
			Sint16 diagonalInc = static_cast<Sint16>(10 - (corner << 2));
			Sint16 d = static_cast<Sint16>(3 - (corner << 1));
			int radius = corner;
			int i = 0;

			while (i <= radius)
			{
				register Uint8 *pixel;
				int k;
				pixel = static_cast<Uint8*>(surface->pixels) + (Ycenter-radius) * surface->pitch + (Xcenter-i) * 3; k = i; SDL_DO_DRAWING_X
					pixel = static_cast<Uint8*>(surface->pixels) + (Ycenter-radius) * surface->pitch + (X2center) * 3; k = i; SDL_DO_DRAWING_X
					pixel = static_cast<Uint8*>(surface->pixels) + (Ycenter-i) * surface->pitch + (Xcenter-radius) * 3; k = radius; SDL_DO_DRAWING_X
					pixel = static_cast<Uint8*>(surface->pixels) + (Ycenter-i) * surface->pitch + (X2center) * 3; k = radius; SDL_DO_DRAWING_X

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

		//	Uint32 pen_col = static_cast<Uint32>(getPenColor());

		Uint8 colorbyte0 = static_cast<Uint8> (pen_col & 0xff);
		Uint8 colorbyte1 = static_cast<Uint8> ((pen_col >> 8) & 0xff);
		Uint8 colorbyte2 = static_cast<Uint8> ((pen_col >> 16) & 0xff);

		Uint8 dark_colorbyte0 = static_cast<Uint8> (dark_pen_col & 0xff);
		Uint8 dark_colorbyte1 = static_cast<Uint8> ((dark_pen_col >> 8) & 0xff);
		Uint8 dark_colorbyte2 = static_cast<Uint8> ((dark_pen_col >> 16) & 0xff);

		Uint8 bright_colorbyte0 = static_cast<Uint8> (pen_col & 0xff);
		Uint8 bright_colorbyte1 = static_cast<Uint8> ((pen_col >> 8) & 0xff);
		Uint8 bright_colorbyte2 = static_cast<Uint8> ((pen_col >> 16) & 0xff);

		// ------ TOP AND LOWER HORIZONTAL LINE ------
		Lock();
		{
			register Uint8* pixel;
			int k;
			pixel = static_cast<Uint8*>(surface->pixels) + y * surface->pitch + Xcenter * 3;k = dx;SDL_DO_BRIGHT_DRAWING_X
		}
		// ------ END OF TOP AND LOWER HORIZONTAL LINE ------


		// ------ LEFT AND RIGHT VERTICAL LINE ------
		{
			register Uint8* pixel;
			int k;

			pixel = static_cast<Uint8*>(surface->pixels) + Ycenter * surface->pitch + x * 3;k = dy+corner;SDL_DO_BRIGHT_DRAWING_Y
				pixel = static_cast<Uint8*>(surface->pixels) + Ycenter * surface->pitch + (x+width-1) * 3;k = dy+corner;SDL_DO_DARK_DRAWING_Y
		}
		// ------ END OF LEFT AND RIGHT VERTICAL LINE ------


		// Halbkreis

		colorbyte0 = static_cast<Uint8> (pen_col & 0xff);
		colorbyte1 = static_cast<Uint8> ((pen_col >> 8) & 0xff);
		colorbyte2 = static_cast<Uint8> ((pen_col >> 16) & 0xff);

		{
			Uint16 rightInc = 6;
			Sint16 diagonalInc = static_cast<Sint16>(10 - (corner << 2));
			Sint16 d = static_cast<Sint16>(3 - (corner << 1));
			int radius = corner;
			register Uint8 *pixel;

			int i = 0;
			while (i <= radius) 
			{
				pixel = static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + (Xcenter - i)*3; SDL_DRAW_BRIGHT_PUTPIXEL_BPP_3_AUX
					pixel = static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + (Xcenter - radius)*3; SDL_DRAW_BRIGHT_PUTPIXEL_BPP_3_AUX

					pixel = static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + (X2center + i)*3; SDL_DRAW_PUTPIXEL_BPP_3_AUX
					pixel = static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + (X2center + radius)*3; SDL_DRAW_PUTPIXEL_BPP_3_AUX

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
