#include "sdl_object.hpp"

#include <misc/log.hpp>

#pragma warning(push, 0)
#include <boost/assert.hpp>
#pragma warning(pop)

#include <misc/ids.hpp>
#include <guicore/pen_storage.hpp>


SDL_Object::SDL_Object(SDL_Object* const parentObject, 
		const boost::shared_ptr<const ObjectSize> objectSize,
		const boost::shared_ptr<LayoutManager> layoutManager) :
	PositionObject(parentObject, objectSize, layoutManager),
	enabled(true),
	bufferValid(false),
	drawBuffer(NULL),
	drawType(SOLID_OBJECT),
	wasShown(false),
	shown(true)
{
	Show();
}

SDL_Object::SDL_Object(const boost::uuids::uuid id, SDL_Object* const parentObject, 
		const boost::shared_ptr<const ObjectSize> objectSize,
		const boost::shared_ptr<LayoutManager> layoutManager) :
	PositionObject(id, parentObject, objectSize, layoutManager),
	enabled(true),
	bufferValid(false),
	drawBuffer(NULL),
	drawType(SOLID_OBJECT),
	wasShown(false),
	shown(true)
{
	Show();
}


SDL_Object::~SDL_Object()
{
//	Show(false);

	if(SDL_Object::focus == this) {
		SDL_Object::resetFocus();
	}

	if(SDL_Object::highlighted == this) {
		SDL_Object::resetHighlighted();
	}

}



void SDL_Object::process()
{
	if(!isShown()) {
		return; 
	}

	bool transparent = (getDrawType() == TRANSPARENT_OBJECT) || (getDrawType() == ANTI_ALIASED_OBJECT);
	// 2. Bewege/Vergrößere/Verkleinere Objekte, -> PositionObject
	move();

	if(wasResized()) {
		// 1. targetSize = rect? deleteDrawBuffer
		// 2. targetSize > rect? deleteDrawBuffer
		if(getSize() == getTargetSize() || getWidth() > getTargetWidth() || getHeight() > getTargetHeight()) {
		// we need to allocate a new draw buffer
			deleteDrawBuffer();
		} else {
		// 3. targetSize < keep surface until (1.)
			makeBufferInvalid();
		}
		// we need to inform parents and children about the size change
		signalSizeChange();
	}

	// 3. Falls bewegt, hidden oder (Transparent und invalid) füge Objekt zu OldRects mit altem Rect, ID und Z hinzu
	if(((!bufferValid) && transparent) || wasMoved() || (!wasShown)) {
		addToPreviousRects(ZRect(getId(), oldRect, getZ(), transparent));
	}

	if((!bufferValid) || wasMoved() || wasShown) {
		// 4. Falls Buffer invalid oder bewegt markiere TOP Rect als 'to paint'
		addToCurrentRects(ZRect(getId(), getAbsoluteRect(), getZ(), transparent, true));
	} else {
		// 5. Füge Objekt zu TOP Rects mit neuem Rect, ID, Z und Transparency hinzu
		addToCurrentRects(ZRect(getId(), getAbsoluteRect(), getZ(), transparent));
	}
	
	// wasShown = shown;

	// 1. Setze oldRect = aktuelles Rect, needs to be here at the end because process of the parent class might have changed the size or position!
	oldRect = getAbsoluteRect();

	// process children - targetsize and targetposition might change
	ObjectNode* tmp = getChildren();  // process all children of gadget
	if (tmp) {
		do {
			static_cast<SDL_Object*>(tmp)->process();
			tmp = tmp->getNextBrother();
		} while (tmp != getChildren());
	}
}


