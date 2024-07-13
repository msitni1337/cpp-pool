#pragma once
#include <string>
#include <iostream>

class ClapTrap
{
protected:
    std::string Name;
    unsigned int HitPoints;
    unsigned int EnergyPoints;
    unsigned int AttackDamage;

public:
    ClapTrap(std::string name, unsigned int hp = 10, unsigned ep = 10, unsigned int ad = 0);
    ClapTrap(const ClapTrap &claptrap);
    ClapTrap &operator=(const ClapTrap &claptrap);
    virtual ~ClapTrap();
    virtual void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    std::string getName() const;
    void setName(std::string s);
    unsigned int getHitPoints() const;
    void setHitPoints(unsigned int val);
    unsigned int getEnergyPoints() const;
    void setEnergyPoints(unsigned int val);
    unsigned int getAttackDamage() const;
    void setAttackDamage(unsigned int val);
};