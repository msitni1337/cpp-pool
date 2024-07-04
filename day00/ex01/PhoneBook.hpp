#pragma once
#include "Contact.hpp"
#include <iomanip>

class PhoneBook
{
public:
    PhoneBook();
    PhoneBook(const PhoneBook &pbook);
    PhoneBook& operator=(const PhoneBook&pbook);
    ~PhoneBook();
    void add_to_book();
    void search();
    
    int get_contacts_count();
    int get_insert_index();

private:
    Contact contacts[8];
    int contacts_count;
    int insert_index;
    std::string get_value(const char *prompt);
    void diplay_column(std::string str, size_t width, bool print_pipe = true);
};