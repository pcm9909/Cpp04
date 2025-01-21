#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	this->type = "cure";
}

Cure::~Cure()
{
}

Cure::Cure(const Cure& cure) : AMateria(cure)
{
}

Cure& Cure::operator=(const Cure& cure)
{
	AMateria::operator=(cure);
	return *this;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}