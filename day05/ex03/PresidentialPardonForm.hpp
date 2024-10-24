#pragma once
#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
private:
    std::string _target;
public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &ppf);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &ppf);
    ~PresidentialPardonForm();
    void execute(Bureaucrat const &executor) const;
    void setTarget(std::string newTarget);
};
