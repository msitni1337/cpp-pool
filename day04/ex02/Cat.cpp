#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    brain = new Brain("Random cat idea..");
    std::cout << "Constructor for Cat type " << type << " class called\n";
}
Cat::Cat(const Cat &cat) : AAnimal(cat)
{
    brain = new Brain(*cat.brain);
    std::cout << "Copy Constructor for Cat type " << type << " class called\n";
}
Cat &Cat::operator=(const Cat &cat)
{
    if (this != &cat)
    {
        delete brain;
        brain = new Brain(*cat.brain);
    }
    std::cout << "Copy Constructor for Cat type " << type << " class called\n";
    return *this;
}
Cat::~Cat()
{
    delete brain;
    std::cout << "Destructor for Cat type " << type << " class called\n";
}
void Cat::makeSound() const
{
    std::cout << "Meow, Meow, Meow...\n";
}