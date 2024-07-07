#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
    std::cout << "Constructor for Frag Trap " << getName() << " Called\n";
}
FragTrap::FragTrap(const FragTrap &scavtrap) : ClapTrap(scavtrap)
{
    std::cout << "Copy Constructor for Frag Trap " << getName() << " Called\n";
}
FragTrap &FragTrap::operator=(const FragTrap &scavtrap)
{
    if (this != &scavtrap)
    {
        setName(scavtrap.getName());
        setHitPoints(scavtrap.getHitPoints());
        setEnergyPoints(scavtrap.getEnergyPoints());
        setAttackDamage(scavtrap.getAttackDamage());
    }
    std::cout << "Copy assignement for Frag Trap " << getName() << " Called\n";
    return *this;
}
FragTrap::~FragTrap()
{
    std::cout << "Destructor for Frag Trap " << getName() << " Called\n";
}
void FragTrap::attack(const std::string &target)
{
    unsigned int EnergyPoints = getEnergyPoints();
    unsigned int HitPoints = getHitPoints();
    if (EnergyPoints != 0 && HitPoints != 0)
    {
        EnergyPoints--;
        setEnergyPoints(EnergyPoints);
        std::cout << "FragTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!\n";
    }
    else
    {
        std::cout << "FragTrap " << getName() << " has no more Energy Points or Hit Points to attack.\n";
    }
}
void FragTrap::highFivesGuys(void)
{
    unsigned int EnergyPoints = getEnergyPoints();
    unsigned int HitPoints = getHitPoints();
    if (EnergyPoints != 0 && HitPoints != 0)
    {
        EnergyPoints--;
        setEnergyPoints(EnergyPoints);
        std::cout << "FragTrap " << getName() << " is kindly requesting a high fives!\n";
    }
    else
    {
        std::cout << "FragTrap " << getName() << " has no more Energy Points or Hit Points to high fives.\n";
    }
}