#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
	this->type = type;
	std::cout << typeid(this).name() << " 생성자 호출" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << typeid(this).name() << " 소멸자 호출" << std::endl;
}

std::string const &AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}