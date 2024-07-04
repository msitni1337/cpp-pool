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
    Fixed &operator=(const Fixed &rhs);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
};