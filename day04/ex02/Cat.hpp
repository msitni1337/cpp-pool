#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
    Brain* brain;    
public:
    Cat();
    Cat(const Cat& cat);
    Cat& operator=(const Cat& cat);
    ~Cat();
    void makeSound() const;
};