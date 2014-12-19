// ------------------------------------------
// ------ PARSING TOOLS AND ERROR LOGS ------
// ------------------------------------------
#include "io.hpp"

#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>

#pragma warning(push, 0)  
#include <sys/types.h>
#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#pragma warning(pop)

#if defined(__linux__)
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#else 
#include <windows.h>
#include <tchar.h>
#endif

#include "exceptions.hpp"
#include "log.hpp"

#include <stdio.h>  /* defines FILENAME_MAX */

void IO::removeFile(const std::string& fileName) {
	try {
		std::remove(fileName.c_str());
	} catch (std::exception &e) {
		toErrorLog("Error removing file " + fileName + "(" + e.what() + ").");
    }
}

std::string IO::getDirectory(const std::list<std::string>& directoryList) {
	std::ostringstream os;
	os.str("");

	for(std::list<std::string>::const_iterator i = directoryList.begin(); i != directoryList.end(); i++) {
#if defined(__linux__)
		os << *i << "/";
#elif defined(WIN32)
		os << *i << "\\";
#endif
	}
	return os.str();
}

bool IO::fileExists(const std::string& fileName) {
	return boost::filesystem::exists(fileName);
}

void IO::makeBackup(const std::string& fileName) {
	if(boost::filesystem::exists(fileName)) {
		std::string backup_filename = fileName + ".old";
		boost::filesystem::rename(fileName, backup_filename);
	}
}

std::vector<std::string> IO::findFiles(const std::string& directory) {
	std::vector<std::string> fileList;

#if defined(__linux__)
	DIR *dir;
	struct dirent *entry;
	if ((dir = opendir(directory.c_str())) == NULL) {
		std::ostringstream os;
		os << "ERROR (find_files()): Cannot open directory " << directory << "(" << errno << ")";
		throw FileException(os.str());
	}
	else 
	{
		while ((entry = readdir(dir)) != NULL) {
			fileList.push_back(directory + entry->d_name);
		}
		closedir(dir);
	}
#elif defined(WIN32)
	WIN32_FIND_DATA dir;
	HANDLE fhandle;
	if ((fhandle = FindFirstFile(((directory + "*.*").c_str()), &dir)) != INVALID_HANDLE_VALUE)
	{
		do {
			fileList.push_back(directory + dir.cFileName);
		} while(FindNextFile(fhandle, &dir));
	} else {
		throw FileException("ERROR (find_files()): Cannot load " + directory + ".");
	}
	FindClose(fhandle);
#endif

	return fileList;	
}

void IO::checkStreamIsOpen(const std::ifstream& stream, const std::string function_name, const std::string& file_name)
{
	if(!stream.is_open())
	{
		throw FileException("ERROR (" + function_name + "()): File " + file_name + " not found or cannot be opened.");
	}
}

void IO::checkStreamIsOpen(std::ofstream& stream, const std::string function_name, const std::string& file_name)
{
	if(!stream.is_open())
	{
		throw FileException("ERROR (" + function_name + "()): Could not create file " + file_name + " (write protection? disk space?).");
	}
}

void IO::checkStreamForFailure(const std::ifstream& stream, const std::string function_name, const std::string& file_name)
{
	if(stream.bad()) {
		throw FileException("ERROR (" + function_name + "()): Fatal error while accessing file " + file_name + " => canceling request.");
	}
	if(stream.fail()) {
		//		stream.clear(stream.rdstate() & ~std::ios::failbit);
		throw FileException("WARNING (" + function_name + "()): Error while reading from file " + file_name + " => retrying.");
	}
}

void IO::checkStreamForFailure(std::ofstream& stream, const std::string function_name, const std::string& file_name)
{
	if(stream.bad())
	{
		throw FileException("ERROR (" + function_name + "()): Fatal error while accessing file " + file_name + " => canceling request.");
	}
	if(stream.fail())
	{
		//		stream.clear(stream.rdstate() & ~std::ios::failbit);
		throw FileException("WARNING (" + function_name + "()): Error while writing to file " + file_name + " => retrying.");
	}
}

const char* IO::loadFileToChar(const std::string& fileName) {
	FILE * fp = fopen(fileName.c_str(),"rt");
	if (fp == NULL) {
		throw FileException("ERROR (load_file_to_char()): File " + fileName + " not found or cannot be opened.");
	}
	fseek(fp, 0, SEEK_END);
	long size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	char *pData = new char[size + 1];
	fread(pData, sizeof(char), size, fp);
	fclose(fp);
	return pData;
}


// -----------------------------------------------
// ------  END PARSING TOOLS AND ERROR LOGS ------
// -----------------------------------------------




boost::filesystem::path IO::initialPath = boost::filesystem::initial_path();
