#pragma once
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
    std::string Name;
public:
    DiamondTrap(std::string name);
    ~DiamondTrap();
    void whoAmI();
};
