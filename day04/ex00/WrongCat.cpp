#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "Constructor for WrongCat " << type << " class called\n";
}
WrongCat::WrongCat(const WrongCat &cat) : WrongAnimal(cat)
{
    std::cout << "Copy Constructor for WrongCat " << type << " class called\n";
}
WrongCat & WrongCat::operator=(const WrongCat &cat)
{
    (void) cat;
    std::cout << "Copy Assignemnt for WrongCat " << type << " class called\n";
    return *this;
}
WrongCat::~WrongCat()
{
    std::cout << "Destructor for WrongCat " << type << " class called\n";
}
void WrongCat::makeSound() const
{
    std::cout << "Meow, Meow, Meow...\n";
}