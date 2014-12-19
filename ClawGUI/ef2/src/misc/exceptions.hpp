#ifndef _MISC_EXCEPTIONS_HPP
#define _MISC_EXCEPTIONS_HPP

#include <stdexcept>
#include "log.hpp"

class SDLException : public std::runtime_error {
public:
	SDLException(const std::string& msg = "") : std::runtime_error(msg) {
		toErrorLog(msg);
	}
};

class FileException : public std::runtime_error {
public:
	FileException(const std::string& msg = "") : std::runtime_error(msg) {
		toErrorLog(msg);
	}
};

class GUIException : public std::runtime_error {
public:
	GUIException(const std::string& msg = "") : std::runtime_error(msg) {
		toErrorLog(msg);
	}
};

#endif // _MISC_EXCEPTIONS_HPP