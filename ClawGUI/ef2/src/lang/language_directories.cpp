#include "language_directories.hpp"
#include <misc/singlestorage.hpp>
#include <misc/io.hpp>

class Text;
class Language;

void LanguageDirectories::init() {
	SingleStorage<Text>::DATA_FILE_NAME = SingleStorage<Text>::DATA_FILE_NAME_BASE;
	SingleStorage<Language>::DATA_FILE_NAME = SingleStorage<Language>::DATA_FILE_NAME_BASE;
}

void LanguageDirectories::initTemp(const std::string prefixDirectory) {
	SingleStorage<Text>::DATA_FILE_NAME = IO::getDirectory(boost::assign::list_of(prefixDirectory)) + SingleStorage<Text>::DATA_FILE_NAME_BASE;
	SingleStorage<Language>::DATA_FILE_NAME = IO::getDirectory(boost::assign::list_of(prefixDirectory)) + SingleStorage<Language>::DATA_FILE_NAME_BASE;
}