#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Constructor for Dog " << type << " class called\n";
}
Dog::Dog(const Dog&dog) : Animal(dog)
{
    std::cout << "Copy Constructor for Dog " << type << " class called\n";
}
Dog&Dog::operator=(const Dog&dog)
{
    (void) dog;
    std::cout << "Copy Assignemnt for Dog " << type << " class called\n";
    return *this;
}
Dog::~Dog()
{
    std::cout << "Destructor for Dog " << type << " class called\n";
}
void Dog::makeSound() const
{
    std::cout << "Haw, Haw, Haw...\n";
}