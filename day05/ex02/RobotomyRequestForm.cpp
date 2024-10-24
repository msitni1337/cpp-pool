#include "RobotomyRequestForm.hpp"
#include <random>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    if(target.empty())
        throw AForm::EmptyTargetException();
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rrf) : AForm(rrf), _target(rrf._target)
{}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rrf)
{
    if (this != &rrf)
    {
        (AForm&)*this = rrf;
        _target = rrf._target;
    }
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
