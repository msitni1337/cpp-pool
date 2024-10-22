#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

#include <iostream>

int main(int c, char **v)
{
    if (c == 3)
    {
        std::string reply;
        unsigned int grade;

        std::cout << "Enter desired bureaucrat grade: ";
        std::cin >> grade;

        try
        {
            Bureaucrat bureaucrat(v[1], grade);
            ShrubberyCreationForm ShForm = ShrubberyCreationForm(v[2]);
            PresidentialPardonForm ppForm = PresidentialPardonForm(v[2]);
            RobotomyRequestForm rrForm = RobotomyRequestForm(v[2]);
            AForm *form;
        choose_form:
            std::cout << "1: ShrubberyCreationForm\n";
            std::cout << "2: PresidentialPardonForm\n";
            std::cout << "3: RobotomyRequestForm\n";
            std::cout << "Enter desired bureaucrat form: ";
            std::cin >> grade;

            switch (grade)
            {
            case 1:
                form = &ShForm;
                break;
            case 2:
                form = &ppForm;
                break;
            case 3:
                form = &rrForm;
                break;
            default:
                std::cout << "wrong answer.\n";
                goto choose_form;
                break;
            }

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
                  << v[0] << " [Name of The Bureaucrat] [Name of Target]\n";
    return 0;
}