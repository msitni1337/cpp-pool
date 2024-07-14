#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < InventorySize; i++)
		Inventory[i] = nullptr;
}
MateriaSource::MateriaSource(const MateriaSource &msource)
{
	*this = msource;
}
MateriaSource &MateriaSource::operator=(const MateriaSource &msource)
{
	for (size_t i = 0; i < InventorySize; i++)
	{
		delete Inventory[i];
		if (msource.Inventory[i])
			Inventory[i] = msource.Inventory[i]->clone();
		else
			Inventory[i] = nullptr;
	}
}
MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < InventorySize; i++)
		delete Inventory[i];
}
void MateriaSource::learnMateria(AMateria *materia)
{
	for (size_t i = 0; i < InventorySize; i++)
	{
		if (Inventory[i] == nullptr)
		{
			Inventory[i] = materia->clone();
			break;
		}
	}
}
AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (size_t i = 0; i < InventorySize; i++)
	{
		if(Inventory[i] && Inventory[i]->getType() == type)
			return Inventory[i]->clone();
	}
	return nullptr;
}