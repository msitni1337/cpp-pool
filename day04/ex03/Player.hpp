#include "ICharacter.hpp"

class Player : public ICharacter
{
private:
public:
    Player(const std::string name);
    Player(const Player &player);
    ~Player();
    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
};