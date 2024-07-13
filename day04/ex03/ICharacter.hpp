#pragma once
#include <string>

class ICharacter
{
protected:
    std::string Name;
    AMateria *inventory[4];

public:
    ICharacter(const std::string Name);
    ICharacter(const ICharacter &obj);
    ICharacter &operator=(const ICharacter &obj);
    virtual ~ICharacter();
    virtual std::string const &getName() const = 0;
    virtual void equip(AMateria *m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter &target) = 0;
    virtual ICharacter *clone() const = 0;
};

class AMateria
{
protected:
    std::string type;

public:
    AMateria(std::string const &type);
    AMateria(const AMateria &type);
    AMateria& operator=(const AMateria &type);
    virtual ~AMateria();
    std::string const &getType() const;
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target) = 0;
};