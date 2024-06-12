#include "PhoneBook.hpp"

void PhoneBook::PhoneBook()
{
    insert_index = 0;
    contacts_count = 0;
}

void PhoneBook::add_to_book()
{
    Contact contact;

    std::cout << "Please input contact's first name:" << std::endl;
    std::cin >> contact.f_name;
    std::cout << "Please input contact's last name:" << std::endl;
    std::cin >> contact.l_name;
    std::cout << "Please input contact's nickname:" << std::endl;
    std::cin >> contact.n_name;
    std::cout << "Please input contact's phone number:" << std::endl;
    std::cin >> contact.phone;
    std::cout << "Please input contact's darkest secret:" << std::endl;
    std::cin >> contact.secret;
}

std::string* get_value(char*prompt)
{
    std::string* result;

    result = new();
    std::cout << prompt << std::endl;
    std::cin >> *result;
    if (result->)
    {
        /* code */
    }
    
}