void SDL_Object::processRects() {

	// TODO optimize
	for(std::list<ZRect>::const_iterator i = newRectList.begin(); i != newRectList.end(); i++) {
		if(i->isMarked()) {
			// 6. Betrachte alle "to paint" TOP Rects, markiere transparente Schnittrects darüberliegender TOP Rects als 'to paint'
			for(std::list<ZRect>::iterator j = newRectList.begin(); j != newRectList.end(); ) {
				if(i == j || !i->getRect().isTouched(j->getRect())) {
					j++;
					continue;
				}

				if((!j->isMarked()) && j->isTransparent() && j->isInFrontOf(*i)) {
					Rect cr = j->getRect().commonRect(i->getRect());
					std::list<Rect> wrj = j->getRect().withoutRect(i->getRect());
					addToCurrentRects(ZRect(j->getId(), cr, j->getZ(), true, true));
					for(std::list<Rect>::const_iterator k = wrj.begin(); k != wrj.end(); k++) {
						addToCurrentRects(ZRect(j->getId(), *k, j->getZ(), true, false));
					}
					j = newRectList.erase(j);
				} else 
					// 7. Betrachte alle nichttransparenten "to paint" TOP Rects, entferne Schnittrects darunterliegender TOP Rects
					if(!i->isTransparent() && i->isInFrontOf(*j)) {
						std::list<Rect> wr = j->getRect().withoutRect(i->getRect());
						for(std::list<Rect>::const_iterator k = wr.begin(); k != wr.end(); k++) {
							addToCurrentRects(ZRect(j->getId(), *k, j->getZ(), j->isTransparent(), j->isMarked()));
						}
						j = newRectList.erase(j);
					} else {
						j++;
					}
			}
		}
	}



	// 8. Betrachte alle old Rects, markiere transparente Schnittrects darüberliegender TOP Rects als 'to paint'
	for(std::list<ZRect>::iterator i = oldRectList.begin(); i != oldRectList.end(); i++) {

		for(std::list<ZRect>::iterator j = newRectList.begin(); j != newRectList.end(); ) {
			if(j->isMarked() || (!j->isTransparent()) || (!i->getRect().isTouched(j->getRect()))) {
				j++;
				continue;
			}

			if(j->isInFrontOf(*i)) {
				Rect cr = j->getRect().commonRect(i->getRect());
				std::list<Rect> wrj = j->getRect().withoutRect(i->getRect());
				addToCurrentRects(ZRect(j->getId(), cr, j->getZ(), true, true));
				for(std::list<Rect>::const_iterator k = wrj.begin(); k != wrj.end(); k++) {
					addToCurrentRects(ZRect(j->getId(), *k, j->getZ(), true, true));
				}
				j = newRectList.erase(j);
			} else {
				j++;
			}
		}
	}

	// 9. Betrachte alle old Rects, markiere Schnittrects darunterliegender TOP Rects als 'to paint', entferne oldRect Schnitte dabei
	for(std::list<ZRect>::iterator i = oldRectList.begin(); i != oldRectList.end(); ) {
		bool erased = false;
		for(std::list<ZRect>::iterator j = newRectList.begin(); j != newRectList.end(); ) {
			if((!j->isMarked()) && i->isInFrontOf(*j) && i->getRect().isTouched(j->getRect())){ 
				Rect cr = j->getRect().commonRect(i->getRect());
				std::list<Rect> wrj = j->getRect().withoutRect(i->getRect());
				addToCurrentRects(ZRect(j->getId(), cr, j->getZ(), j->isTransparent(), true));
				for(std::list<Rect>::const_iterator k = wrj.begin(); k != wrj.end(); k++) {
					addToCurrentRects(ZRect(j->getId(), *k, j->getZ(), j->isTransparent()));
				}

				wrj = i->getRect().withoutRect(j->getRect());
				for(std::list<Rect>::const_iterator k = wrj.begin(); k != wrj.end(); k++) {
					addToPreviousRects(ZRect(i->getId(), *k, i->getZ(), i->isTransparent()));
				}
				erased = true;
				i = oldRectList.erase(i);
				j = newRectList.erase(j);

				if(i == oldRectList.end()) {
					break;
				}
			} else {
				j++;
			}
		}
		if(!erased) {
			i++;
		}

	}



	// 10. Entferne alle Rects die nicht als 'to paint' markiert sind
	for(std::list<ZRect>::iterator j = newRectList.begin(); j != newRectList.end(); ) {
		if(!j->isMarked()) {
			j = newRectList.erase(j);
		} else {
			j++;
		}
	}



}


// cut borders of screen from rects
void SDL_Object::cutBorders(const Rect& screen) {
	ZRect::cutBorders(screen, oldRectList);
	ZRect::cutBorders(screen, newRectList);
}



