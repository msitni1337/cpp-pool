#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name)
{
    if (name.empty())
        throw; // exception class need to be implemented ..
    if (grade < 1 || grade > 150)
        throw; // exception class need to be implemented ..
    _grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat &b)
{
    *this = b;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b)
{
    if (&b == this)
        return;
    _grade = b._grade;
}
Bureaucrat::~Bureaucrat()
{
}
std::string Bureaucrat::get_name()
{
    return _name;
}
unsigned int Bureaucrat::get_grade()
{
    return _grade;
}
void Bureaucrat::increment_grade()
{
    if (_grade == 1)
        throw; // exception class need to be implemented ..
    _grade--;
}
void Bureaucrat::decrement_grade()
{
    if (_grade == 150)
        throw; // exception class need to be implemented ..
    _grade++;
}