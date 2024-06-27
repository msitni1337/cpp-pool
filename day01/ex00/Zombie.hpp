#pragma once
#include <string>
#include <iostream>

class Zombie
{
private:
    Zombie();
    std::string name;
public:
    Zombie(std::string name);
    ~Zombie();
    void announce(void);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);