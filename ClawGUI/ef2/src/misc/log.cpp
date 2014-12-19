#include "log.hpp"

#include <iostream>

void toInitLog(const std::string msg) {
	std::cout << "[INIT] " << msg << "\n";
}

void toErrorLog(const std::string msg) {
	std::cout << "[ERROR] " << msg << "\n";
}

void toDebugLog(const std::string msg)
{
	std::cout << "[DEBUG] " << msg << "\n";
}

void toWarnLog(const std::string msg)
{
	std::cout << "[WARN] " << msg << "\n";
}

void toInfoLog(const std::string msg)
{
	std::cout << "[INFO] " << msg << "\n";
}
