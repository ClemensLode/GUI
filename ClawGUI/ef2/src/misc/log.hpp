#ifndef _MISC_LOG_HPP
#define _MISC_LOG_HPP

#include <string>

extern void toInitLog(const std::string msg);
extern void toDebugLog(const std::string msg);
extern void toInfoLog(const std::string msg);
extern void toWarnLog(const std::string msg);
extern void toErrorLog(const std::string msg);

#endif // _MISC_LOG_HPP