#include "dc.hpp"

void DC::Draw_VLine_16bit(const Sint16 x0, const Sint16 y0, const Sint16 y1) const
{
	BOOST_ASSERT(static_cast<Sint16>(y1+1) > y0);
	Uint16 pen_col = static_cast<Uint16>(getPenColor());
	register Uint8 *p = static_cast<Uint8*>(surface->pixels) + y0 * surface->pitch + (x0 << 1);
	int i = y1 - y0 + 1;
	Lock();

	if(pen->getStyle() == SHORT_DASH_PEN_STYLE)
	{
		for(; i--;)
		{
			if(((i%5) != 2)&&((i%5) != 3)) {
				*reinterpret_cast<Uint16*>(p) = pen_col;
			}
			p += surface->pitch;
		}
	} else
	{
		for(; i--; p+=surface->pitch) {
			*reinterpret_cast<Uint16*>(p) = pen_col;
		}
	}
	Unlock();
}


void DC::Draw_HLine_16bit(const Sint16 x0, const Sint16 y0, const Sint16 x1) const 
{
	BOOST_ASSERT(static_cast<Uint16>(x1+1) > x0);
	Uint16 pen_col = static_cast<Uint16>(getPenColor());
	register Uint8* pixel = static_cast<Uint8*>(surface->pixels) + y0 * surface->pitch + (x0 << 1);
	int i = x1 - x0 + 1;

	for(; i--; pixel+=2) {
		*reinterpret_cast<Uint16*>(pixel) = pen_col;
	}
}

void DC::Draw_Line_16bit(const Sint16 x0, const Sint16 y0, const Sint16& dx, const Sint16& dy, const Sint16& pixx, const Sint16& pixy) const
{
	Uint16 col = static_cast<Uint16>(getPenColor());
	register Uint8 *pixel = static_cast<Uint8*>(surface->pixels) + y0 * surface->pitch + (x0 << 1);
	int x = 0;
	int y = 0;
	Lock();
	for (; x < dx; ++x, pixel += pixx) {
		*reinterpret_cast<Uint16*>(pixel) = col;
		y = static_cast<Sint16>(y + dy);
		if (y >= dx) {
			y = static_cast<Sint16>(y - dx);
			pixel += pixy;
		}
	}
	Unlock();
}


void DC::DrawRound_16bit(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height, const Uint16 corner) const
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
		Uint16 col = static_cast<Uint16>(getBrushColor());

		// Rechteck von linker Kante nach rechter Kante
		if(dy > 0)
		{
			SDL_Rect r;
			r.x = static_cast<Sint16>(x+1); r.y = Ycenter;
			r.w = static_cast<Uint16>(width-1); r.h = dy;
			SDL_FillRect(surface, &r, col);
		}

		// Rechteck entlang der oberen und entlang der unteren Kante
		if( (corner > 0) && (dx > 0) )
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
			// Nur Ecken:
			for(int k = i; k--;)
			{
				*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + ((k + Xcenter - i)<<1) )) = col;
				*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + ((k + X2center)<<1) )) = col;
				*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Y2center+radius-1)*surface->pitch + ((k + X2center)<<1) )) = col;
				*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Y2center+radius-1)*surface->pitch + ((k + Xcenter - i)<<1) )) = col;

			}
			for(int k = radius; k--;)
			{
				*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + ((k+Xcenter - radius)<<1) )) = col;
				*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + ((k+X2center)<<1) )) = col;
				*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Y2center+i-1)*surface->pitch + ((k+X2center)<<1) )) = col;
				*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Y2center+i-1)*surface->pitch + ((k+Xcenter-radius)<<1) )) = col;
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
		}
		Unlock();
	}

	if(pen->getStyle() != TRANSPARENT_PEN_STYLE) {
		Uint16 col = static_cast<Uint16>(getPenColor());
		Lock();
		{
			register Uint8* p0 = static_cast<Uint8*>(surface->pixels) +	y	* surface->pitch + (Xcenter << 1);
			register Uint8* p1 = static_cast<Uint8*>(surface->pixels) + (y+height-1) * surface->pitch + (Xcenter << 1);
			int i = dx;				
			switch( i % 4 ) { 
				do{			
			case 0:	 
				*reinterpret_cast<Uint16*>(p0) = col; p0+=2;
				*reinterpret_cast<Uint16*>(p1) = col; p1+=2;		
			case 3:								
				*reinterpret_cast<Uint16*>(p0) = col; p0+=2;		
				*reinterpret_cast<Uint16*>(p1) = col; p1+=2;	 
			case 2:							 
				*reinterpret_cast<Uint16*>(p0) = col; p0+=2;	 
				*reinterpret_cast<Uint16*>(p1) = col; p1+=2;
			case 1:							
				*reinterpret_cast<Uint16*>(p0) = col; p0+=2;
				*reinterpret_cast<Uint16*>(p1) = col; p1+=2;
				}while( (i-=4) > 0 );	
			default:break;
			}
		}
		{
			register Uint8* p0 = static_cast<Uint8*>(surface->pixels) + Ycenter*surface->pitch + (x << 1);	 
			register Uint8* p1 = static_cast<Uint8*>(surface->pixels) + Ycenter*surface->pitch + ((x+width-1) << 1);
			int i = dy;				
			switch( i % 4 ) {							 
				do{										
			case 0:								 
				*reinterpret_cast<Uint16*>(p0) = col; p0+=surface->pitch;
				*reinterpret_cast<Uint16*>(p1) = col; p1+=surface->pitch;
			case 3:								 
				*reinterpret_cast<Uint16*>(p0) = col; p0+=surface->pitch;
				*reinterpret_cast<Uint16*>(p1) = col; p1+=surface->pitch;
			case 2:								 
				*reinterpret_cast<Uint16*>(p0) = col; p0+=surface->pitch;
				*reinterpret_cast<Uint16*>(p1) = col; p1+=surface->pitch;
			case 1:								 
				*reinterpret_cast<Uint16*>(p0) = col; p0+=surface->pitch;
				*reinterpret_cast<Uint16*>(p1) = col; p1+=surface->pitch;
				}while( (i-=4) > 0 );					 
			default:break;
			}
		}
		{
			Uint16 rightInc = 6;
			Sint16 diagonalInc = static_cast<Sint16>( 10 - (corner<<2));	
			Sint16 d = static_cast<Sint16>(3 - (corner << 1));
			int radius = corner;
			int i = 0;
			while (i <= radius)
			{
				*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + ((Xcenter - radius)<<1) )) = col;
				*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + ((Xcenter - i)<<1) )) = col;
				*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + ((X2center + i)<<1) )) = col;
				*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + ((X2center + radius)<<1) )) = col;
				*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Y2center+radius)*surface->pitch + ((X2center + i)<<1) )) = col;
				*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Y2center+i)*surface->pitch + ((X2center + radius)<<1) )) = col;
				*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Y2center+radius)*surface->pitch + ((Xcenter - i)<<1) )) = col;
				*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Y2center+i)*surface->pitch + ((Xcenter - radius)<<1) )) = col;
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




