#include "rect.hpp"
#include <sstream>

const std::string Rect::toString() const
{
	std::ostringstream os;
	os << "(" << getLeft() << " " << getTop() << ") (" << getWidth() << " " << getHeight() << ")";
	return os.str();
}

void Rect::correctStartTargetRectPosition(Point& start_rect_pos, Point& target_rect_pos) {
	if( ((start_rect_pos.getX() < target_rect_pos.getX()) &&
		(this->getLeft() > target_rect_pos.getX() || this->getLeft() < start_rect_pos.getX())) ||
		((start_rect_pos.getX() > target_rect_pos.getX()) && 
		(this->getLeft() < target_rect_pos.getX() || this->getLeft() > start_rect_pos.getX()))) {
			start_rect_pos.setX(this->getLeft());
	}

	if( ((start_rect_pos.getY() < target_rect_pos.getY()) &&
		(this->getTop() > target_rect_pos.getY() || this->getTop() < start_rect_pos.getY())) ||
		((start_rect_pos.getY() > target_rect_pos.getY()) && 
		(this->getTop() < target_rect_pos.getY() || this->getTop() > start_rect_pos.getY()))) {
			start_rect_pos.setY(this->getTop());
	}
}

void Rect::correctStartTargetRectSize(Size& start_rect_size, Size& target_rect_size) {
	if((start_rect_size.getWidth() < target_rect_size.getWidth() && 
		this->getWidth() > target_rect_size.getWidth()) ||

		(start_rect_size.getWidth() > target_rect_size.getWidth() && 
		this->getWidth() < target_rect_size.getWidth())) {

			start_rect_size.setWidth(this->getWidth());
	}

	if((start_rect_size.getHeight() < target_rect_size.getHeight() && 
		this->getHeight() > target_rect_size.getHeight()) || 
		(start_rect_size.getHeight() > target_rect_size.getHeight() && 
		this->getHeight() < target_rect_size.getHeight())) {

			start_rect_size.setHeight(this->getHeight());
	}
}

void Rect::moveSmooth(Rect& start_rect, Rect& target_rect)
{
	if(*this == target_rect) {
		start_rect = target_rect;
		return; // no action
	}

	correctStartTargetRectPosition(start_rect.topLeftCorner, target_rect.topLeftCorner);
	correctStartTargetRectSize(start_rect.rectSize, target_rect.rectSize);
	start_rect.calculateBottomRightCorner();
	target_rect.calculateBottomRightCorner();

	//	std::ostringstream os;
	//	os << "||" << start_rect.getLeft() << ":" << start_rect.getTop() << " -> " << topLeftCorner.getX() << ":" << topLeftCorner.getY() << " -> " << target_rect.getLeft() << ":" << target_rect.getTop();
	//	to_init_log(os.str());

	topLeftCorner.move(start_rect.getTopLeft(), target_rect.getTopLeft());
	rectSize.move(start_rect.getSize(), target_rect.getSize());
	this->calculateBottomRightCorner();
}

