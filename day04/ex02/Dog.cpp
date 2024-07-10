#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    brain = new Brain("Random dog idea..");
    std::cout << "Constructor for " << type << " class called\n";
}
Dog::~Dog()
{
    delete brain;
    std::cout << "Destructor for " << type << " class called\n";
}
void Dog::makeSound() const
{
    std::cout << "Haw, Haw, Haw...\n";
}