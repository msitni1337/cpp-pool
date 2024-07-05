#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
    std::cout << "Constructor for Frag Trap " << Name << " Called\n";
}
FragTrap::~FragTrap()
{
    std::cout << "Destructor for Frag Trap " << Name << " Called\n";
}
void FragTrap::highFivesGuys(void)
{
    std::cout << "Frag Trap " << Name << " is requesting a high five.\n";
}
