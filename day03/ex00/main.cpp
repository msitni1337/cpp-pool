#include "ClapTrap.hpp"

int main()
{
    std::cout << "================= Subject Tests ======================\n\n";
    {
        ClapTrap ct("msitni");

        for (int i = 0; i < 4; i++)
            ct.beRepaired(1900000000);
        for (int i = 0; i < 7; i++)
            ct.attack("1337");
    }
    std::cout << "\n==== Testing attacking after taking full damage ======\n\n";
    {
        ClapTrap ct("m42");

        for (int i = 0; i < 8; i++)
            ct.takeDamage(2);
    }
    std::cout << "\n======== Testing copy assignement operator ============\n\n";
    {
        ClapTrap ct("m42");

        for (int i = 0; i < 4; i++)
            ct.takeDamage(2);

        ClapTrap ct2("msitni");
        ct2 = ct;
        for (int i = 0; i < 4; i++)
            ct2.takeDamage(2);
    }
    return 0;
}