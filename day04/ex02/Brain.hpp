#pragma once
#include <string>
#include <iostream>

class Brain
{
private:
    std::string ideas[100];
public:
    Brain(const std::string &idea);
    Brain(const Brain& brain);
    Brain& operator=(const Brain& brain);
    ~Brain();
};