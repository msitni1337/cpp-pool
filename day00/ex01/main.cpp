#include "PhoneBook.hpp"
#include "assert.h"
#include "stdio.h"

int main()
{
    PhoneBook pb;
    std::string input;

    std::cout << "Welcome to Yellow Book - Small Contacts Application.\n";
    for(;;)
    {
        std::cout << "\tChoose between [ADD/SEARCH/EXIT]\n";
        std::cout << "\t-> ";
        std::getline(std::cin, input);
        if (input == "ADD")
            pb.add_to_book();
        else if (input ==  "SEARCH")
           pb.search();
        else if (input == "EXIT")
            break;
    }
    return 0;
}