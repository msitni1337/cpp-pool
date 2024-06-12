#include "PhoneBook.hpp"

int main()
{
    PhoneBook pb;
    char buff[1024];
    int bytes;

    while ((bytes = read(STDIN_FILENO, buff, 1023)) > 0)
    {
        buff[bytes] = 0;
        if (strcmp(buff, "ADD"))
            pb.add_to_book();
        if (strcmp(buff, "SEARCH"))
            pb.search();
        else if (strcmp(buff, "EXIT"))
            /* HANDLE EXIT LOGIC ..*/
            return 0;
    }
    return 0;
}