#pragma once
#include <string>
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
private:
    ShrubberyCreationForm _shForm();
    PresidentialPardonForm _ppForm();
    RobotomyRequestForm _rrForm();
    AForm *_forms[3];

public:
    Intern();
    Intern(const Intern &i);
    Intern &operator=(const Intern &i);
    ~Intern();
    AForm *makeForm(std::string form_name, std::string target_name);
};