void SDL_Object::updateAreasToUpdate()
{

	//	rootObjectList.sort(sort_objects_by_z());
	/*
	Update areas

	- if size/position has changed: add old and new rect OK
	- if buffer invalid: add new rect                    OK

	- remove same new rects with same or larger z

	- remove intersections of old rects with new rects with larger z
	*/

	//	ZRect::eraseOverlappingRects(newRectList);
	//	ZRect::eraseOverlappingRects(oldRectList);

	//durch alle Objekte laufen, oldRectList überprüfen und das größte z zuweisen

	for(std::list<ObjectNode*>::const_iterator i = rootObjectList.begin(); i != rootObjectList.end(); ++i) {
		static_cast<SDL_Object*>(*i)->checkHighestZ(oldRectList, newRectList);
	}
	//	Remove all newRects from oldRects 
	ZRect::eraseOverlappingRects(oldRectList, newRectList);

	/*
	Aktualisiere Gebiete:

	- if size/position has changed: add old and new rect
	- if buffer invalid: add new rect

	- remove same new rects with same z
	- remove intersections of old rects with new rects with larger z
	// - merge new rects?
	// - merge old rects?


	Copy contents:

	buffer invalid:
	- remove all areas with larger z (neues rect)

	buffer valid:
	- copy only intersection with larger z (altes rect)
	*/

}

void SDL_Object::checkHighestZ(std::list<ZRect>& old_rect_list, std::list<ZRect>& new_rect_list) {

	std::list<ZRect> add_to_list;

	// Finde die Rects der Elemente die am vordersten sind
	for(std::list<ZRect>::iterator i = old_rect_list.begin(); i != old_rect_list.end(); ) {

		if(i->getRect().isTouched(getAbsoluteRect())) {

			// old_rect vor Objekt?

			if(i->isInFrontOf(ZRect(getId(), Rect(), getZ())))
				// Oldrect ist näher am Betrachter => Dahinterliegendes (this) muss neugezeichnet werden
				// Suche größtes dahinterliegendes!
			{
				//		std::ostringstream os;
				//		os << "Old rect touches " << getAbsoluteRect().toString() << " with Z " << i->getZ() << ">=" << getZ() << " und ID " << i->ID << ">" << ID;
				//		to_init_log(os.str());


				//TODO größte ID?
				// jeder braucht noch TempID und tempz, sonst wird z.B. ID 2 durch ID 0 upgedated und ID 1 übersprungen!
				//	os.str("");
				//	os << "Update ID " << i->ID << " with ID " << ID;
				//	to_init_log(os.str());

				// part gets the new id, part gets the old id
				add_to_list.push_back(ZRect(getId(), i->getRect().commonRect(getAbsoluteRect()), i->getZ()));

				// füge Restteil ein
				std::list<Rect> wr = i->getRect().withoutRect(getAbsoluteRect());
				for(std::list<Rect>::iterator j = wr.begin(); j != wr.end(); j++) {
					add_to_list.push_back(ZRect(i->getId(), *j, i->getZ()));
					//		to_init_log("Add Z " + j->toString());
				}
				i = old_rect_list.erase(i);
			} else if(ZRect(getId(), Rect(), getZ()).isInFrontOf(*i))
			{
				//new_rect_list.push_back(ZRect(getId(), i->getRect().commonRect(getAbsoluteRect()), getZ()));
				add_to_list.push_back(ZRect(getId(), i->getRect().commonRect(getAbsoluteRect()), getZ()));
				//	to_init_log("Add new Rect from Z: " + i->getRect().commonRect(getAbsoluteRect()).toString() + "(rect: " + getAbsoluteRect().toString() + " / old rect: " + i->getRect().toString() + ")");
				//	std::ostringstream os;
				//	os << ID << " > " << i->ID;
				//	to_init_log(os.str());
				std::list<Rect> wr = i->getRect().withoutRect(getAbsoluteRect());
				for(std::list<Rect>::iterator j = wr.begin(); j != wr.end(); j++) {
					add_to_list.push_back(ZRect(i->getId(), *j, i->getZ()));
					//					to_init_log("Add Z " + j->toString());
				}
				i = old_rect_list.erase(i);				
			} else {
				i++;
			}
		} else {
			i++;
		}
	}
	old_rect_list.insert(old_rect_list.end(), add_to_list.begin(), add_to_list.end());


	// es können mehrere Rects ein Gebiet mit NewRect beanspruchen! Nur vordersten nehmen!
	// verdeckte newrects außerdem abschneiden! TODO

	for(std::list<ZRect>::iterator i = new_rect_list.begin(); i != new_rect_list.end(); ) {
		if(i->getRect().isTouched(getAbsoluteRect()) && 
			ZRect(getId(), Rect(), getZ()).isInFrontOf(*i)) {
				// Rechteck ist weiter entfernt, Davorliegendes muss nicht neugezeichnet werden
				// Entferne Teil von oldRectList
				//to_init_log("Remove " + i->getRect().commonRect(getAbsoluteRect()).toString() + " from newRect " + i->getRect().toString());
				// alte rect-Teile mit altem Z initialisieren
				std::list<Rect> l = i->getRect().withoutRect(getAbsoluteRect());
				for(std::list<Rect>::iterator j = l.begin(); j != l.end(); j++) {
					new_rect_list.push_back(ZRect(i->getId(), *j, i->getZ()));
				}
				new_rect_list.push_back(ZRect(getId(), i->getRect().commonRect(getAbsoluteRect()), getZ()));
				i = new_rect_list.erase(i);
		} else {
			i++;
		}
	}




	ObjectNode* tmp = getChildren();  // process all children of gadget
	if (tmp) {
		do {
			static_cast<SDL_Object*>(tmp)->checkHighestZ(old_rect_list, new_rect_list);
			tmp = tmp->getNextBrother();
		} while (tmp != getChildren());
	}	
}


