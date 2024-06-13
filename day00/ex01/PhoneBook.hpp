#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook
{
    public:
    PhoneBook();
    void add_to_book();
    void search();
    private:
    Contact contacts[8];
    int contacts_count;
    int insert_index;
    std::string* get_value(const char*prompt);
};
#endif