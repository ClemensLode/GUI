#ifndef _GEOMETRY_ENUMS_LAYOUTTYPE_HPP
#define _GEOMETRY_ENUMS_LAYOUTTYPE_HPP

enum eLayoutType
{
	HORIZONTAL_LAYOUT_TYPE,

	VERTICAL_LAYOUT_TYPE,

	GRID_TWO_COLUMNS_LAYOUT_TYPE, // fill a 2xn grid, using the maximal width/height of all objects as size for a single cell
	GRID_TWO_LINES_LAYOUT_TYPE, // fill a nx2 grid, using the maximal width/height of all objects as size for a single cell

	MAX_LAYOUT_TYPES
};

#endif // _GEOMETRY_ENUMS_LAYOUTTYPE_HPP