// put single object on screen
void SDL_Object::putOnScreen(DC* const dc)
{
	BOOST_ASSERT(dc);

	if (!isShown()) {
		return;
	}

	/*Copy contents:

	buffer invalid / moved:
	- remove all areas with larger z (neues rect)

	buffer valid:
	- copy only intersection with larger z (altes rect)
	*/
	//alle objekte mit newrect rein? mmh oder durch alle durchlaufen... bei highestZ... mmmh....
	std::list<Rect> blitRectList;
	/*
	// everything that isn't covered by other objects (newrects) needs to be redrawn
	if(!isBufferValid() || wasMoved()) { // size has changed, item has moved or contents have changed
	// first assume to blit everything
	Rect common_rect = Rect(Point(0,0), dc->getSize()).commonRect(getAbsoluteRect());
	if(common_rect.getSize() != Size()) {


	blitRectList.push_back(common_rect);

	// now remove all areas which are covered by new objects with a larger Z	
	for(std::list<ZRect>::iterator i = newRectList.begin(); i != newRectList.end(); i++) {
	if(i->isInFrontOf(ZRect(getId(), Rect(), getZ()))) {
	std::list<Rect> add_blit_rect_list;
	// check all blitRectList parts
	for(std::list<Rect>::iterator j = blitRectList.begin(); j != blitRectList.end(); ) {
	if(i->getRect().isTouched(*j)) {
	// remove the area which is overlapped by the new rectangle
	std::list<Rect> new_list = j->withoutRect(i->getRect());
	add_blit_rect_list.insert(add_blit_rect_list.end(), new_list.begin(), new_list.end());
	j = blitRectList.erase(j);
	} else {
	j++;
	}
	}
	blitRectList.insert(blitRectList.end(), add_blit_rect_list.begin(), add_blit_rect_list.end());
	add_blit_rect_list.clear();				
	}
	}		
	}



	// object was not moved or redrawn
	// no check required, except checking whether objects that were above
	// this object moved away.

	// only redraw parts that were formerly covered by other objects, we removed newRects from oldRects before
	else {
	for(std::list<ZRect>::iterator i = oldRectList.begin(); i != oldRectList.end(); i++) {
	if(i->getId() == getId()) {
	blitRectList.push_back(i->getRect());
	}
	}		
	}*/
	//	TODO newRectList immer leer!
	for(std::list<ZRect>::const_iterator i = newRectList.begin(); i != newRectList.end(); i++) {
		if(i->getId() == getId()) {
			blitRectList.push_back(i->getRect());
		}
	}

	if(blitRectList.size() > 0) {
		//Situation: Liegt B über C und A über B und C, dann eliminiert darüberliegendes B das old_rect komplett...
		//			   bzw. kein new_rect wird gesetzt!

		//	Liegt old_rect über 

		// use drawBuffer only with solid objects
		if(getDrawType() != ANTI_ALIASED_OBJECT)
		{
			bool clear_buffer = false;
			if(drawBuffer == NULL) {
				reinitializeDrawBuffer(dc);
			} else {
				if(getDrawType() == TRANSPARENT_OBJECT) {
					clear_buffer = true;
				}
			}

			if(!isBufferValid())
			{
				if(clear_buffer) {
					SDL_FillRect(drawBuffer, NULL, 0);
				}
				dc->switchToSurface(drawBuffer);
				dc->drawFromPoint(Point(0,0));		
				draw(dc); // fill buffer
				dc->switchToOriginalSurface();				
			} else {
				dc->drawFromPoint(getAbsolutePosition());
			}

			// copy rectangles from buffer to screen, add rectangle to dc screen update procedure
			for(std::list<Rect>::iterator i = blitRectList.begin(); i != blitRectList.end(); )
			{
				Point p = getAbsolutePosition();
				SDL_Rect source = Rect::createRect(Point(static_cast<Sint16>(i->getLeft() - p.getX()), static_cast<Sint16>(i->getTop() - p.getY())), i->getSize());
				SDL_Rect target = Rect::createRect(i->getTopLeft(), Size());
				SDL_BlitSurface(drawBuffer, &source, dc->getSurface(), &target);
				dc->addRectangle(*i);
				i = blitRectList.erase(i);
			}

		} else 
		{
			dc->addRectangle(getAbsoluteRect());
			dc->drawFromPoint(this->getAbsolutePosition());
			draw(dc);
		}
		
		blitRectList.clear();
		
	}
	makeBufferValid();
	ObjectNode* tmp = getChildren();
	if (tmp) {
		do {
			static_cast<SDL_Object*>(tmp)->putOnScreen(dc);
			tmp = tmp->getNextBrother();
		} while (tmp != getChildren());
	}

	
}


