#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	~Ice();
	Ice(const Ice &ice);
	Ice &operator=(const Ice &ice);

	AMateria *clone() const;
	void use(ICharacter &target);
};

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice 생성" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice 소멸" << std::endl;
}

Ice::Ice(const Ice &ice) : AMateria(ice)
{
	std::cout << "Ice 복사 생성" << std::endl;
}

Ice &Ice::operator=(const Ice &ice)
{
	AMateria::operator=(ice);
	std::cout << "Ice 대입 연산" << std::endl;
	return *this;
}

AMateria *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

#endif