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
    friend std::ostream &operator<<(std::ostream &out, const Fixed &rhs);
    bool operator>(const Fixed &rhs) const;
    bool operator<(const Fixed &rhs) const;
    bool operator>=(const Fixed &rhs) const;
    bool operator<=(const Fixed &rhs) const;
    bool operator==(const Fixed &rhs) const;
    bool operator!=(const Fixed &rhs) const;
    Fixed operator+(const Fixed &rhs) const;
    Fixed operator-(const Fixed &rhs) const;
    Fixed operator*(const Fixed &rhs) const;
    Fixed operator/(const Fixed &rhs) const;
    float operator++();
    float operator--();
    float operator++(int);
    float operator--(int);
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};