// don't call this function during initialization! oldrect will be initialized wrongly (? really?)
void SDL_Object::setZ(const signed int zcoord)
{
	// TODO ID?
	addToPreviousRects(ZRect(getId(), getAbsoluteRect(), getZ())); // TODO? does this work?

	ObjectNode::setZ(zcoord);

	addToCurrentRects(ZRect(getId(), getAbsoluteRect(), getZ()));
}


// contents of 'zrect' are now visible again, re-copy all objects at the top
void SDL_Object::addToPreviousRects(ZRect zrect) {
	if(zrect.getRect().getWidth() > 0 && zrect.getRect().getHeight() > 0) {
		oldRectList.push_back(zrect);
	}
}


// contents of 'rect' were changed (because the object moved or because the object was redrawn)
void SDL_Object::addToCurrentRects(ZRect zrect) {
	if(zrect.getRect().getWidth() > 0 && zrect.getRect().getHeight() > 0) {
		newRectList.push_back(zrect);
	}
}


void SDL_Object::makeBufferInvalid() {
	bufferValid = false;
}


void SDL_Object::Show(const bool show)
{
	// show value has changed
	if(show != shown) {
		wasShown = shown;
		shown = show;

		if(SDL_Object::focus == this) {
			SDL_Object::resetFocus();
		}
		if(SDL_Object::highlighted == this) {
			SDL_Object::resetHighlighted();
		}

		if(isShown()) {
			// draw the new item
			addToCurrentRects(ZRect(getId(), getAbsoluteRect(), getZ()));
		} else {
			// signal all objects that were below this object that they might need a redraw
			addToPreviousRects(ZRect(getId(), getAbsoluteRect(), getZ()));
		}

		if(getParent()) {
			getParent()->setChildrenWereChanged();
		}
	}
}

