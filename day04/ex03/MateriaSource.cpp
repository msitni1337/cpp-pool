#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < InventorySize; i++)
		Inventory[i] = NULL;
}
MateriaSource::MateriaSource(const MateriaSource &msource) : IMateriaSource(msource)
{
	for (size_t i = 0; i < InventorySize; i++)
		Inventory[i] = NULL;
	*this = msource;
}
MateriaSource &MateriaSource::operator=(const MateriaSource &msource)
{
	if (this == &msource)
		return *this;
	for (size_t i = 0; i < InventorySize; i++)
	{
		delete Inventory[i];
		if (msource.Inventory[i])
			Inventory[i] = msource.Inventory[i]->clone();
		else
			Inventory[i] = NULL;
	}
	return *this;
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
		if (Inventory[i] == NULL)
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
		if (Inventory[i] && Inventory[i]->getType() == type)
			return Inventory[i]->clone();
	}
	return NULL;
}