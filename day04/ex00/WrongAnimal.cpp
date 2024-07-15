#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    type = "WrongAnimal";
    std::cout << "Constructor for WrongAnimal " << type << " class called\n";
}
WrongAnimal::WrongAnimal(const WrongAnimal &animal)
{
    type = animal.type;
    std::cout << "Copy Constructor for WrongAnimal " << type << " class called\n";
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal)
{
    (void) animal;
    std::cout << "Copy Assignemnt for WrongAnimal " << type << " class called\n";
    return *this;
}
WrongAnimal::~WrongAnimal()
{
    std::cout << "Destructor for WrongAnimal " << type << " class called\n";
}
std::string WrongAnimal::getType() const
{
    return type;
}
void WrongAnimal::makeSound() const
{
    std::cout << "Different animals have different voices.\n";
}
