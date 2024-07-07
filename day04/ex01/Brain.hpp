#pragma once
#include <string>

class Brain
{
private:
public:
    std::string ideas[100];
    Brain();
    Brain(const Brain& brain);
    Brain& operator=(const Brain& brain);
    ~Brain();
};