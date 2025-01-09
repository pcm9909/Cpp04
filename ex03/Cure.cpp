#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	this->type = "cure";
	std::cout << typeid(this).name() << " 생성자 호출" << std::endl;
}

Cure::~Cure()
{
	std::cout << typeid(this).name() << " 소멸자 호출" << std::endl;
}

Cure::Cure(const Cure& cure) : AMateria(cure)
{
	std::cout << typeid(this).name() << " Cure 복사 생성자 호출" << std::endl;
}

Cure& Cure::operator=(const Cure& cure)
{
	AMateria::operator=(cure);
	std::cout << typeid(this).name() << " 대입 연산자 호출" << std::endl;
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