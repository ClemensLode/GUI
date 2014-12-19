#ifndef _GEOMETRY_ENUMS_AUTOSIZE_HPP
#define _GEOMETRY_ENUMS_AUTOSIZE_HPP

enum eAutoSize
{
	// do not resize object after initial creation
	NO_AUTO_SIZE,

	// absolute width/height 
	// TODO really needed? reset to original? 
	CONST_SIZE,

	// use x% of the parent width/height
	AUTO_PARENT_SIZE,

	// use x% of the child width/height
	AUTO_CHILD_SIZE,
	
	MAX_AUTO_SIZES
};

#endif // _GEOMETRY_ENUMS_AUTOSIZE_HPP
