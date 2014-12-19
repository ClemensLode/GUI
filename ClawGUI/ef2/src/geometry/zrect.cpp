#include "zrect.hpp"

#pragma warning(push, 0)
#include <boost/assert.hpp>
#pragma warning(pop)

ZRect::ZRect(const boost::uuids::uuid id, const Rect& rect, const signed int z, const bool transparent, const bool marked):
	UUID<ZRect>(id),
	rect(rect),
	z(z),
	transparent(transparent),
	marked(marked)
{ 
	BOOST_ASSERT(z >= 0);	
}

ZRect::ZRect(const Rect& rect, const signed int z, const bool transparent, const bool marked):
	UUID<ZRect>(),
	rect(rect),
	z(z),
	transparent(transparent),
	marked(marked)
{
	BOOST_ASSERT(z >= 0);
}

ZRect::~ZRect() {
}

bool ZRect::isInFrontOf(const ZRect& zrect) const {
	if(z > zrect.z || (z == zrect.z && getId() > zrect.getId())) {
		return true;
	} else {
		return false;
	}
}

// remove overlapping rects
void ZRect::eraseOverlappingRects(std::list<ZRect>& rect_list) {
// compare all rects to each other
	//std::list<ZRect> new_rect_list;

	for(std::list<ZRect>::iterator i = rect_list.begin(); i != rect_list.end(); ) {
		std::list<ZRect>::iterator j = i;
		j++;
		while(j != rect_list.end()) {		
			if(i->rect.isTouched(j->getRect())) {
				 
				// remove the upper part from the lower part
				if(i->isInFrontOf(*j)) {
					std::list<Rect> without_rect_list = j->getRect().withoutRect(i->getRect());
					for(std::list<Rect>::iterator s = without_rect_list.begin(); s != without_rect_list.end(); s++) {
						rect_list.push_back(ZRect(j->getId(), *s, j->getZ()));
					}
					j = rect_list.erase(j);
				} else if(j->isInFrontOf(*i)) {
					std::list<Rect> without_rect_list = i->rect.withoutRect(j->getRect());
					for(std::list<Rect>::iterator s = without_rect_list.begin(); s != without_rect_list.end(); s++) {
						rect_list.push_back(ZRect(i->getId(), *s, i->getZ()));
					}
					i = rect_list.erase(i);
					break;
				} else {
					j++;
				}
				
			} else {
				j++;
			}
		}
		i++;
	}
	
	//rect_list.insert(rect_list, new_rect_list.begin(), new_rect_list.end());
}



void ZRect::eraseOverlappingRects(std::list<ZRect>& old_rect_list, std::list<ZRect>& new_rect_list) {
	for(std::list<ZRect>::iterator i = new_rect_list.begin(); i != new_rect_list.end(); ) {
		for(std::list<ZRect>::iterator j = old_rect_list.begin(); j != old_rect_list.end(); ) {
			// remove part of oldrects that are covered by a new rect with larger z
			if((i->getId() == j->getId() || i->isInFrontOf(*j)) && i->rect.isTouched(j->getRect())) {
				std::list<Rect> without_rect_list = j->rect.withoutRect(i->getRect());
				std::list<ZRect> new_without_rect_list;
				for(std::list<Rect>::iterator s = without_rect_list.begin(); s != without_rect_list.end(); s++) {
					new_without_rect_list.push_back(ZRect(i->getId(), *s, i->getZ()));
				}
				old_rect_list.insert(j, new_without_rect_list.begin(), new_without_rect_list.end());
				j = old_rect_list.erase(j);
			} else {
				j++;
			}
		}
		i++;
	}
}
// result: 


void ZRect::cutBorders(const Rect& screen, std::list<ZRect>& rectList) {
	for(std::list<ZRect>::iterator i = rectList.begin(); i != rectList.end(); ) {
		Rect common_rect = i->getRect().commonRect(screen);
		if(common_rect != i->getRect()) {
			if(common_rect.getSize() != Size()) {
				rectList.push_front(ZRect(i->getId(), common_rect, i->getZ()));
			}
			i = rectList.erase(i);
		} else {
			i++;
		}
	}
}



const std::string ZRect::toString() const
{
	std::ostringstream os;
	os << "[" << getRect() << " <" << getZ() << "> ]";
	return os.str();
}