#ifndef _GEOMETRY_ZRECT_HPP
#define _GEOMETRY_ZRECT_HPP

#include <list>

#include "rect.hpp"

#include <misc/uuid.hpp>

class ZRect : public UUID<ZRect>
{
	friend std::ostream& operator<<(std::ostream& out, ZRect val) {out << val.toString();return out;}
	public:
		ZRect(const boost::uuids::uuid id, const Rect& rect, const signed int z, const bool transparent = false, const bool marked = false);
		ZRect(const Rect& rect, const signed int z, const bool transparent = false, const bool marked = false);
		~ZRect();
	
		bool isInFrontOf(const ZRect& zrect) const;
		static void eraseOverlappingRects(std::list<ZRect>& rect_list);
		static void eraseOverlappingRects(std::list<ZRect>& old_rect_list, std::list<ZRect>& new_rect_list);
		static void connectRects(std::list<ZRect>& rect_list);

		const Rect& getRect() const;
		signed int getZ() const;

		void setMarked();

		bool isMarked() const;
		bool isTransparent() const;

		const std::string toString() const;

		static void cutBorders(const Rect& screen, std::list<ZRect>& rectList);

	private:
		const Rect rect;
		const signed int z;
		const bool transparent;
		bool marked;
};

inline const Rect& ZRect::getRect() const {
	return rect;
}

inline signed int ZRect::getZ() const {
	return z;
}

inline bool ZRect::isTransparent() const {
	return transparent;
}

inline void ZRect::setMarked() {
	marked = true;
}

inline bool ZRect::isMarked() const {
	return marked;
}

#endif // _GEOMETRY_ZRECT_HPP