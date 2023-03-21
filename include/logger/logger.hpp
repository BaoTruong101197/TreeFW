#include <vector>

namespace logger {
template<typename T>
void log(const char* const file, const char* const function, const int line, const T& log)
{
    std::cout << file << " | " << function << " | " << line << " | " << log << "\n";  
}
}

#define LOG_LINE(FILE, FUNC, LINE, LOG) logger::log(FILE, FUNC, LINE,  LOG)
#define LOG(LOG) LOG_LINE(__FILE__, __FUNCTION__, __LINE__,  LOG)