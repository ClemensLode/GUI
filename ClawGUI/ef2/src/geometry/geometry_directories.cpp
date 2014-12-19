#include "geometry_directories.hpp"
#include <misc/singlestorage.hpp>
#include <misc/io.hpp>

class Layout;
class ObjectSize;
class Resolution;

void GeometryDirectories::init() {
	SingleStorage<ObjectSize>::DATA_FILE_NAME = SingleStorage<ObjectSize>::DATA_FILE_NAME_BASE;
	SingleStorage<Resolution>::DATA_FILE_NAME = SingleStorage<Resolution>::DATA_FILE_NAME_BASE;
}

void GeometryDirectories::initTemp(const std::string prefixDirectory) {
	SingleStorage<ObjectSize>::DATA_FILE_NAME = IO::getDirectory(boost::assign::list_of(prefixDirectory)) + SingleStorage<ObjectSize>::DATA_FILE_NAME_BASE;
	SingleStorage<Resolution>::DATA_FILE_NAME = IO::getDirectory(boost::assign::list_of(prefixDirectory)) + SingleStorage<Resolution>::DATA_FILE_NAME_BASE;
}