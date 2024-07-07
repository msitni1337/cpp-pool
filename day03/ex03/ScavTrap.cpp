#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
    std::cout << "Constructor for Scav Trap " << getName() << " Called\n";
}
ScavTrap::ScavTrap(const ScavTrap &scavtrap) : ClapTrap(scavtrap)
{
    std::cout << "Copy Constructor for Scav Trap " << getName() << " Called\n";
}
ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap)
{
    if (this != &scavtrap)
    {
        setName(scavtrap.getName());
        setHitPoints(scavtrap.getHitPoints());
        setEnergyPoints(scavtrap.getEnergyPoints());
        setAttackDamage(scavtrap.getAttackDamage());
    }
    std::cout << "Copy assignement for Scav Trap " << getName() << " Called\n";
    return *this;
}
ScavTrap::~ScavTrap()
{
    std::cout << "Destructor for Scav Trap " << getName() << " Called\n";
}
void ScavTrap::attack(const std::string &target)
{
    unsigned int EnergyPoints = getEnergyPoints();
    unsigned int HitPoints = getHitPoints();
    if (EnergyPoints != 0 && HitPoints != 0)
    {
        EnergyPoints--;
        setEnergyPoints(EnergyPoints);
        std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!\n";
    }
    else
    {
        std::cout << "ScavTrap " << getName() << " has no more Energy Points or Hit Points to attack.\n";
    }
}
void ScavTrap::guardGate()
{
    unsigned int EnergyPoints = getEnergyPoints();
    unsigned int HitPoints = getHitPoints();
    if (EnergyPoints != 0 && HitPoints != 0)
    {
        EnergyPoints--;
        setEnergyPoints(EnergyPoints);
        std::cout << "ScavTrap " << getName() << " is now in gate keeper mode!\n";
    }
    else
    {
        std::cout << "ScavTrap " << getName() << " has no more Energy Points or Hit Points to guard gate.\n";
    }
}