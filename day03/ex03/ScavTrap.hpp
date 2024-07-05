#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
public:
    ScavTrap(std::string name);
    ~ScavTrap();
    void guardGate();
};