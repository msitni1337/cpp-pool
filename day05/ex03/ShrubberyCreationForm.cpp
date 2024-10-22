#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    if (target.empty())
        throw AForm::EmptyTargetException();
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ppf) : AForm(ppf)
{
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ppf)
{
    (AForm &)*this = ppf;
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    std::ofstream tree_file(_target + "_shrubbery");
    tree_file << TREE_CSTR;
    tree_file.close();
}