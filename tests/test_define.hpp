#include <stdexcept>
#include <string>

#define ASSERT(x) if (!(x)) {throw std::runtime_error(std::string(__FILE__) + ":" + std::to_string(__LINE__) + " in " + std::string(__PRETTY_FUNCTION__));}