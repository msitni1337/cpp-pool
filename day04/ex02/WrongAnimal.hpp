#pragma once
#include <string>
#include <iostream>

class WrongAnimal
{
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& animal);
    WrongAnimal& operator=(const WrongAnimal& animal);
    ~WrongAnimal();
    std::string getType() const;
    void makeSound() const;
};