#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
    Name = name;
    HitPoints = 10;
    EnergyPoints = 10;
    AttackDamage = 0;
    std::cout << "Constructor for Clap Trap " << Name << " Called\n";
}
ClapTrap::~ClapTrap()
{
    std::cout << "Destructor for Clap Trap " << Name << " Called\n";
}
void ClapTrap::attack(const std::string &target)
{
    if (EnergyPoints != 0 && HitPoints != 0)
    {
        EnergyPoints--;
        std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!\n";
    }
    else
    {
        std::cout << "ClapTrap " << Name << " has no more Energy Points or Hit Points to attack.\n";
    }
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (HitPoints != 0)
    {
        if (amount > HitPoints)
            HitPoints = 0;
        else
            HitPoints -= amount;
        std::cout << "ClapTrap " << Name << " took " << amount << " of damage now he has " << HitPoints << " of health points left\n";
    }
    else
    {
        std::cout << "ClapTrap " << Name << " has no Health Points to take more damage.\n";
    }
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (EnergyPoints != 0 && HitPoints != 0)
    {
        EnergyPoints--;
        long tmp = HitPoints + amount;
        if (tmp > __INT_MAX__)
            HitPoints = __INT_MAX__;
        else
            HitPoints = tmp;
        std::cout << "ClapTrap " << Name << " gained " << amount << " Hit Points back, Hit Points = " << HitPoints << "\n";
    }
    else
    {
        std::cout << "ClapTrap " << Name << " has no more Energy Points or Hit Points to be repaired.\n";
    }
}