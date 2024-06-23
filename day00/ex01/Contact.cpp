#include "Contact.hpp"

Contact::Contact()
{}

Contact::Contact(const Contact &c)
{
    f_name = c.f_name;
    l_name = c.l_name;
    n_name = c.n_name;
    phone = c.phone;
    secret = c.secret;
}

Contact &Contact::operator=(const Contact &c)
{
    if (this != &c)
    {
        f_name = c.f_name;
        l_name = c.l_name;
        n_name = c.n_name;
        phone = c.phone;
        secret = c.secret;
    }

    return *this;
}

Contact::~Contact() {}

std::string Contact::get_f_name() const
{
    return f_name;
}
void Contact::set_f_name(std::string s)
{
    f_name = s;
}
std::string Contact::get_l_name() const
{
    return l_name;
}
void Contact::set_l_name(std::string s)
{
    l_name = s;
}
std::string Contact::get_n_name() const
{
    return n_name;
}
void Contact::set_n_name(std::string s)
{
    n_name = s;
}
std::string Contact::get_phone() const
{
    return phone;
}
void Contact::set_phone(std::string s)
{
    phone = s;
}
std::string Contact::get_secret() const
{
    return secret;
}
void Contact::set_secret(std::string s)
{
    secret = s;
}