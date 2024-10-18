#include "Form.hpp"

Form::Form(const std::string name, const unsigned int to_sign, const unsigned int to_exec)
: _name(name), gr_to_sign(to_sign), gr_to_exec(to_exec)
{}
Form::Form(const Form &f)
: _name(f._name), gr_to_sign(f.gr_to_sign), gr_to_exec(f.gr_to_exec)
{}
Form &Form::operator=(const Form &f)
{
    if (this != &f)
    {
        _is_signed = f._is_signed;
    }
    return *this;
}
Form::~Form()
{}
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

std::ostream &operator<<(std::ostream &out, const Form &rhs)
{
    out << "Form name " << rhs.get_name()
    << rhs.get_is_signed() ? ", is signed\n": ", is not signed\n";
    out << "requires " << rhs.get_gr_to_sign() << " grade or higher to sign\n"
    << "requires " << rhs.get_gr_to_exec() << " grade or higher to execute\n"
    return out;
}