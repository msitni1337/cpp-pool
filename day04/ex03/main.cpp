#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	std::cout << "\n================= Subject test =====================\n\n";
	{
		Ice ice;
		Cure cure;
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(&ice);
		src->learnMateria(&cure);
		ICharacter *me = new Character("me");
		AMateria *tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter *bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	std::cout << "\n================= General Logic Flow test =====================\n\n";
	{
		const unsigned int materiasCount = 5;
		AMateria *materias[materiasCount];
		Ice ice;
		Cure cure;
		IMateriaSource *src = new MateriaSource();
		ICharacter *me = new Character("me");
		ICharacter *bob = new Character("bob");
		std::cout << "[Learning materias by src] :\n";
		for (size_t i = 0; i < materiasCount; i++)
			if (i % 2 == 0)
				src->learnMateria(&ice);
			else
				src->learnMateria(&cure);
		std::cout << "[Creating materias by src] :\n";
		for (size_t i = 0; i < materiasCount; i++)
			materias[i] = src->createMateria(i % 2 == 0 ? "ice" : "cure");
		std::cout << "[Using materias without equiping] :\n";
		for (size_t i = 0; i < materiasCount; i++)
			me->use(i, *bob);
		std::cout << "[Equiping " << materiasCount << " materias] :\n";
		for (size_t i = 0; i < materiasCount; i++)
			me->equip(materias[i]);
		std::cout << "[Using materias from idx 0 to " << materiasCount << "] :\n";
		for (size_t i = 0; i < materiasCount; i++)
			me->use(i, *bob);
		std::cout << "[Unequipping materias from idx 0 to " << materiasCount << "] :\n";
		for (size_t i = 0; i < materiasCount; i++)
			me->unequip(i);
		std::cout << "[Deleting materias] :\n";
		for (size_t i = 0; i < materiasCount; i++)
			delete materias[i];
		delete bob;
		delete me;
		delete src;
	}
	return 0;
}