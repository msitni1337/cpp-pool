#pragma once
#include "AForm.hpp"
#include <string>

#define TREE_CSTR \
"  *\n"\
" ***\n"\
"*****\n"\
"  |\n"
class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;
public:
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &ppf);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &ppf);
    ~ShrubberyCreationForm();
    void execute(Bureaucrat const &executor) const;
    AForm* clone();
};