#include "Character.hpp"

Character::Character(const std::string name) : Name(name)
{
	for (size_t i = 0; i < sizeof(Inventory) / sizeof(Inventory[0]); i++)
		Inventory[i] = NULL;
}
Character::Character(const Character &character) : ICharacter(character)
{
	for (size_t i = 0; i < sizeof(Inventory) / sizeof(Inventory[0]); i++)
		Inventory[i] = NULL;
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
ICharacter *Character::clone() const
{
	Character *c = new Character(*this);
	return c;
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
			return;
		}
	}
	std::cerr << "No more free slots in Inventory to equip a new materia\n";
}
void Character::unequip(int idx)
{
	if (idx >= 0 && (unsigned int)idx < InventorySize && Inventory[idx])
		Inventory[idx] = NULL;
	else
		std::cerr << "Can't unequip materia at index: " << idx << '\n';
}
void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && (unsigned int)idx < InventorySize && Inventory[idx])
		Inventory[idx]->use(target);
	else
		std::cerr << "Can't use materia at index: " << idx << '\n';
}
