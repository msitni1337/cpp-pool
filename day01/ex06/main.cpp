#include "Harl.hpp"

int main(int c, const char **v)
{
    Harl harl;

    if (c == 2)
    {
        harl.complain(v[1]);
        return 0;
    }
    return 1;
}