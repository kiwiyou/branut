template <class ActualType>
class Variable;

template <class ActualType>
Variable<ActualType>::Variable()
    : m_value()
{}

template <class ActualType>
Variable<ActualType>::Variable(Variable<ActualType>::value_cref value)
    : m_value(value)
{}

template <class ActualType>
typename Variable<ActualType>::value_cref Variable<ActualType>::value() const noexcept
{
    return m_value;
}

template <class ActualType>
void Variable<ActualType>::set_value(Variable<ActualType>::value_cref value) noexcept
{
    m_value = value;
}

template <class ActualType>
Variable<ActualType>::operator Variable<ActualType>::value_t() const noexcept
{
    return m_value;
}

template <class ActualType>
typename Variable<ActualType>::value_cref Variable<ActualType>::operator=(Variable<ActualType>::value_cref value) noexcept
{
    return m_value = value;
}
template <class ActualType>
typename Variable<ActualType>::value_cref Variable<ActualType>::operator+=(Variable<ActualType>::value_cref value) noexcept
{
    return m_value += value;
}
template <class ActualType>
typename Variable<ActualType>::value_cref Variable<ActualType>::operator-=(Variable<ActualType>::value_cref value) noexcept
{
    return m_value -= value;
}
template <class ActualType>
typename Variable<ActualType>::value_cref Variable<ActualType>::operator*=(Variable<ActualType>::value_cref value) noexcept
{
    return m_value *= value;
}
template <class ActualType>
typename Variable<ActualType>::value_cref Variable<ActualType>::operator/=(Variable<ActualType>::value_cref value) noexcept
{
    return m_value /= value;
}

template <class ActualType>
bool Variable<ActualType>::operator==(Variable<ActualType>::this_cref other) const noexcept
{
    return m_value == other.m_value;
}
template <class ActualType>
bool Variable<ActualType>::operator!=(Variable<ActualType>::this_cref other) const noexcept
{
    return m_value != other.m_value;
}