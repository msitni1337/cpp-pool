#include "Form.hpp"

Form::GradeTooHighException::GradeTooHighException()
{
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form::GradeTooHighException";
}

Form::GradeTooLowException::GradeTooLowException()
{
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form::GradeTooLowException";
}

Form::EmptyNameException::EmptyNameException()
{
}

const char *Form::EmptyNameException::what() const throw()
{
    return "Form::EmptyNameException";
}

Form::Form(const std::string name, const unsigned int to_sign, const unsigned int to_exec)
    : _name(name), gr_to_sign(to_sign), gr_to_exec(to_exec)
{
    if (name.empty())
        throw Form::EmptyNameException();
    if (to_sign < 1 || to_exec < 1)
        throw Form::GradeTooHighException();
    if (to_sign > 150 || to_exec > 150)
        throw Form::GradeTooLowException();
    _is_signed = false;
}
Form::Form(const Form &f)
    : _name(f._name), _is_signed(f._is_signed), gr_to_sign(f.gr_to_sign), gr_to_exec(f.gr_to_exec)
{
}
Form &Form::operator=(const Form &f)
{
    if (this != &f)
    {
        _is_signed = f._is_signed;
    }
    return *this;
}
std::string Form::get_name() const
{
    return _name;
}
bool Form::get_is_signed() const
{
    return _is_signed;
}
unsigned int Form::get_gr_to_sign() const
{
    return gr_to_sign;
}
unsigned int Form::get_gr_to_exec() const
{
    return gr_to_exec;
}
void Form::beSigned(const Bureaucrat &b)
{
    if (b.get_grade() > gr_to_sign)
        throw Form::GradeTooLowException();
    _is_signed = true;
}

std::ostream &operator<<(std::ostream &out, const Form &rhs)
{
    out << "Form name " << rhs.get_name();
    rhs.get_is_signed() ? out << ", is signed\n" : out << ", is not signed\n";
    out << "requires " << rhs.get_gr_to_sign() << " grade or higher to sign\n"
        << "requires " << rhs.get_gr_to_exec() << " grade or higher to execute\n";
    return out;
}