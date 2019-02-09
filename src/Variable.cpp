#include <branut/Variable.hpp>

// Initializer

Variable::Variable()
    : m_value()
{}

Variable::Variable(value_cref value)
    : m_value(value)
{}

// Const member function

typename Variable::value_cref Variable::value() const noexcept
{
    return m_value;
}

// Non-const member function

void Variable::set_value(Variable::value_cref value) noexcept
{
    m_value = value;
}

// Operator

Variable::operator Variable::value_t() const noexcept
{
    return value();
}

typename Variable::value_cref Variable::operator=(Variable::value_cref value) noexcept
{
    set_value(value);
    return this->value();
}

typename Variable::value_cref Variable::operator+=(Variable::value_cref value) noexcept
{
    set_value(this->value() + value);
    return this->value();
}

typename Variable::value_cref Variable::operator-=(Variable::value_cref value) noexcept
{
    set_value(this->value() - value);
    return this->value();
}

typename Variable::value_cref Variable::operator*=(Variable::value_cref value) noexcept
{
    set_value(this->value() * value);
    return this->value();
}

typename Variable::value_cref Variable::operator/=(Variable::value_cref value) noexcept
{
    set_value(this->value() / value);
    return this->value();
}

bool Variable::operator==(Variable::this_cref other) const noexcept
{
    return m_value == other.m_value;
}

bool Variable::operator!=(Variable::this_cref other) const noexcept
{
    return !operator==(other);
}