void DC::DrawEdgedRound_16bit(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height, const Uint16 corner) const
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

	if(this->brush->getStyle() != TRANSPARENT_BRUSH_STYLE) {
		Uint16 brush_col;
		if(!pressedRectangle) {
			brush_col = static_cast<Uint16>(getBrushColor());
		} else {
			brush_col = static_cast<Uint16>(getDarkBrushColor());
		}

		// Rechteck von linker Kante nach rechter Kante

		if(dy > 0)
		{
			SDL_Rect r;
			r.x = static_cast<Sint16>(x+1); 
			r.y = Ycenter;
			r.w = static_cast<Uint16>(width-1); 
			r.h = dy;
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
		//???
		{
			Lock();
			Uint16 rightInc = 6;
			Sint16 diagonalInc = static_cast<Sint16>( 10 - (corner<<2));
			Sint16 d = static_cast<Sint16>(3 - (corner<<1));
			int radius = corner;
			int i = 0;

			while (i <= radius) 
			{
				for(int k = i; k--;)
				{
					*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + ((k + Xcenter - i)<<1) )) = brush_col;
					*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + ((k + X2center)<<1) )) = brush_col;
					*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Y2center+radius)*surface->pitch + ((k + X2center)<<1) )) = brush_col;
				}
				for(int k = radius; k--;)
				{
					*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + ((k + Xcenter - radius)<<1) )) = brush_col;
					*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + ((k + X2center)<<1) )) = brush_col;
					*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Y2center+i)*surface->pitch + ((k + X2center)<<1) )) = brush_col;
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
			Unlock();
		}
	}

	if(pen->getStyle() != TRANSPARENT_PEN_STYLE) {
		// ------ TOP AND LOWER HORIZONTAL LINE ------
		Uint16 dark_pen_col, pen_col;
		if(pressedRectangle)
		{
			dark_pen_col = static_cast<Uint16>(getDarkPressedPenColor());
			pen_col = static_cast<Uint16>(getPressedPenColor());

		} else
		{
			dark_pen_col = static_cast<Uint16>(getDarkPenColor());
			pen_col = static_cast<Uint16>(getPenColor());
		}


		Lock();
		{
			register Uint8* p0 = static_cast<Uint8*>(surface->pixels) + y * surface->pitch + (Xcenter<<1);
			register Uint8* p1 = static_cast<Uint8*>(surface->pixels) + (y+height-1) * surface->pitch + (x<<1);
			int i = corner;
			for(; i--; p1+=2)
				*reinterpret_cast<Uint16*>(p1) = dark_pen_col;
			i = dx;
			for(; i--; p0+=2, p1+=2)
			{
				*reinterpret_cast<Uint16*>(p0) = pen_col; //bright?
				*reinterpret_cast<Uint16*>(p1) = dark_pen_col;
			}
		}
		// ------ END OF TOP AND LOWER HORIZONTAL LINE ------


		// ------ LEFT AND RIGHT VERTICAL LINE ------
		{
			register Uint8* p0 = static_cast<Uint8*>(surface->pixels) + Ycenter*surface->pitch + (x<<1);	 
			register Uint8* p1 = static_cast<Uint8*>(surface->pixels) + Ycenter*surface->pitch + ((x+width-1)<<1);
			int i = dy;
			for(; i--; p0+=surface->pitch, p1+=surface->pitch)
			{
				*reinterpret_cast<Uint16*>(p0) = pen_col; //bright?
				*reinterpret_cast<Uint16*>(p1) = dark_pen_col;
			}
			i = corner;
			for(;i--;p0+=surface->pitch) {
				*reinterpret_cast<Uint16*>(p0) = pen_col;	 //bright?
			}
		}
		// ------ END OF LEFT AND RIGHT VERTICAL LINE ------

		// Halbkreis

		{
			Uint16 rightInc = 6;
			Sint16 diagonalInc = static_cast<Sint16>( 10 - (corner<<2));
			Sint16 d = static_cast<Sint16>(3 - (corner<<1));
			int radius = corner;
			int i = 0;

			while (i <= radius) 
			{
				*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + ((Xcenter - i)<<1) )) = pen_col; // bright ?
				*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + ((Xcenter - radius)<<1) )) = pen_col; // bright ?

				*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + ((X2center + i)<<1) )) = pen_col;
				*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + ((X2center + radius)<<1) )) = pen_col;

				*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Y2center+radius)*surface->pitch + ((X2center + i)<<1) )) = dark_pen_col;
				*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Y2center+i)*surface->pitch + ((X2center + radius)<<1) )) = dark_pen_col;
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


