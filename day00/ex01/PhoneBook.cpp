#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook()
{
    insert_index = 0;
    contacts_count = 0;
}

PhoneBook::PhoneBook(const PhoneBook &pbook)
{
    for (size_t i = 0; i < 8; i++)
        contacts[i] = pbook.contacts[i];
    contacts_count = pbook.contacts_count;
    insert_index = pbook.insert_index;
}

PhoneBook &PhoneBook::operator=(const PhoneBook &pbook)
{
    if (this != &pbook)
    {
        for (size_t i = 0; i < 8; i++)
            contacts[i] = pbook.contacts[i];
        contacts_count = pbook.contacts_count;
        insert_index = pbook.insert_index;
    }

    return *this;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::add_to_book()
{
    std::string input;

    if ((input = get_value("Please input contact's first name:")).length() == 0)
        return;
    contacts[insert_index].set_f_name(input);
    if ((input = get_value("Please input contact's last name:")).length() == 0)
        return;
    contacts[insert_index].set_l_name(input);
    if ((input = get_value("Please input contact's nickname:")).length() == 0)
        return;
    contacts[insert_index].set_n_name(input);
    if ((input = get_value("Please input contact's phone number:")).length() == 0)
        return;
    contacts[insert_index].set_phone(input);
    if ((input = get_value("Please input contact's darkest secret:")).length() == 0)
        return;
    contacts[insert_index].set_secret(input);
    insert_index = (insert_index + 1) % 8;
    contacts_count++;
}

void PhoneBook::diplay_column(std::string str, size_t width, bool print_pipe = true)
{
    if (str.length() > width)
    {
        str = str.substr(0, width - 1);
        str += '.';
    }
    std::cout << std::setw(width) << str;
    if (print_pipe)
        std::cout << "|";
}

void PhoneBook::search()
{
    if (contacts_count < 1)
    {
        std::cout << "No contacts to display." << std::endl;
        return;
    }
    std::cout << std::left;
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nick Name" << std::endl;
    for (int i = 0; i < contacts_count; i++)
    {
        std::cout << std::setw(10) << i << "|";
        diplay_column(contacts[i].get_f_name(), 10);
        diplay_column(contacts[i].get_l_name(), 10);
        diplay_column(contacts[i].get_n_name(), 10, false);
        std::cout << std::endl;
    }

    int chosen_index;
    std::cout << "\tEnter contact index [0-" << contacts_count - 1 << "]: ";
    std::cin >> chosen_index;
    std::cin.ignore();
    if (chosen_index < 0 || chosen_index >= contacts_count)
    {
        std::cout << "Index out of bound." << std::endl;    
        return;
    }
    std::cout << "first Name: " << contacts[chosen_index].get_f_name() << std::endl;
    std::cout << "last Name: " << contacts[chosen_index].get_l_name() << std::endl;
    std::cout << "nick Name: " << contacts[chosen_index].get_n_name() << std::endl;
    std::cout << "phone: " << contacts[chosen_index].get_phone() << std::endl;
    std::cout << "darkest secret: " << contacts[chosen_index].get_secret() << std::endl;
}

std::string PhoneBook::get_value(const char *prompt)
{
    std::string result;

    std::cout << prompt << std::endl;
    getline(std::cin, result);
    if (result.length() == 0)
        std::cout << "You can't leave this field empty." << std::endl
                  << "returning to main..." << std::endl;
    return result;
}
