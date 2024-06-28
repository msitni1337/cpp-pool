#pragma once
#include "Weapon.hpp"
#include <iostream>

class HumanB
{
private:
    std::string name;
    Weapon* weapon;
    HumanB();
public:
    HumanB(std::string name);
    ~HumanB();
    void setWeapon(Weapon& weapon);
    void attack() const;
};