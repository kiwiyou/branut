#include <branut/Term.hpp>
#include "test_define.hpp"

int main()
{
    Variable x = 1;
    Variable y = 2;
    auto x_squared = x ^ 2;
    ASSERT(x_squared.order() == 2 && x_squared.coefficient() == 1)
    auto y_squared = y ^ 2;
    ASSERT(x_squared != y_squared)
    x_squared *= 3;
    ASSERT(x_squared.coefficient() == 3);
    auto something = (x_squared * 2.0) / 3.0;
    ASSERT(something.coefficient() == 2);
    Term x_squared_2 = (x ^ 2) * 2;
    ASSERT(something == x_squared_2);
    x_squared_2 ^= 2;
    ASSERT(x_squared_2.coefficient() == 4 && x_squared_2.order() == 4)
}