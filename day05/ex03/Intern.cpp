#include "Intern.hpp"

Intern::Intern()
{
    ShrubberyCreationForm f("");
    _forms[0] = &f;
    _forms[1] = &f;
    _forms[2] = &f;
}
Intern::Intern(const Intern &i)
{
}
Intern &Intern::operator=(const Intern &i)
{
    return *this;
}
Intern::~Intern()
{
}
AForm *Intern::makeForm(std::string form_name, std::string target_name)
{
    for (int i = 0; i < 3; i++)
    {
        
    }
}