void DC::DrawTab_16bit(const Sint16 x, const Sint16 y, const Uint16 width, const Uint16 height) const
{
	Uint16 corner = 4;
	// Ecke links oben
	Sint16 Xcenter = static_cast<Sint16>(x + corner);
	Sint16 Ycenter = static_cast<Sint16>(y + corner);
	// Kantenlaengen
	Uint16 dx = static_cast<Uint16>(width - (corner << 1));
	Uint16 dy = static_cast<Uint16>(height - (corner << 1));
	// Ecke rechts unten
	Sint16 X2center = static_cast<Sint16>(Xcenter + dx - 1);
	Sint16 Y2center = static_cast<Sint16>(Ycenter + dy - 1);


	if(this->brush->getStyle() != TRANSPARENT_BRUSH_STYLE) {

		Uint16 brush_col;
		if(pressedRectangle) {
			brush_col = static_cast<Uint16>(getBrushColor());
		} else {
			brush_col = static_cast<Uint16>(getDarkBrushColor());
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
		if((corner > 0) && (dx > 0))
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
		//???
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
					*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + ((k + Xcenter - i)<<1) )) = brush_col;
					*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + ((k + X2center)<<1) )) = brush_col;
				}
				for(int k = radius; k--;)
				{
					*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + ((k + Xcenter - radius)<<1) )) = brush_col;
					*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + ((k + X2center)<<1) )) = brush_col;
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

	// ------ TOP AND LOWER HORIZONTAL LINE ------
	if(this->pen->getStyle() != TRANSPARENT_PEN_STYLE) {
		Uint16 dark_pen_col, pen_col;
		if(pressedRectangle)
		{
			dark_pen_col = static_cast<Uint16>(getDarkPressedPenColor());
			pen_col = static_cast<Uint16>(getPressedPenColor());

		} else
		{
			dark_pen_col = static_cast<Uint16>(getDarkPenColor());
			pen_col = static_cast<Uint16>(getPenColor());
		}


		Lock();
		{
			register Uint8* p0 = static_cast<Uint8*>(surface->pixels) + y * surface->pitch + (Xcenter<<1);
			int i = dx;
			for(; i--; p0+=2)
			{
				*reinterpret_cast<Uint16*>(p0) = pen_col;
			}
		}
		// ------ END OF TOP AND LOWER HORIZONTAL LINE ------


		// ------ LEFT AND RIGHT VERTICAL LINE ------
		{
			register Uint8* p0 = static_cast<Uint8*>(surface->pixels) + Ycenter*surface->pitch + (x<<1);	 
			register Uint8* p1 = static_cast<Uint8*>(surface->pixels) + Ycenter*surface->pitch + ((x+width-1)<<1);
			int i = dy + corner;
			for(; i--; p0+=surface->pitch, p1+=surface->pitch)
			{
				*reinterpret_cast<Uint16*>(p0) = pen_col;
				*reinterpret_cast<Uint16*>(p1) = dark_pen_col;
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
				*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + ((Xcenter - i)<<1) )) = pen_col;
				*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + ((Xcenter - radius)<<1) )) = pen_col;

				*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-radius)*surface->pitch + ((X2center + i)<<1) )) = pen_col;
				*(reinterpret_cast<Uint16*>(static_cast<Uint8*>(surface->pixels) + (Ycenter-i)*surface->pitch + ((X2center + radius)<<1) )) = pen_col;

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
