#include "guicore_directories.hpp"
#include <misc/singlestorage.hpp>
#include <misc/io.hpp>

class Animation;
class Bitmap;
class Brush;
class ButtonAnimation;
class ButtonColors;
class Color;
class Cursor;
class Font;
class FontType;
class ObjectSize;
class Pen;
class WindowColors;
class Theme;
class Resolution;

void GuiCoreDirectories::init() {
	SingleStorage<Animation>::DATA_FILE_NAME = SingleStorage<Animation>::DATA_FILE_NAME_BASE;
	SingleStorage<Bitmap>::DATA_FILE_NAME = SingleStorage<Bitmap>::DATA_FILE_NAME_BASE;
	SingleStorage<Brush>::DATA_FILE_NAME = SingleStorage<Brush>::DATA_FILE_NAME_BASE;
	SingleStorage<ButtonAnimation>::DATA_FILE_NAME = SingleStorage<ButtonAnimation>::DATA_FILE_NAME_BASE;
	SingleStorage<ButtonColors>::DATA_FILE_NAME = SingleStorage<ButtonColors>::DATA_FILE_NAME_BASE;
	SingleStorage<Color>::DATA_FILE_NAME = SingleStorage<Color>::DATA_FILE_NAME_BASE;
	SingleStorage<Cursor>::DATA_FILE_NAME = SingleStorage<Cursor>::DATA_FILE_NAME_BASE;
	SingleStorage<Font>::DATA_FILE_NAME = SingleStorage<Font>::DATA_FILE_NAME_BASE;
	SingleStorage<FontType>::DATA_FILE_NAME = SingleStorage<FontType>::DATA_FILE_NAME_BASE;
	SingleStorage<Pen>::DATA_FILE_NAME = SingleStorage<Pen>::DATA_FILE_NAME_BASE;
	SingleStorage<Theme>::DATA_FILE_NAME = SingleStorage<Theme>::DATA_FILE_NAME_BASE;
	SingleStorage<WindowColors>::DATA_FILE_NAME = SingleStorage<WindowColors>::DATA_FILE_NAME_BASE;
}

void GuiCoreDirectories::initTemp(const std::string prefixDirectory) {
	SingleStorage<Animation>::DATA_FILE_NAME = IO::getDirectory(boost::assign::list_of(prefixDirectory)) + SingleStorage<Animation>::DATA_FILE_NAME_BASE;
	SingleStorage<Bitmap>::DATA_FILE_NAME = IO::getDirectory(boost::assign::list_of(prefixDirectory)) + SingleStorage<Bitmap>::DATA_FILE_NAME_BASE;
	SingleStorage<Brush>::DATA_FILE_NAME = IO::getDirectory(boost::assign::list_of(prefixDirectory)) + SingleStorage<Brush>::DATA_FILE_NAME_BASE;
	SingleStorage<ButtonAnimation>::DATA_FILE_NAME = IO::getDirectory(boost::assign::list_of(prefixDirectory)) + SingleStorage<ButtonAnimation>::DATA_FILE_NAME_BASE;
	SingleStorage<ButtonColors>::DATA_FILE_NAME = IO::getDirectory(boost::assign::list_of(prefixDirectory)) + SingleStorage<ButtonColors>::DATA_FILE_NAME_BASE;
	SingleStorage<Color>::DATA_FILE_NAME = IO::getDirectory(boost::assign::list_of(prefixDirectory)) + SingleStorage<Color>::DATA_FILE_NAME_BASE;
	SingleStorage<Cursor>::DATA_FILE_NAME = IO::getDirectory(boost::assign::list_of(prefixDirectory)) + SingleStorage<Cursor>::DATA_FILE_NAME_BASE;
	SingleStorage<Font>::DATA_FILE_NAME = IO::getDirectory(boost::assign::list_of(prefixDirectory)) + SingleStorage<Font>::DATA_FILE_NAME_BASE;
	SingleStorage<FontType>::DATA_FILE_NAME = IO::getDirectory(boost::assign::list_of(prefixDirectory)) + SingleStorage<FontType>::DATA_FILE_NAME_BASE;
	SingleStorage<Pen>::DATA_FILE_NAME = IO::getDirectory(boost::assign::list_of(prefixDirectory)) + SingleStorage<Pen>::DATA_FILE_NAME_BASE;
	SingleStorage<Theme>::DATA_FILE_NAME = IO::getDirectory(boost::assign::list_of(prefixDirectory)) + SingleStorage<Theme>::DATA_FILE_NAME_BASE;
	SingleStorage<WindowColors>::DATA_FILE_NAME = IO::getDirectory(boost::assign::list_of(prefixDirectory)) + SingleStorage<WindowColors>::DATA_FILE_NAME_BASE;
}