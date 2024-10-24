#include "Intern.hpp"

const char * Intern::NoFormMatchNameException::what()  const throw()
{
    return "NoFormMatchNameException";
}

Intern::Intern() : _shForm("home"), _ppForm("home"), _rrForm("home")
{
    _forms[0] = &_shForm;
    _forms[1] = &_ppForm;
    _forms[2] = &_rrForm;
}
Intern::Intern(const Intern &i) : _shForm(i._shForm), _ppForm(i._ppForm), _rrForm(i._rrForm)
{
    _forms[0] = &_shForm;
    _forms[1] = &_ppForm;
    _forms[2] = &_rrForm;
}
Intern &Intern::operator=(const Intern &i)
{
    if (this != &i)
    {
        _shForm = i._shForm;
        _ppForm = i._ppForm;
        _rrForm = i._rrForm;
    }
    return *this;
}
Intern::~Intern()
{
}
AForm *Intern::makeForm(std::string form_name, std::string target_name)
{ 
    for (int i = 0; i < 3; i++)
    {
        if (_forms[i]->get_name() == form_name)
        {
            _forms[i]->setTarget(target_name);
            return _forms[i];
        }
    }
    throw Intern::NoFormMatchNameException();
}