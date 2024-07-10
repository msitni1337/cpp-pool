#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
    Brain* brain;    
public:
    Cat();
    ~Cat();
    Cat& operator=(const Cat& cat);
    void makeSound() const;
};