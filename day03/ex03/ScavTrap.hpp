#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
private:

public:
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& scavtrap);
    ScavTrap& operator=(const ScavTrap& scavtrap);
    ~ScavTrap();
    void attack(const std::string &target);
    void guardGate();
};