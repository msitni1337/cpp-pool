#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}
Ice::Ice(const Ice &ice) : AMateria("ice")
{
	(void) ice;
}
Ice &Ice::operator=(const Ice &ice)
{
	(void) ice;
	return *this;
}
Ice::~Ice()
{
}
AMateria *Ice::clone() const
{
	Ice* ice = new Ice();
	return ice;
}
void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() <<" *\n";
}