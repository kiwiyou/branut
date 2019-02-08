#include <branut/Variable.hpp>
#include "test_define.hpp"

int main()
{
    Variable<double> double_var{.1};
    ASSERT(double_var.value() == .1)
    double_var = 1.0;
    ASSERT(double_var.value() == 1.0)
    double_var += 1;
    ASSERT(double_var.value() == 2.0)
    double_var -= 2;
    ASSERT(double_var.value() == 0.0)
    double_var.set_value(50);
    ASSERT(double_var.value() == 50.0)
    double_var *= 2;
    ASSERT(double_var.value() == 100)
    double_var /= 5;
    ASSERT(double_var.value() == 20)
}