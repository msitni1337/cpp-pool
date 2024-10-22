#pragma once
#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
private:
    std::string _target;
public:
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &ppf);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &ppf);
    ~RobotomyRequestForm();
    void execute(Bureaucrat const &executor) const;
    AForm* clone();
};