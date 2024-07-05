#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    std::cout << "Constructor for Scav Trap " << Name << " Called\n";
}
ScavTrap::~ScavTrap()
{
    std::cout << "Destructor for Scav Trap " << Name << " Called\n";
}
void ScavTrap::guardGate()
{
    std::cout << "Scav Trap " << Name << "  is now in Gate keeper mode.\n";
}
