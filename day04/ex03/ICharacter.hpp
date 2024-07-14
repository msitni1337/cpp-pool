#pragma once
#include <string>

class AMateria;

class ICharacter
{
protected:
    std::string Name;
public:
    ICharacter();
    ICharacter(const ICharacter &obj);
    ICharacter &operator=(const ICharacter &obj);
    virtual ~ICharacter();
    virtual std::string const &getName() const = 0;
    virtual void equip(AMateria *m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter &target) = 0;
    virtual ICharacter *clone() const = 0;
};