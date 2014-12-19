#ifndef _GEOMETRY_STORAGES_GEOMETRYDIRECTORIES_HPP
#define _GEOMETRY_STORAGES_GEOMETRYDIRECTORIES_HPP

#include <string>

class GeometryDirectories
{
public:
	static void init();
	static void initTemp(const std::string prefixDirectory); // for tests
};

#endif // _GEOMETRY_STORAGES_GEOMETRYDIRECTORIES_HPP