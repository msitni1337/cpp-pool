#include "FragTrap.hpp"

int main()
{
    {
        FragTrap ft("msitni");

        ft.highFivesGuys();
    }
    std::cout << "==============================================================\n";
    {
        FragTrap ft("m42");
        for (size_t i = 0; i < 10; i++)
            ft.attack("msitni");
        for (size_t i = 0; i < 10; i++)
            ft.takeDamage(10);
        ft.beRepaired(10);
        ft.attack("msitni");
    }
    std::cout << "==============================================================\n";
    {
        FragTrap ft("mohammed");
        ft.attack("msitni");
        ft.takeDamage(10);
        ft.beRepaired(10);
        ft.attack("msitni");
        ft.highFivesGuys();
    }
    return 0;
}