#include <iostream>
#include <string>
#include <iomanip>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << std::setw(31) << std::left << "The address of string: " << &string << '\n';
    std::cout << "The address held by stringPTR: " << stringPTR << '\n';
    std::cout << "The address held by stringREF: " << &stringREF << "\n\n";

    std::cout << std::setw(29) << std::left << "The value of string: " << string << '\n';
    std::cout << "The value held by stringPTR: " << *stringPTR << '\n';
    std::cout << "The value held by stringREF: " << stringREF << '\n';

    return 0;
}