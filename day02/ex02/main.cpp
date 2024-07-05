#include "Fixed.hpp"
#include <iomanip>

int main(void)
{
    {
        Fixed a;
        Fixed const b(Fixed(16.0f) * Fixed(2));
        std::cout << std::left;
        std::cout << std::setw(15) << "a = " << a << std::endl;
        std::cout << std::setw(15) << "b = " << b << std::endl;
        std::cout << std::setw(15) << "++a = " << ++a << std::endl;
        std::cout << std::setw(15) << "a = " << a << std::endl;
        std::cout << std::setw(15) << "a++ = " << a++ << std::endl;
        std::cout << std::setw(15) << "a = " << a << std::endl;
        std::cout << std::setw(15) << "b = " << b << std::endl;
        std::cout << std::setw(15) << "max(a, b) = " << Fixed::max(a, b) << std::endl;
        std::cout << std::setw(15) << "min(a, b) = " << Fixed::min(a, b) << std::endl;
        a = b;
        std::cout << std::setw(15) << "a = b;" << std::endl;
        std::cout << std::setw(15) << "a = " << a << std::endl;
        std::cout << std::setw(15) << "b = " << b << std::endl;
    }
    std::cout << "======================================" << std::endl;
    {
        Fixed c(5.0f);
        Fixed d(2.0f);
        std::cout << std::setw(15) << "c = " << c << std::endl;
        std::cout << std::setw(15) << "d = " << d << std::endl;
        std::cout << std::setw(15) << "c + d = " << c + d << std::endl;
        std::cout << std::setw(15) << "c - d = " << c - d << std::endl;
        std::cout << std::setw(15) << "c * d = " << c * d << std::endl;
        std::cout << std::setw(15) << "c / d = " << c / d << std::endl;
        std::cout << std::setw(15) << "c > d = " << (c > d) << std::endl;
        std::cout << std::setw(15) << "c >= d = " << (c >= d) << std::endl;
        std::cout << std::setw(15) << "c < d = " << (c < d) << std::endl;
        std::cout << std::setw(15) << "c <= d = " << (c <= d) << std::endl;
        std::cout << std::setw(15) << "c == d = " << (c == d) << std::endl;
        std::cout << std::setw(15) << "c != d = " << (c != d) << std::endl;
        c = d;
        std::cout << std::setw(15) << "c = d; " << std::endl;
        std::cout << std::setw(15) << "c == d = " << (c == d) << std::endl;
        std::cout << std::setw(15) << "c != d = " << (c != d) << std::endl;
        std::cout << std::setw(15) << "d == d = " << (d == d) << std::endl;
        std::cout << std::setw(15) << "d != d = " << (d != d) << std::endl;
    }

    return 0;
}