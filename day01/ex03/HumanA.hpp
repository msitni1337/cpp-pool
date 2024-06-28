#pragma once
#include "Weapon.hpp"
#include <iostream>

class HumanA
{
private:
    std::string name;
    Weapon& weapon;
    HumanA();
public:
    HumanA(std::string name, Weapon& weapon);
    ~HumanA();
    void setWeapon(Weapon& weapon);
    void attack() const;
};