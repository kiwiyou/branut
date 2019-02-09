#include <branut/Term.hpp>
#include "test_define.hpp"
#include <limits>

int main()
{
    Variable x = -2;
    (x ^ 16) * 2 = 17;
    const double answer = -1.143111734174820412040700;
    ASSERT(std::abs(x - answer) < 2e-14)
}