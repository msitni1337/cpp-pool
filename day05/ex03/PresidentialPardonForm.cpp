#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    if(target.empty())
        throw AForm::EmptyTargetException();
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ppf) : AForm(ppf)
{}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ppf)
{
    (AForm&)*this = ppf;
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm()
{}
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n";
}
