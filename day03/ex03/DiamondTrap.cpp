#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
    Name = name;
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(30);
    std::cout << "Constructor for Diamond Trap " << Name << " Called\n";
}
DiamondTrap::DiamondTrap(const DiamondTrap &dt)
    : ClapTrap(dt.ClapTrap::getName()), FragTrap(dt.Name), ScavTrap(dt.Name)
{
    Name = dt.Name;
    setHitPoints(dt.getHitPoints());
    setEnergyPoints(dt.getEnergyPoints());
    setAttackDamage(dt.getAttackDamage());
    std::cout << "Copy Constructor for Diamond Trap " << Name << " Called\n";
}
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &dt)
{
    if (this != &dt)
    {
        Name = dt.Name;
        ClapTrap::setName(dt.getName());
        setHitPoints(dt.getHitPoints());
        setEnergyPoints(dt.getEnergyPoints());
        setAttackDamage(dt.getAttackDamage());
    }
    std::cout << "Copy assignement operator for Diamond Trap " << Name << " Called\n";
    return *this;
}
DiamondTrap::~DiamondTrap()
{
    std::cout << "Destructor for Diamond Trap " << Name << " Called\n";
}
void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}
void DiamondTrap::whoAmI()
{
    std::cout << "Hello, I'm " << Name << std::endl;
    std::cout << "And also, I'm " << getName() << std::endl;
}