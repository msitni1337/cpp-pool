#include "Animal.hpp"

Animal::Animal()
{
    type = "Animal";
    std::cout << "Constructor for " << type << " class called\n";
}
Animal::~Animal()
{
    std::cout << "Destructor for " << type << " class called\n";
}
std::string Animal::getType() const
{
    return type;
}
void Animal::makeSound() const
{
    std::cout << "Different animals have different voices.\n";
}
