#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	static const unsigned int InventorySize = 4;
	AMateria *Inventory[InventorySize];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &msource);
	MateriaSource &operator=(const MateriaSource &msource);
	~MateriaSource();
	void learnMateria(AMateria *materia);
	AMateria *createMateria(std::string const &type);
};