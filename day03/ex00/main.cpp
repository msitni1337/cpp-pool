#include "ClapTrap.hpp"

int main()
{
    {
        ClapTrap ct("msitni");

        for (int i = 0; i < 4; i++)
            ct.beRepaired(1900000000);
        for (int i = 0; i < 7; i++)
            ct.attack("1337");
    }
    std::cout << "==============================================================\n";
    {
        ClapTrap ct("m42");

        for (int i = 0; i < 8; i++)
            ct.takeDamage(2);
    }
    return 0;
}