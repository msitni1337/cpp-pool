#pragma once
#include <string>

class Weapon
{
private:
    Weapon();
    std::string type;
public:
    Weapon(std::string type);
    ~Weapon();
    const std::string& getType() const;
    void setType(std::string newType);
};