#include "AForm.hpp"

const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm::GradeTooHighException";
}
const char *AForm::GradeTooLowException::what() const throw()
{
    return "AForm::GradeTooLowException";
}
const char *AForm::EmptyNameException::what() const throw()
{
    return "AForm::EmptyNameException";
}
const char *AForm::EmptyTargetException::what() const throw()
{
    return "AForm::EmptyTargetException";
}
const char *AForm::FormNotSignedException::what() const throw()
{
    return "AForm::FormNotSignedException";
}

AForm::AForm(const std::string name, const unsigned int to_sign, const unsigned int to_exec)
    : _name(name),_is_signed(false), gr_to_sign(to_sign), gr_to_exec(to_exec)
{
    if (name.empty())
        throw AForm::EmptyNameException();
    if (to_sign < 1 || to_exec < 1)
        throw AForm::GradeTooHighException();
    if (to_sign > 150 || to_exec > 150)
        throw AForm::GradeTooLowException();
}
AForm::AForm(const AForm &f)
    : _name(f._name), _is_signed(f._is_signed), gr_to_sign(f.gr_to_sign), gr_to_exec(f.gr_to_exec)
{
}
AForm &AForm::operator=(const AForm &f)
{
    if (this != &f)
    {
        _is_signed = f._is_signed;
    }
    return *this;
}
AForm::~AForm()
{}
std::string AForm::get_name() const
{
    return _name;
}
bool AForm::get_is_signed() const
{
    return _is_signed;
}
unsigned int AForm::get_gr_to_sign() const
{
    return gr_to_sign;
}
unsigned int AForm::get_gr_to_exec() const
{
    return gr_to_exec;
}
void AForm::beSigned(const Bureaucrat &b)
{
    if (b.get_grade() > gr_to_sign)
        throw AForm::GradeTooLowException();
    _is_signed = true;
}
void AForm::execute(Bureaucrat const & executor) const
{
    if (executor.get_grade() > gr_to_exec)
        throw AForm::GradeTooLowException();
    if (_is_signed == false)
        throw AForm::FormNotSignedException();
}

std::ostream &operator<<(std::ostream &out, const AForm &rhs)
{
    out << "Form name " << rhs.get_name();
    rhs.get_is_signed() ? out << ", is signed\n" : out << ", is not signed\n";
    out << "requires " << rhs.get_gr_to_sign() << " grade or higher to sign\n"
        << "requires " << rhs.get_gr_to_exec() << " grade or higher to execute\n";
    return out;
}