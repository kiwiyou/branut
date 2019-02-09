#include <branut/Term.hpp>

#include <cmath>
#include <limits>
#include <stdexcept>

// Initializer

Term::Term(Variable& variable, Term::order_cref order)
    : m_variable(variable), m_order(order), m_coefficient(1)
{}

Term::Term(Term::coef_cref coefficient, Variable& variable, Term::order_cref order)
    : m_variable(variable), m_order(order), m_coefficient(coefficient)
{}

// Const member function

typename Variable::value_t Term::value() const noexcept
{
    return m_coefficient * std::pow(m_variable.value(), m_order);
}

typename Term::coef_cref Term::coefficient() const noexcept
{
    return m_coefficient;
}

typename Term::order_cref Term::order() const noexcept
{
    return m_order;
}

// Non-const member function

void Term::set_coefficient(Term::coef_cref coefficient) noexcept
{
    m_coefficient = coefficient;
}

void Term::set_order(Term::order_cref order) noexcept
{
    m_order = order;
}

// Operator

Term::operator Variable::value_t() const noexcept
{
    return value();
}

typename Term::this_t Term::operator*(Term::coef_cref multiplier) const noexcept
{
    Term result = *this;
    return result *= multiplier;
}

typename Term::this_t Term::operator/(Term::coef_cref divisor) const noexcept
{
    Term result = *this;
    return result /= divisor;
}

typename Term::this_t Term::operator^(Term::order_cref exponent) const noexcept
{
    Term result = *this;
    return result ^= exponent;
}

typename Term::this_ref Term::operator*=(Term::coef_cref multiplier) noexcept
{
    set_coefficient(coefficient() * multiplier);
    return *this;
}

typename Term::this_ref Term::operator/=(Term::coef_cref divisor) noexcept
{
    set_coefficient(coefficient() / divisor);
    return *this;
}

typename Term::this_ref Term::operator^=(Term::order_cref exponent) noexcept
{
    set_order(order() * exponent);
    set_coefficient(std::pow(coefficient(), exponent));
    return *this;
}

bool Term::operator==(Term::this_cref other) const noexcept
{
    return (m_coefficient == other.m_coefficient)
        && (m_order == other.m_order)
        && (&m_variable == &other.m_variable);
}

bool Term::operator!=(Term::this_cref other) const noexcept
{
    return !operator==(other);
}

void Term::operator=(Variable::value_cref value) const noexcept
{
    Term derivative(coefficient() * order(), m_variable, order() - 1);
    constexpr auto epsilon = 2e-14;
    Variable::value_t previous;
    if (derivative.value() == 0)
    {
        m_variable = std::pow(value / coefficient(), 1.0 / order());
    }
    else
    {
        do
        {
            previous = m_variable;
            m_variable -= (this->value() - value) / derivative.value();
        } while (std::abs(previous - m_variable) >= epsilon);
    }
}

// Other

Term operator*(Variable& variable, Term::coef_cref coefficient) noexcept
{
    return Term(coefficient, variable);
}

Term operator/(Variable& variable, Term::coef_cref inverse_coef) noexcept
{
    return Term(1 / inverse_coef, variable);
}

Term operator^(Variable& variable, Term::order_cref order) noexcept
{
    return Term(variable, order);
}

Term operator*(Term::coef_cref multiplicand, Term& term) noexcept
{
    return term * multiplicand;
}

Term operator/(Term::coef_cref diviend, Term& term) noexcept
{
    Term result = term;
    result.set_coefficient(diviend / result.coefficient());
    result.set_order(-result.order());
    return result;
}