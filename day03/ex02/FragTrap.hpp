#pragma once
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:
public:
    FragTrap(std::string name);
    FragTrap(const FragTrap& scavtrap);
    FragTrap& operator=(const FragTrap& scavtrap);
    ~FragTrap();
    void attack(const std::string &target);
    void highFivesGuys(void);
};