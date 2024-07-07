#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name)
{
}
DiamondTrap::DiamondTrap(const DiamondTrap &dt)
: ClapTrap("name"), FragTrap("name"), ScavTrap("name")
{
    (void) dt;
}
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &dt)
{
    (void) dt;
    return *this;
}
DiamondTrap::~DiamondTrap()
{
}
void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}