void SDL_Object::draw(DC* const dc) const {
	BOOST_ASSERT(dc);
}

void SDL_Object::deleteDrawBuffer() {
	if(drawBuffer != NULL) {
		SDL_FreeSurface(drawBuffer);
		drawBuffer = NULL;
	}
	makeBufferInvalid();
}

void SDL_Object::reinitializeDrawBuffer(DC* const dc) {
	const SDL_PixelFormat* pixel_format = dc->getSurface()->format;
	Size s(this->getSize());
	drawBuffer = SDL_CreateRGBSurface( SDL_SWSURFACE, s.getWidth(), s.getHeight(), dc->getBits(), pixel_format->Rmask, pixel_format->Gmask, pixel_format->Bmask, pixel_format->Amask);
	makeBufferInvalid();
	if(getDrawType() == TRANSPARENT_OBJECT) {
		SDL_SetColorKey(drawBuffer, SDL_SRCCOLORKEY , SDL_MapRGB(drawBuffer->format, 0, 0, 0));
	}

}


/**
* Process all root objects
*/
void SDL_Object::processAll()
{
	for(std::list<ObjectNode*>::const_iterator i = rootObjectList.begin(); i != rootObjectList.end(); ++i) {
		static_cast<SDL_Object*>(*i)->process();
	}
}



void SDL_Object::drawAll(DC* const dc) {
	BOOST_ASSERT(dc);

	for(std::list<ObjectNode*>::const_iterator i = rootObjectList.begin(); i != rootObjectList.end(); i++ ) {		
		static_cast<SDL_Object*>(*i)->putOnScreen(dc);
	}

	oldRectList.clear();
	newRectList.clear();
}


SDL_Object* SDL_Object::checkHighlight(const Point& mouse)
{
	if(!isShown()) {
		return NULL;
	}

	ObjectNode* tmp = getChildren();  // process all children of gadget

	SDL_Object* result = NULL;
	if(tmp) {
		do 
		{
			result = static_cast<SDL_Object*>(tmp)->checkHighlight(mouse);
			tmp = tmp->getNextBrother();
		} while( tmp != getChildren() && (result == NULL) );
	}

	return result;
}

void SDL_Object::redrawAllRootObjects() {
	for(std::list<ObjectNode*>::const_iterator i = rootObjectList.begin(); i != rootObjectList.end(); i++ ) {		
		static_cast<SDL_Object*>(*i)->redrawWholeObject();
	}
}

void SDL_Object::deleteAllRootObjectBuffers() {
	for(std::list<ObjectNode*>::const_iterator i = rootObjectList.begin(); i != rootObjectList.end(); i++ ) {		
		static_cast<SDL_Object*>(*i)->deleteAllBuffers();
	}
}

void SDL_Object::deleteAllBuffers() {
	if(!isShown()) {
		return;
	}

	deleteDrawBuffer();

	// todo evtl raus
	ObjectNode* tmp = getChildren();  // process all children of gadget
	if (tmp) {
		do {
			static_cast<SDL_Object*>(tmp)->deleteAllBuffers();
			tmp = tmp->getNextBrother();
		} while (tmp != getChildren());
	}	
}


void SDL_Object::redrawWholeObject() {
	if(!isShown()) {
		return;
	}
	makeBufferInvalid();

	// todo evtl raus
	ObjectNode* tmp = getChildren();  // process all children of gadget
	if (tmp) {
		do {
			static_cast<SDL_Object*>(tmp)->redrawWholeObject();
			tmp = tmp->getNextBrother();
		} while (tmp != getChildren());
	}	
}

void SDL_Object::resetData()
{ 
	ObjectNode* tmp = getChildren();  // process all children of gadget
	if (tmp) {
		do {
			static_cast<SDL_Object*>(tmp)->resetData();
			tmp = tmp->getNextBrother();

		} while (tmp != getChildren());
	}
}


SDL_Object* SDL_Object::focus = NULL;
SDL_Object* SDL_Object::highlighted = NULL;
std::list<ZRect> SDL_Object::oldRectList;
std::list<ZRect> SDL_Object::newRectList;
