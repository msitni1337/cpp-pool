#include "Zombie.hpp"

Zombie::Zombie()
{}
Zombie::Zombie(std::string name)
{
    this->name = name;
}
Zombie::~Zombie()
{
    std::cout << name << ": is dead...\n";
}
void Zombie::set_name(std::string name)
{
    this->name = name;
}
void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}