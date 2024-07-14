#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
}
Cure::Cure(const Cure &cure) : AMateria("cure")
{
	(void)cure;
}
Cure &Cure::operator=(const Cure &cure)
{
	(void)cure;
	return *this;
}
Cure::~Cure()
{
}
AMateria *Cure::clone() const
{
	Cure * cure = new Cure();
	return cure;
}
void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}