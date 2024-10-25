#include "ScalarConverter.hpp"

int main(int c, char **v)
{
    if (c == 2)
    {
        ScalarConverter::convert(v[1]);
        return 0;
    }
    std::cout << "Bad arguments. usage:\n";
    std::cout << v[0] << " [string to convert]\n";
    return 1;
}