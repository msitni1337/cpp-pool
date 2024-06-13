#include "PhoneBook.hpp"
#include "assert.h"
#include "stdio.h"

int main()
{
    PhoneBook pb;
    char buff[1024];
    int bytes;

    while ((bytes = read(STDIN_FILENO, buff, 1023)) > 0)
    {
        buff[bytes] = 0;
        if (strcmp(buff, "ADD\n") == 0)
            pb.add_to_book();
        else if (strcmp(buff, "SEARCH\n") == 0)
            assert(!"NOT IMPLEMENTED");
           /* pb.search(); */
        else if (strcmp(buff, "EXIT\n") == 0)
            /* HANDLE EXIT LOGIC ..*/
            return 0;
    }
    return 0;
}