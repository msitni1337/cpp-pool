#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat::GradeTooHighException";
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat::GradeTooLowException";
}
const char *Bureaucrat::EmptyNameException::what() const throw()
{
    return "Bureaucrat::EmptyNameException";
}
Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name)
{
    if (name.empty())
        throw EmptyNameException(); // exception class need to be implemented ..
    if (grade < 1)
        throw GradeTooHighException(); // exception class need to be implemented ..
    if (grade > 150)
        throw GradeTooLowException(); // exception class need to be implemented ..
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
        throw GradeTooHighException();
    _grade--;
}
void Bureaucrat::decrement_grade()
{
    if (_grade == 150)
        throw GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(AForm &f)
{
    try
    {
        f.beSigned(*this);
        std::cout << _name << " signed " << f.get_name() <<'\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << _name << " couldn't sign " << f.get_name() << " because "<< e.what() <<".\n";
    }
}
void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << _name << " executed " << form.get_name() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr <<  _name << " did not executed " << form.get_name() << " for this reason : " << e.what() << '\n';
    }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs)
{
    out << rhs.get_name() << ", bureaucrat grade " << rhs.get_grade() << "\n";
    return out;
}
