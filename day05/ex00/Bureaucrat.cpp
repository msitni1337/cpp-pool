#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException()
{

}
Bureaucrat::GradeTooHighException::~GradeTooHighException() _NOEXCEPT
{

}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{

}
Bureaucrat::GradeTooLowException::~GradeTooLowException() _NOEXCEPT
{
    
}

Bureaucrat::EmptyNameException::EmptyNameException()
{

}
Bureaucrat::EmptyNameException::~EmptyNameException() _NOEXCEPT
{
    
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name)
{
    if (name.empty())
        throw new EmptyNameException(); // exception class need to be implemented ..
    if (grade < 1)
        throw new GradeTooHighException(); // exception class need to be implemented ..
    if (grade > 150)
        throw new GradeTooLowException(); // exception class need to be implemented ..
    _grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat &b)
{
    *this = b;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b)
{
    if (&b != this)
        _grade = b._grade;
    return *this;
}
Bureaucrat::~Bureaucrat()
{
}
std::string Bureaucrat::get_name() const
{
    return _name;
}
unsigned int Bureaucrat::get_grade() const
{
    return _grade;
}
void Bureaucrat::increment_grade()
{
    if (_grade == 1)
        throw new GradeTooHighException();
    _grade--;
}
void Bureaucrat::decrement_grade()
{
    if (_grade == 150)
        throw new GradeTooLowException();
    _grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs)
{
    out << rhs.get_name() << ", bureaucrat grade " << rhs.get_grade() << "\n";
    return out;
}
