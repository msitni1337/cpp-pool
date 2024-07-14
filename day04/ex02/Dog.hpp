#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
private:
    Brain *brain;

public:
    Dog();
    Dog(const Dog &dog);
    Dog &operator=(const Dog &dog);
    ~Dog();
    void makeSound() const;
};