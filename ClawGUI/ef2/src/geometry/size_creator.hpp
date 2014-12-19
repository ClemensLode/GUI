#ifndef _GEOMETRY_STORAGES_SIZE_CREATOR_HPP
#define _GEOMETRY_STORAGES_SIZE_CREATOR_HPP

#include <misc/nodecreator.hpp>

class Size;

class SizeCreator : public NodeCreator<Size>
{ 
private:
	SizeCreator();
	~SizeCreator();

};

#endif // _GEOMETRY_STORAGES_SIZE_CREATOR_HPP