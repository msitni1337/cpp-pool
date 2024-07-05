#pragma once
#include <string>
#include <iostream>

class Animal
{
protected:
    std::string type;
public:
    Animal();
    virtual ~Animal();
    std::string getType() const;
    virtual void makeSound() const;
};