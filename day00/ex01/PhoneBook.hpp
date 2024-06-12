#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
#include <iostream>

class PhoneBook
{
    public:
    void add_to_book();
    void search();
    private:
    Contact contacts[8];
    int insert_index;
};
#endif