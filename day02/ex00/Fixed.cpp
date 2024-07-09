#include "Fixed.hpp"

Fixed::Fixed()
{
    rawBits = 0;
    std::cout << "Default constructor called\n";
}
Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called\n";
    rawBits = fixed.rawBits;
}
Fixed &Fixed::operator=(const Fixed &rhs)
{
    std::cout << "Copy assignement operator called\n";
    if (this == &rhs)
        return *this;
    rawBits = rhs.rawBits;
    return *this;
}
Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return rawBits;
}
void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called\n";
    rawBits = raw;
}
