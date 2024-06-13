#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    insert_index = 0;
    contacts_count = 0;
}

void PhoneBook::add_to_book()
{
    std::string *input;
    Contact contact;

    if ((input = get_value("Please input contact's first name:")) == NULL)
        return;
    contact.f_name = *input;
    if ((input = get_value("Please input contact's last name:")) == NULL)
        return;
    contact.l_name = *input;
    if ((input = get_value("Please input contact's nickname:")) == NULL)
        return;
    contact.n_name = *input;
    if ((input = get_value("Please input contact's phone number:")) == NULL)
        return;
    contact.phone = *input;
    if ((input = get_value("Please input contact's darkest secret:")) == NULL)
        return;
    contact.secret = *input;
}

std::string *PhoneBook::get_value(const char *prompt)
{
    std::string *result;

    result = new std::string;
    std::cout << prompt << std::endl;
    std::cin >> *result;
    if (result->length() == 0)
    {
        std::cout << "You can't leave this field empty." << std::endl;
        delete result;
        return NULL;
    }
    return result;
}
