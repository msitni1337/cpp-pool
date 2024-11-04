#include "whatever.tpp"
#include <iostream>
#include <string>

int main(int c, char **v)
{
    if (c == 3)
    {
        std::string arg1 = v[1];
        std::string arg2 = v[2];
        std::string result;

        std::cout << "input:\n";
        std::cout << "arg1 = " << arg1 << "\narg2 = " << arg2 << '\n';
        std::cout << "Swapping input..\n";
        ::swap(&arg1, &arg2);
        std::cout << "arg1 = " << arg1 << "\narg2 = " << arg2 << '\n';
        result = ::max(arg1, arg2);
        std::cout << "max = " << result << '\n';
        result = ::min(arg1, arg2);
        std::cout << "min = " << result << '\n';

        return 0;
    }
    std::cout << "Bad arguments.\nusage: " << v[0] << " [first string] [second string]\n";
    return 1;
}
