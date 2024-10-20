#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(int c, char**v)
{
    if (c == 3)
    {
        unsigned int grade;
        unsigned int f_grade_sign;
        unsigned int f_grade_exec;
        
        std::cout << "Enter desired bureaucrat grade: ";
        std::cin >> grade;
        std::cout << "Enter desired form signing grade: ";
        std::cin >> f_grade_sign;
        std::cout << "Enter desired form execution grade: ";
        std::cin >> f_grade_exec;

        try
        {
            Bureaucrat bureaucrat(v[1], grade);
            Form form(v[2], f_grade_sign, f_grade_exec);

            std::cout << bureaucrat << "is going to sign\n" << form;

            bureaucrat.signForm(form);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Main Catched an exception: " << e.what() << "\n";
        }
    }
    else
        std::cout << "Usage\n" << v[0] << " [Name of The Bureaucrat] [Name of Form]\n";
    return 0;
}