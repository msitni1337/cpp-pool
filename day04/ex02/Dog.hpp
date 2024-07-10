#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
private:
    Brain* brain;    
public:
    Dog();
    ~Dog();
    void makeSound() const;
};