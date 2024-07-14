#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : type(type)
{
}
AMateria::AMateria(const AMateria &materia) : type(materia.type)
{
}
AMateria &AMateria::operator=(const AMateria &materia)
{
	if (this == &materia)
		return *this;
	type = materia.type;
	return *this;
}
AMateria::~AMateria()
{}
std::string const &AMateria::getType() const
{
	return type;
}
