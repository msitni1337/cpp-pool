#pragma once
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
    std::string Name;
public:
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap &dt);
    DiamondTrap &operator=(const DiamondTrap &dt);
    ~DiamondTrap();
    void attack(const std::string &target);
    void whoAmI();
};