#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
public:
    WrongCat();
    WrongCat(const WrongCat&cat);
    WrongCat& operator=(const WrongCat&cat);
    ~WrongCat();
    void makeSound() const;
};