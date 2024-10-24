#include "Intern.hpp"
#include <iostream>

int main(int c, char **v)
{
    if (c == 2)
    {
        std::string reply;
        std::string form_name;
        std::string form_target;
        unsigned int grade;

        std::cout << "Enter desired bureaucrat grade: ";
        std::cin >> grade;

        try
        {
            Bureaucrat bureaucrat(v[1], grade);
            Intern intern;
            AForm *form;

            std::cout << "ShrubberyCreationForm\n";
            std::cout << "PresidentialPardonForm\n";
            std::cout << "RobotomyRequestForm\n";
            std::cout << "Enter desired form name: ";
            std::cin >> form_name;
            std::cout << "Enter desired form target: ";
            std::cin >> form_target;
            form = intern.makeForm(form_name, form_target);
            std::cout << "Do you want to sign form " << form->get_name() << " [y/n]: ";
            std::cin >> reply;
            if (reply == "y")
            {
                std::cout << bureaucrat << "is going to sign\n"
                          << *form;
                bureaucrat.signForm(*form);
            }
            std::cout << "Do you want to execute form " << form->get_name() << " [y/n]: ";
            std::cin >> reply;
            if (reply == "y")
            {
                std::cout << bureaucrat << "is going to execute\n"
                          << *form;
                bureaucrat.executeForm(*form);
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "Main Catched an exception: " << e.what() << "\n";
        }
    }
    else
        std::cout << "Usage\n"
                  << v[0] << " [Name of The Bureaucrat]\n";
    return 0;
}