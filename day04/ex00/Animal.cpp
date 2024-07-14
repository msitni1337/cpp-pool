#include "Animal.hpp"

Animal::Animal()
{
    type = "Animal";
    std::cout << "Constructor for Animal " << type << " class called\n";
}
Animal::Animal(const Animal &animal)
{
    type = animal.type;
    std::cout << "Copy Constructor for Animal " << type << " class called\n";
}
Animal &Animal::operator=(const Animal &animal)
{
    (void) animal;
    std::cout << "Copy Assignemnt for Animal " << type << " class called\n";
    return *this;
}
Animal::~Animal()
{
    std::cout << "Destructor for Animal " << type << " class called\n";
}
std::string Animal::getType() const
{
    return type;
}
void Animal::makeSound() const
{
    std::cout << "Different animals have different voices.\n";
}
