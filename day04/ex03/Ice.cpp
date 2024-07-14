#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}
Ice::Ice(const Ice &ice) : AMateria("ice")
{
}
Ice &Ice::operator=(const Ice &ice)
{
	if (this == &ice)
		return *this;
	// Handle copyig logic
	return *this;
}
Ice::~Ice()
{
}
AMateria *Ice::clone() const
{
	Ice* ice = new Ice();
	// cloning logic
	return ice;
}
void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() <<" *\n";
}