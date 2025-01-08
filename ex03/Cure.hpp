#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		~Cure();
		Cure(const Cure& cure);
		Cure& operator=(const Cure& cure);

		AMateria* clone() const;
		void use(ICharacter& target);
};

Cure::Cure() : AMateria("cure")
{
	this->type = "cure";
	std::cout << "Cure 생성" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure 소멸" << std::endl;
}

Cure::Cure(const Cure& cure) : AMateria(cure)
{
	std::cout << "Cure 복사 생성" << std::endl;
}

Cure& Cure::operator=(const Cure& cure)
{
	AMateria::operator=(cure);
	std::cout << "Cure 대입 연산" << std::endl;
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

#endif