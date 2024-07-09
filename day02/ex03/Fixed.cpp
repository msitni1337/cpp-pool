#include "Fixed.hpp"

Fixed::Fixed()
{
    rawBits = 0;
    // std::cout << "Default constructor called\n";
}
Fixed::Fixed(const Fixed &fixed)
{
    // std::cout << "Copy constructor called\n";
    rawBits = fixed.getRawBits();
}
Fixed::Fixed(int const value)
{
    // std::cout << "Int constructor called\n";
    rawBits = value * (1 << fraction);
}
Fixed::Fixed(float const value)
{
    // std::cout << "Float constructor called\n";
    rawBits = ( value + (value == 0 ? 0 : 1) * (value < 0 ? -0.0005 : 0.0005) ) * (1 << fraction);
}
Fixed &Fixed::operator=(const Fixed &rhs)
{
    // std::cout << "Copy assignement operator called\n";
    if (this == &rhs)
        return *this;
    rawBits = rhs.getRawBits();
    return *this;
}
Fixed::~Fixed()
{
    // std::cout << "Destructor called\n";
}
int Fixed::getRawBits(void) const
{
    return rawBits;
}
void Fixed::setRawBits(int const raw)
{
    rawBits = raw;
}
float Fixed::toFloat(void) const
{
    return ((float)rawBits / (1 << this->fraction));
}
int Fixed::toInt(void) const
{
    return ((float)rawBits / (1 << this->fraction));
}

std::ostream &operator<<(std::ostream &out, const Fixed &rhs)
{
    out << rhs.toFloat();
    return out;
}
bool Fixed::operator>(const Fixed &rhs) const
{
    return this != &rhs && this->toFloat() > rhs.toFloat();
}
bool Fixed::operator<(const Fixed &rhs) const
{
    return this != &rhs && this->toFloat() < rhs.toFloat();
}
bool Fixed::operator>=(const Fixed &rhs) const
{
    return this == &rhs || this->toFloat() >= rhs.toFloat();
}
bool Fixed::operator<=(const Fixed &rhs) const
{
    return this == &rhs || this->toFloat() <= rhs.toFloat();
}
bool Fixed::operator==(const Fixed &rhs) const
{
    return this == &rhs || this->toFloat() == rhs.toFloat();
}
bool Fixed::operator!=(const Fixed &rhs) const
{
    return this != &rhs && this->toFloat() != rhs.toFloat();
}
Fixed Fixed::operator+(const Fixed &rhs) const
{
    Fixed res;
    res.setRawBits((this->rawBits + rhs.rawBits));
    return res;
}
Fixed Fixed::operator-(const Fixed &rhs) const
{
    Fixed res;
    res.setRawBits((this->rawBits - rhs.rawBits));
    return res;
}
Fixed Fixed::operator*(const Fixed &rhs) const
{
    Fixed res;
    __int64_t a, b;
    a = rawBits;
    b = rhs.rawBits;
    res.setRawBits((a * b) >> fraction);
    return res;
}
Fixed Fixed::operator/(const Fixed &rhs) const
{
    Fixed res;
    __int64_t a, b;
    a = rawBits << fraction;
    b = rhs.rawBits;
    res.setRawBits((a / b));
    return res;
}
float Fixed::operator++()
{
    rawBits++;
    return toFloat();
}
float Fixed::operator--()
{
    rawBits--;
    return toFloat();
}
float Fixed::operator++(int)
{
    float value = toFloat();
    rawBits++;
    return value;
}
float Fixed::operator--(int)
{
    float value = toFloat();
    rawBits--;
    return value;
}
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    float af, bf;
    af = a.toFloat();
    bf = b.toFloat();
    if (af <= bf)
        return a;
    return b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    float af, bf;
    af = a.toFloat();
    bf = b.toFloat();
    if (af <= bf)
        return a;
    return b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    float af, bf;
    af = a.toFloat();
    bf = b.toFloat();
    if (af >= bf)
        return a;
    return b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    float af, bf;
    af = a.toFloat();
    bf = b.toFloat();
    if (af >= bf)
        return a;
    return b;
}