// dieses Rect relativ zum anderen...
eTouchType Rect::getTouchType(const Rect& rect) const
{
	if(!isTouched(rect)) {
		return TOUCHES_NO_TOUCH;
	}

	// ist 'rect' innerhalb dieses Rects?
	if(isRectInside(rect)) {
		return TOUCHES_IS_COMPLETELY_INSIDE;
	} else if(isTopLeftCornerInside(rect.getTopLeft()) && isBottomLeftCornerInside(rect.getBottomLeft())) {
		return TOUCHES_CROSSES_RIGHT_BORDER;
	} else if(isTopLeftCornerInside(rect.getTopLeft()) && isTopRightCornerInside(rect.getTopRight())) {
		return TOUCHES_CROSSES_LOWER_BORDER;
	} else if(isTopRightCornerInside(rect.getTopRight()) && isBottomRightCornerInside(rect.getBottomRight())) {
		return TOUCHES_CROSSES_LEFT_BORDER;
	} else if(isBottomRightCornerInside(rect.getBottomRight()) && isBottomLeftCornerInside(rect.getBottomLeft())) {
		return TOUCHES_CROSSES_UPPER_BORDER;
	} else if(isTopLeftCornerInside(rect.getTopLeft())) {
		return TOUCHES_CROSSES_BOTTOM_RIGHT_CORNER;
	} else if(isTopRightCornerInside(rect.getTopRight())) {
		return TOUCHES_CROSSES_BOTTOM_LEFT_CORNER;
	} else if(isBottomRightCornerInside(rect.getBottomRight())) {
		return TOUCHES_CROSSES_TOP_LEFT_CORNER;
	} else if(isBottomLeftCornerInside(rect.getBottomLeft())) {
		return TOUCHES_CROSSES_TOP_RIGHT_CORNER;
	}

	else if((rect.getLeft() < getLeft()) && (rect.getRight() > getRight()) && (rect.getTop() >= getTop()) && (rect.getBottom() <= getBottom())) { // ? = 
		return TOUCHES_CROSSES_LEFT_AND_RIGHT_BORDER;
	} else if((rect.getTop() < getTop()) && (rect.getBottom() > getBottom()) && (rect.getLeft() >= getLeft()) && (rect.getRight() <= getRight())) {
		return TOUCHES_CROSSES_TOP_AND_BOTTOM_BORDER;
	}

	else if((rect.getLeft() == getRight()) && (rect.getTop() == getTop()) && (rect.getBottom() == getBottom())) {
		return TOUCHES_RIGHT_BORDER;
	} else if((rect.getTop() == getBottom()) && (rect.getLeft() == getLeft()) && (rect.getRight() == getRight())) {
		return TOUCHES_LOWER_BORDER;
	} else if((rect.getRight() == getLeft()) && (rect.getTop() == getTop()) && (rect.getBottom() == getBottom())) {
		return TOUCHES_LEFT_BORDER;
	} else if((rect.getBottom() == getTop()) && (rect.getLeft() == getLeft()) && (rect.getRight() == getRight())) {
		return TOUCHES_UPPER_BORDER;
	}

	else if((rect.isTopLeftCornerInside(getTopLeft())) && (rect.isTopRightCornerInside(getTopRight())) && (!rect.isBottomRightCornerInside(getBottomRight())) && (!rect.isBottomLeftCornerInside(getBottomLeft()))) {
		return TOUCHES_CROSSES_UPPER_AREA;
	} else if((!rect.isTopLeftCornerInside(getTopLeft())) && (rect.isTopRightCornerInside(getTopRight())) && (rect.isBottomRightCornerInside(getBottomRight())) && (!rect.isBottomLeftCornerInside(getBottomLeft()))) {
		return TOUCHES_CROSSES_RIGHT_AREA;
	} else if((!rect.isTopLeftCornerInside(getTopLeft())) && (!rect.isTopRightCornerInside(getTopRight())) && (rect.isBottomRightCornerInside(getBottomRight())) && (rect.isBottomLeftCornerInside(getBottomLeft()))) {
		return TOUCHES_CROSSES_LOWER_AREA;
	} else if((rect.isTopLeftCornerInside(getTopLeft())) && (!rect.isTopRightCornerInside(getTopRight())) && (!rect.isBottomRightCornerInside(getBottomRight())) && (rect.isBottomLeftCornerInside(getBottomLeft()))) {
		return TOUCHES_CROSSES_LEFT_AREA;
	}

	else { 
		return TOUCHES_NO_TOUCH;
	}
}

//problem bei touches wenn this ein Rechteck ist, das in das andere Rechteck halb eintaucht


// Faelle: 
// - rect komplett in object enthalten
// - object komplett in rect enthalten
// - zwei Objekt Punkte liegen in rect
// - zwei rect Punkte liegen im Objekt
// - ein Punkt liegt in rect (und umgekehrt)
// - Schnitt zweier Kanten

