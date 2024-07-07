#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "================= Simple High Five Test ====================\n";
    {
        FragTrap ft("msitni");

        ft.highFivesGuys();
    }
    std::cout << "================= Depleting Energy test ===================\n";
    {
        FragTrap ft("m42");
        for (size_t i = 0; i < 10; i++)
            ft.attack("msitni");
        for (size_t i = 0; i < 10; i++)
            ft.takeDamage(10);
        ft.beRepaired(10);
        ft.attack("msitni");
    }
    std::cout << "================ Repairing Funcs test =====================\n";
    {
        FragTrap ft("mohammed");
        ft.attack("msitni");
        ft.takeDamage(10);
        ft.beRepaired(10);
        ft.attack("msitni");
        ft.highFivesGuys();
    }
    std::cout << "================ Dynamic binding test =====================\n";
    {
        ClapTrap *ct[2] = {new FragTrap("mohammed"), new ScavTrap("msitni")};
        ct[0]->attack("Ahmed");
        ct[1]->attack("Ahmed");
        delete ct[0];
        delete ct[1];
    }
    return 0;
}