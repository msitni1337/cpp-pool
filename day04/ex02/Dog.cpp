#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    brain = new Brain("Random dog idea..");
    std::cout << "Constructor for Dog type " << type << " class called\n";
}
Dog::Dog(const Dog &dog) : AAnimal(dog)
{
    brain = new Brain(*dog.brain);
    std::cout << "Copy Constructor for Dog type " << type << " class called\n";
}
Dog &Dog::operator=(const Dog &dog)
{
    if (this != &dog)
    {
        delete brain;
        brain = new Brain(*dog.brain);
    }
    std::cout << "Copy Constructor for Dog type " << type << " class called\n";
    return *this;
}
Dog::~Dog()
{
    delete brain;
    std::cout << "Destructor for Dog type " << type << " class called\n";
}
void Dog::makeSound() const
{
    std::cout << "Haw, Haw, Haw...\n";
}