#ifndef _BRANUT_VARIABLE_HPP_
#define _BRANUT_VARIABLE_HPP_

class Variable
{
public:
    using value_t = double;
    using value_ref = value_t&;
    using value_cref = const value_t&;

    using this_t = Variable;
    using this_ref = this_t&;
    using this_cref = const this_t&;

public:
    Variable();
    Variable(value_cref value);

public:
    value_cref value() const noexcept;

public:
    void set_value(value_cref value) noexcept;

public:
    operator value_t() const noexcept;

    value_cref operator=(value_cref value) noexcept;
    value_cref operator+=(value_cref value) noexcept;
    value_cref operator-=(value_cref value) noexcept;
    value_cref operator*=(value_cref value) noexcept;
    value_cref operator/=(value_cref value) noexcept;

    bool operator==(this_cref other) const noexcept;
    bool operator!=(this_cref other) const noexcept;

private:
    value_t m_value;
};

#endif