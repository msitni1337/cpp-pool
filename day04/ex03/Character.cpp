#include "Character.hpp"

Character::Character(const std::string name) : Name(name)
{
	for (size_t i = 0; i < sizeof(Inventory) / sizeof(Inventory[0]); i++)
		Inventory[i] = NULL;
}
Character::Character(const Character &character)
{
	*this = character;
}
Character &Character::operator=(const Character &character)
{
	if (this == &character)
		return *this;
	for (size_t i = 0; i < sizeof(Inventory) / sizeof(Inventory[0]); i++)
		delete Inventory[i];
	for (size_t i = 0; i < sizeof(Inventory) / sizeof(Inventory[0]); i++)
		if (character.Inventory[i])
			Inventory[i] = character.Inventory[i]->clone();
		else
			Inventory[i] = NULL;
	Name = character.Name;
	return *this;
}
Character::~Character()
{
	for (size_t i = 0; i < sizeof(Inventory) / sizeof(Inventory[0]); i++)
		delete Inventory[i];
}
std::string const &Character::getName() const
{
	return Name;
}
void Character::equip(AMateria *m)
{
	for (size_t i = 0; i < sizeof(Inventory) / sizeof(Inventory[0]); i++)
	{
		if (Inventory[i] == NULL)
		{
			Inventory[i] = m;
			break;
		}
	}
}
void Character::unequip(int idx)
{
	if (idx >= 0 && (unsigned int) idx < InventorySize)
		Inventory[idx] = NULL;
}
void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && (unsigned int) idx < InventorySize && Inventory[idx])
		Inventory[idx]->use(target);
}
