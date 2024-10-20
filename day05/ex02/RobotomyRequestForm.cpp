#include "RobotomyRequestForm.hpp"
#include <random>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    if(target.empty())
        throw AForm::EmptyTargetException();
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ppf) : AForm(ppf)
{}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &ppf)
{
    (AForm&)*this = ppf;
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm()
{}
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    std::cout << "Making some drilling noise.\n";
    std::cout << "..\n";
    srand(time(0));
    int random = rand() % 2;
    if (random)
        std::cout << _target << " has been robotomized successfully.\n";
    else
        std::cout << "the robotomy for " << _target << " has failed.\n";
}
