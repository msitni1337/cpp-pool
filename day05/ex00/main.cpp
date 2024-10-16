#include "Bureaucrat.hpp"
#include <iostream>

int main(int c, char**v)
{
    if (c == 2)
    {
        unsigned int grade;
        std::cout << "Enter desired grade: ";
        std::cin >> grade;        
        Bureaucrat a(v[1], grade);
    }
    else
        std::cout << "Usage\n" << v[0] << " [Name of The Bureaucrat]\n";
    return 0;
}