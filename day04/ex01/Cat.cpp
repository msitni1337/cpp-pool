#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    brain = new Brain();
    
    // populate with ideas...

    std::cout << "Constructor for " << type << " class called\n";
}
Cat::~Cat()
{
    delete brain;
    std::cout << "Destructor for " << type << " class called\n";
}
void Cat::makeSound() const
{
    std::cout << "Meow, Meow, Meow...\n";
}