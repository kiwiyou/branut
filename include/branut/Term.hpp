#ifndef _BRANUT_TERM_HPP_
#define _BRANUT_TERM_HPP_

#include <branut/Variable.hpp>

class Term
{
public:
    using coef_t = Variable::value_t;
    using coef_ref = coef_t&;
    using coef_cref = const coef_t&;
    
    using order_t = long long int;
    using order_ref = order_t&;
    using order_cref = const order_t&;

    using this_t = Term;
    using this_ref = this_t&;
    using this_cref = const this_t&;

public:
    Term(Variable& variable, order_cref order = 1);
    Term(coef_cref coefficient, Variable& variable, order_cref order = 1);
    Term(this_cref other) = default;

public:
    Variable::value_t value() const noexcept;
    coef_cref coefficient() const noexcept;
    order_cref order() const noexcept;

public:
    void set_coefficient(coef_cref coefficient) noexcept;
    void set_order(order_cref order) noexcept;

public:
    operator Variable::value_t() const noexcept;

    this_t operator*(coef_cref multiplier) const noexcept;
    this_t operator/(coef_cref divisor) const noexcept;
    this_t operator^(order_cref exponent) const noexcept;

    this_ref operator*=(coef_cref multiplier) noexcept;
    this_ref operator/=(coef_cref divisor) noexcept;
    this_ref operator^=(order_cref exponent) noexcept;

    bool operator==(this_cref other) const noexcept;
    bool operator!=(this_cref other) const noexcept;

    void operator=(Variable::value_cref result) const noexcept;

private:
    Variable& m_variable;
    coef_t m_coefficient;
    order_t m_order;
};

Term operator*(Variable& variable, Term::coef_cref coefficient) noexcept;
Term operator/(Variable& variable, Term::coef_cref inverse_coef) noexcept;
Term operator^(Variable& variable, Term::order_cref order) noexcept;

Term operator*(Term::coef_cref multiplicand, Term& term) noexcept;
Term operator/(Term::coef_cref diviend, Term& term) noexcept;

#endif