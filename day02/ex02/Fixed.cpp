#include "Fixed.hpp"

Fixed::Fixed()
{
    rawBits = 0;
    std::cout << "Default constructor called\n";
}
Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called\n";
    rawBits = fixed.getRawBits();
}
Fixed::Fixed(int const value)
{
    std::cout << "Int constructor called\n";
    rawBits = value * (1 << fraction);
}
Fixed::Fixed(float const value)
{
    std::cout << "Float constructor called\n";
    rawBits = (value + (value == 0 ? 0 : 1) * (value < 0 ? -0.005 : 0.005)) * (1 << fraction);
}
Fixed &Fixed::operator=(const Fixed &rhs)
{
    if (this == &rhs)
        return *this;
    std::cout << "Copy assignement operator called\n";
    rawBits = rhs.getRawBits();
    return *this;
}
Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
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