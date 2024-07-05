#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Constructor for " << type << " class called\n";
}
Cat::~Cat()
{
    std::cout << "Destructor for " << type << " class called\n";
}
void Cat::makeSound() const
{
    std::cout << "Meow, Meow, Meow...\n";
}