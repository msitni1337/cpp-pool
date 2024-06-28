#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    weapon = NULL;
}
HumanB::~HumanB()
{}
void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}
void HumanB::attack() const
{
    if (weapon != NULL)
    {
        std::cout << name << " attacks with their " << weapon->getType() << '\n';
    }
}