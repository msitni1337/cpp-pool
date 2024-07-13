#include "DiamondTrap.hpp"

int main()
{
    std::cout << "================= Simple Test ====================\n";
    {
        DiamondTrap ft("msitni");
        
        std::cout << std::endl;
        ft.whoAmI();
        std::cout << "My Hit Points:    " << ft.getHitPoints() << std::endl;
        std::cout << "My Energy Points: " << ft.getEnergyPoints() << std::endl;
        std::cout << "My Attack Damage: " << ft.getAttackDamage() << std::endl;
        ft.attack("Ahmed");
        ft.guardGate();
        ft.highFivesGuys();
        std::cout << std::endl;
    }
    return 0;
}