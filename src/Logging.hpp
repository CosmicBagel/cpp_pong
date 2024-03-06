#include <raylib.h>

#include <format>
#include <string>

// literally made this because using std::format with raylib TraceLog is annoying

template <typename... Args>
inline void DebugLog(std::format_string<Args...> fmt, Args&&... args) {
    std::string formatted = std::format(fmt, args...);
    TraceLog(LOG_DEBUG, formatted.c_str());
}

template <typename... Args>
inline void MyTraceLog(int LogLevel, std::format_string<Args...> fmt, Args&&... args) {
    std::string formatted = std::format(fmt, args...);
    TraceLog(LogLevel, formatted.c_str());
}
