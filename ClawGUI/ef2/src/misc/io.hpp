#ifndef _MISC_IO_HPP
#define _MISC_IO_HPP

#include <list>
#include <iostream>
#include <vector>
#include <string>

#pragma warning(push, 0) 
#include <boost/filesystem/path.hpp>
#include <boost/assign/list_of.hpp>
#pragma warning(pop)

class IO
{
public:
	static void removeFile(const std::string& fileName);
	static void makeBackup(const std::string& fileName);
	static std::string getDirectory(const std::list<std::string>& directoryList);
	static std::vector<std::string> findFiles(const std::string& directory);
	static void checkStreamIsOpen(const std::ifstream& stream, const std::string function_name, const std::string& file_name);
	static void checkStreamIsOpen(std::ofstream& stream, const std::string function_name, const std::string& file_name);
	static void checkStreamForFailure(const std::ifstream& stream, const std::string function_name, const std::string& file_name);
	static void checkStreamForFailure(std::ofstream& stream, const std::string function_name, const std::string& file_name);
	static const char* loadFileToChar(const std::string& fileName);	
	static bool fileExists(const std::string& fileName);

private:
	IO();
	~IO();

	static boost::filesystem::path initialPath;
	
};

#endif // _MISC_IO_HPP

