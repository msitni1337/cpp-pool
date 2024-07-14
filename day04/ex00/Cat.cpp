#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Constructor for Cat " << type << " class called\n";
}
Cat::Cat(const Cat &cat) : Animal(cat)
{
    std::cout << "Copy Constructor for Cat " << type << " class called\n";
}
Cat & Cat::operator=(const Cat &cat)
{
    (void) cat;
    std::cout << "Copy Assignemnt for Cat " << type << " class called\n";
    return *this;
}
Cat::~Cat()
{
    std::cout << "Destructor for Cat " << type << " class called\n";
}
void Cat::makeSound() const
{
    std::cout << "Meow, Meow, Meow...\n";
}