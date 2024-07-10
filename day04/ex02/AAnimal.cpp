#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    type = "Animal";
    std::cout << "Constructor for " << type << " class called\n";
}
AAnimal::~AAnimal()
{
    std::cout << "Destructor for Animal type " << type << " class called\n";
}
std::string AAnimal::getType() const
{
    return type;
}
void AAnimal::makeSound() const
{
    std::cout << "Different animals have different voices.\n";
}
