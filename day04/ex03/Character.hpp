#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
    static const unsigned int InventorySize = 4;
    std::string Name;
    AMateria *Inventory[InventorySize];

public:
    Character(const std::string name);
    Character(const Character &character);
    Character &operator=(const Character &character);
    ~Character();
    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
    ICharacter *clone() const;
};