#include "AMateria.hpp"

class Cure : public AMateria
{
private:
public:
	Cure();
	Cure(const Cure& ice);
	Cure& operator=(const Cure& ice);
	~Cure();
	AMateria *clone() const;
	void use(ICharacter &target);
};