#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    type = "Animal";
    std::cout << "Constructor for AAnimal type" << type << " class called\n";
}
AAnimal::AAnimal(const AAnimal &animal)
{
    type = animal.type;
    std::cout << "Copy Constructor for AAnimal type " << type << " class called\n";
}
AAnimal &AAnimal::operator=(const AAnimal &animal)
{
    (void)animal;
    std::cout << "Copy Assignemnt for AAnimal type " << type << " class called\n";
    return *this;
}
AAnimal::~AAnimal()
{
    std::cout << "Destructor for AAnimal type " << type << " class called\n";
}
std::string AAnimal::getType() const
{
    return type;
}
void AAnimal::makeSound() const
{
    std::cout << "Different animals have different voices.\n";
}