// Schnitt
const Rect Rect::commonRect(const Rect& rect) const
{
	if(!this->isTouched(rect)) {
		return Rect();
	}

	eTouchType k = getTouchType(rect);
	switch(k)
	{
	case TOUCHES_NO_TOUCH:
		{
			if(rect.getTouchType(*this) == TOUCHES_IS_COMPLETELY_INSIDE)
				return *this;
			else return Rect();
		}break;				
	case TOUCHES_IS_COMPLETELY_INSIDE:return rect;break;
	case TOUCHES_CROSSES_RIGHT_BORDER:return Rect(rect.getTopLeft(), Point(getRight(), rect.getBottom()));break;
	case TOUCHES_CROSSES_LOWER_BORDER:return Rect(rect.getTopLeft(), Point(rect.getRight(), getBottom()));break;
	case TOUCHES_CROSSES_LEFT_BORDER:return Rect(Point(getLeft(), rect.getTop()), rect.getBottomRight());break;
	case TOUCHES_CROSSES_UPPER_BORDER:return Rect(Point(rect.getLeft(), getTop()), rect.getBottomRight());break;
	case TOUCHES_CROSSES_BOTTOM_RIGHT_CORNER:return Rect(rect.getTopLeft(), getBottomRight());break;
	case TOUCHES_CROSSES_BOTTOM_LEFT_CORNER:return Rect(Point(getLeft(), rect.getTop()), Point(rect.getRight(), getBottom()));break;
	case TOUCHES_CROSSES_TOP_LEFT_CORNER:return Rect(getTopLeft(), rect.getBottomRight());break;
	case TOUCHES_CROSSES_TOP_RIGHT_CORNER:return Rect(Point(rect.getLeft(), getTop()), Point(getRight(), rect.getBottom()));break;
	case TOUCHES_CROSSES_LEFT_AND_RIGHT_BORDER:return Rect(Point(getLeft(), rect.getTop()), Point(getRight(), rect.getBottom()));break;
	case TOUCHES_CROSSES_TOP_AND_BOTTOM_BORDER:return Rect(Point(rect.getLeft(), getTop()), Point(rect.getRight(), getBottom()));break;

	case TOUCHES_CROSSES_UPPER_AREA:return Rect(getTopLeft(), Point(getRight(), rect.getBottom()));break;
	case TOUCHES_CROSSES_RIGHT_AREA:return Rect(Point(rect.getLeft(), getTop()), getBottomRight());break;
	case TOUCHES_CROSSES_LOWER_AREA:return Rect(Point(getLeft(), rect.getTop()), getBottomRight());break;
	case TOUCHES_CROSSES_LEFT_AREA:return Rect(getTopLeft(), Point(rect.getRight(), getBottom()));break;
	case TOUCHES_UPPER_BORDER:
	case TOUCHES_LEFT_BORDER:
	case TOUCHES_LOWER_BORDER:
	case TOUCHES_RIGHT_BORDER:
	default:return Rect();break;
	}
}


// ok, laeuft perfekt.
std::list<Rect> Rect::withoutRect(const Rect& rect) const
{

	// Schnittmenge:
	std::list<Rect> rects;
	if(rect == *this) {
		return rects;
	}

	Rect cut = commonRect(rect);

	// Schnitt ist gleich dem Rechteck
	if(cut == *this) {
		return rects;
	} else if(cut.getWidth() == 0 || cut.getHeight() == 0) {
		rects.push_back(*this);
		return rects;
	} else
	{
		// Sonst: bis zu 4 rectangles:
		// Rechteck mit vollstaendiger Breite, wenn cut im unteren Teil stattgefunden hat
		if(cut.getTop() > getTop()) {
			Rect r(getTopLeft(), Point(getRight(), cut.getTop()));
			if(r.getWidth() > 0 && r.getHeight() > 0) {
				rects.push_back(r);
			}
		}
		// links
		if(cut.getLeft() > getLeft()) {
			Rect r(Point(getLeft(), cut.getTop()), cut.getBottomLeft());
			if(r.getWidth() > 0 && r.getHeight() > 0) {
				rects.push_back(r);
			}
		}
		// rechts
		if(cut.getRight() < getRight()) {
			Rect r(cut.getTopRight(), Point(getRight(), cut.getBottom()));
			if(r.getWidth() > 0 && r.getHeight() > 0) {
				rects.push_back(r);
			}
		}
		// unten
		// Rechteck mit vollstaendiger Breite, wenn unter dem cut Recht noch Platz ist
		if(cut.getBottom() < getBottom()) {
			Rect r(Point(getLeft(), cut.getBottom()), getBottomRight());
			if(r.getWidth() > 0 && r.getHeight() > 0) {
				rects.push_back(r);
			}
		}
	}
	return rects;
}




