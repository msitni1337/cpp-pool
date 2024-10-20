#include "ShrubberyCreationForm.hpp"

#include <iostream>

int main(int c, char**v)
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

            AForm& form = ShForm;

            std::cout << "Do you want to sign form " << form.get_name()  << " [y/n]: ";
            std::cin >> reply;
            if (reply == "y")
            {
                std::cout << bureaucrat << "is going to sign\n" << form;
                bureaucrat.signForm(form);
            }
            std::cout << "Do you want to execute form " << form.get_name()  << " [y/n]: ";
            std::cin >> reply;
            if (reply == "y")
            {
                std::cout << bureaucrat << "is going to execute\n" << form;
                bureaucrat.executeForm(form);
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "Main Catched an exception: " << e.what() << "\n";
        }
    }
    else
        std::cout << "Usage\n" << v[0] << " [Name of The Bureaucrat] [Name of Target]\n";
    return 0;
}