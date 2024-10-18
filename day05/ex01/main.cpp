#include "Bureaucrat.hpp"
#include <iostream>

int main(int c, char**v)
{
    if (c == 2)
    {
        unsigned int grade;
        std::cout << "Enter desired grade: ";
        std::cin >> grade;
        try{
            Bureaucrat a(v[1], grade);
        }
        catch (const std::exception &e)
        {
            printf("what: %s\n", e.what());
        }
    }
    else
        std::cout << "Usage\n" << v[0] << " [Name of The Bureaucrat]\n";
    return 0;
}