// add the rect to the rect list, merge overlapping rects
std::list<Rect> Rect::removeRects(const std::list<Rect>& rects) const {
	std::list<Rect> remainingRects;
	remainingRects.push_back(*this);

	for(std::list<Rect>::const_iterator i = rects.begin(); i != rects.end(); i++) {
		std::list<Rect> temp;
		for(std::list<Rect>::const_iterator j = remainingRects.begin(); j != remainingRects.end(); j++) {
			std::list<Rect> wr = j->withoutRect(*i);
			temp.insert(temp.end(), wr.begin(), wr.end());
		}
		remainingRects.clear();
		if(temp.size() > 0) {
			remainingRects.insert(remainingRects.end(), temp.begin(), temp.end());
		}
	}

	return remainingRects;
}


		

// Vereinigung, falls es ein schoenes Rect ergibt
/*const std::list<Rect> Rect::connectRect(const Rect& rect, bool& change) const
{
std::list<Rect> t_list;
eTouchType k = touches(rect);
//	to_error_log(k);

change = false;
if( k != TOUCHES_NO_TOUCH)
{

if((k == TOUCHES_CROSSES_LEFT_BORDER) || (k == TOUCHES_LEFT_BORDER))
{
if((getTop() == rect.getTop()) && (getBottom() == rect.getBottom()))
t_list.push_back(Rect(rect.getTopLeft(), getBottomRight()));
}
else if((k == TOUCHES_CROSSES_RIGHT_BORDER) || (k == TOUCHES_RIGHT_BORDER))
{
if((getTop() == rect.getTop()) && (getBottom() == rect.getBottom()))
t_list.push_back(Rect(getTopLeft(), rect.getBottomRight()));
}				
else if((k == TOUCHES_CROSSES_UPPER_BORDER) || (k == TOUCHES_UPPER_BORDER))
{
if((getLeft() == rect.getLeft()) && (getRight() == rect.getRight()))
t_list.push_back(Rect(rect.getTopLeft(), getBottomRight()));
}
else if((k == TOUCHES_CROSSES_LOWER_BORDER) || (k == TOUCHES_LOWER_BORDER))
{
if((getLeft() == rect.getLeft()) && (getRight() == rect.getRight()))
t_list.push_back(Rect(getTopLeft(), rect.getBottomRight()));
}
if(t_list.size() == 0)
{
std::list<Rect> t_list_1;
std::list<Rect> t_list_2;
t_list_1 = withoutRect(rect);
t_list_2 = rect.withoutRect(*this);
if((t_list_1.size() == 1)&& // glatter Schnitt
(t_list_1.front() != *this)) // if there was actually a 'cut'
{
t_list.push_back(t_list_1.front());
t_list.push_back(rect);
change = true;
} else
if((t_list_2.size() == 1)&& // glatter Schnitt
(t_list_1.front() != rect)) // if there was actually a 'cut'
{
t_list.push_back(t_list_2.front());
t_list.push_back(*this);
change = true;
}
} else change = true;
}
return t_list;
}*/

#if 0

void Rect::connectRects(std::list<std::pair<GEOMETRY_Object*, Rect> >& rects)
{
	for(std::list<Rect>::iterator i = rects.begin(); i != rects.end(); ++i)
		for(std::list<Rect>::iterator j = rects.begin(); j != rects.end(); )
			if(i == j)
				++j;
			else if(i->isRectInside(*j))
				j = rects.erase(j);
			else if((j->getWidth() == 0) || (j->getHeight() == 0))
				j = rects.erase(j);
			else
			{
				std::list<Rect> t_list;
				bool change = false;
				t_list = i->connectRect(*j, change);
				if(change)
				{
					rects.erase(i);
					rects.erase(j);
					rects.splice(rects.begin(), t_list);
					j = rects.begin();
					i = rects.begin();
				} else ++j;
			}
			TODO

}
#endif 