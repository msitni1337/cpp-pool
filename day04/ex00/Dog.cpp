#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Constructor for " << type << " class called\n";
}
Dog::~Dog()
{
    std::cout << "Destructor for " << type << " class called\n";
}
void Dog::makeSound() const
{
    std::cout << "Haw, Haw, Haw...\n";
}