#include "PhoneBook.hpp"
#include "assert.h"
#include "stdio.h"

int main()
{
    PhoneBook pb;
    std::string input;

    std::cout << "\n\tWelcome to Yellow Book - Small Contacts Application.\n\n";
    while(!std::cin.eof())
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
        else
            std::cout << "invalid choice: " << input << '\n';
    }
    return 0;
}