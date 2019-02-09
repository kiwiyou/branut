#include <branut/Term.hpp>
#include "test_define.hpp"
#include <limits>

int main()
{
    Variable x;
    ((x ^ 2) * 2) = 8;
    ASSERT(std::abs(x.value()) - 2.0 < std::numeric_limits<Variable::value_t>::epsilon())
}