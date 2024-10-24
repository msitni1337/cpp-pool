#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    if(target.empty())
        throw AForm::EmptyTargetException();
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ppf) : AForm(ppf), _target(ppf._target)
{}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ppf)
{
    if (this != &ppf)
    {
        (AForm&)*this = ppf;
        _target = ppf._target;
    }
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm()
{}
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n";
}
void PresidentialPardonForm::setTarget(std::string newTarget)
{
    if(newTarget.empty())
        throw AForm::EmptyTargetException();
    _target = newTarget;
}
