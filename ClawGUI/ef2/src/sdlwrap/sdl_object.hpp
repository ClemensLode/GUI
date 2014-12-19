#ifndef _SDL_OBJECT_HPP
#define _SDL_OBJECT_HPP

#include "dc.hpp"
#include <geometry/positionobject.hpp>
#include <geometry/zrect.hpp>
#include "enums/drawtype.hpp"

#include <misc/uuid.hpp>
/*
usage:
derive objects from sdl_object
define the draw function
SDL_Object::processAll for movement
SDL_Object::updateAreasToUpdate to define updateable areas of the screen
SDL_Object::drawAll(dc) to draw the objects
*/

class SDL_Object;

class SDL_Object : public PositionObject 
{
protected:

	SDL_Object(
		SDL_Object* const parentObject, 
		const boost::shared_ptr<const ObjectSize> objectSize,
		const boost::shared_ptr<LayoutManager> layoutManager);


	SDL_Object(const boost::uuids::uuid id, 
		SDL_Object* const parentObject, 
		const boost::shared_ptr<const ObjectSize> objectSize,
		const boost::shared_ptr<LayoutManager> layoutManager);

	~SDL_Object(); 

public:

	bool isShown() const;

	void reloadOriginalSize();


	void makeBufferInvalid();
	void makeBufferValid();
	bool isBufferValid() const;

	void Show(const bool show = true);
	void Hide(const bool hide = true);

	virtual void draw(DC* const dc) const;
	void redrawWholeObject();		
	static void redrawAllRootObjects();

	virtual void process();
	virtual void resetData();

	virtual SDL_Object* checkHighlight(const Point& mouse);
	eDrawType getDrawType() const;
	void setDrawType(const eDrawType draw_type);		

	static void updateAreasToUpdate();
	static void drawAll(DC* dc);
	static void processAll();	
	static void processRects();

	static void resetFocus();
	static void setFocus(SDL_Object* const new_focus);
	static const SDL_Object* getFocus();
	static void setHighlighted(SDL_Object* const new_highlighted);
	static SDL_Object* getHighlighted();
	static void resetHighlighted();	
	static void deleteAllRootObjectBuffers();
	
	bool isHighlighted() const;
	bool isFocused() const;

	void setZ(const signed int zcoord);
	static void cutBorders(const Rect& screen);
	void deleteAllBuffers();

	bool isEnabled() const;
	void enable(const bool enabled = true);
	void disable(const bool disabled = true);

protected:

	void addIfBufferInvalid();
	void checkForChildrenOverlap(const Rect& rect);

private:
	

	static SDL_Object* focus;	
	static SDL_Object* highlighted;
	static std::list<ZRect> oldRectList;
	static std::list<ZRect> newRectList;

	void putOnScreen(DC* dc);
	// TODO , (*i)->getTransparentCornersSize());
	
	static void addToPreviousRects(ZRect zrect);
	static void addToCurrentRects(ZRect zrect);
	void checkHighestZ(std::list<ZRect>& old_rect_list, std::list<ZRect>& new_rect_list);
	bool enabled;
	bool bufferValid;

	SDL_Surface* drawBuffer;
	eDrawType drawType;		
	bool wasShown;	

	void reinitializeDrawBuffer(DC* const dc);
	void deleteDrawBuffer();
	bool shown;
	
	SDL_Object& operator=(const SDL_Object& object);
	SDL_Object(const SDL_Object& object);
};


inline bool SDL_Object::isEnabled() const {
	return enabled;
}

inline void SDL_Object::enable(const bool enabled) {
	this->enabled = enabled;
}

inline void SDL_Object::disable(const bool disabled) {
	this->enabled = !disabled;
}

inline bool SDL_Object::isHighlighted() const {
	return highlighted == this;
}

inline bool SDL_Object::isFocused() const {
	return focus == this;
}

inline void SDL_Object::setFocus(SDL_Object* const new_focus) {
	focus = new_focus;
}

inline void SDL_Object::resetFocus() {
	focus = NULL;
}

inline const SDL_Object* SDL_Object::getFocus() {
	return focus;
}

inline void SDL_Object::setHighlighted(SDL_Object* const new_highlighted) {
	if(highlighted != new_highlighted) {
		if(highlighted != NULL) {
			highlighted->makeBufferInvalid();
		}
		if(new_highlighted != NULL) {
			new_highlighted->makeBufferInvalid();
		}
		highlighted = new_highlighted;
	}
}

inline void SDL_Object::resetHighlighted() {
	setHighlighted(NULL);
}

inline SDL_Object* SDL_Object::getHighlighted() {
	return highlighted;
}

inline eDrawType SDL_Object::getDrawType() const {
	return drawType;
}

inline void SDL_Object::setDrawType(const eDrawType draw_type) {
	drawType = draw_type;
}

inline bool SDL_Object::isBufferValid() const {
	return bufferValid;
}

inline void SDL_Object::Hide(const bool hide) {
	Show(!hide);
}

inline bool SDL_Object::isShown() const {
	return shown;
}

inline void SDL_Object::makeBufferValid() {
	bufferValid = true;
}




#endif // _SDL_OBJECT_HPP

