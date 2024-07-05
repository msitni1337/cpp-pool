#pragma once
#include <iostream>

class Fixed
{
private:
    static const int fraction = 8;
    int rawBits;

public:
    Fixed();
    Fixed(const Fixed &fixed);
    Fixed(int const value);
    Fixed(float const value);
    Fixed &operator=(const Fixed &rhs);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &rhs);