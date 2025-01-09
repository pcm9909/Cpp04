#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << typeid(this).name() << " 생성자 호출" << std::endl;
}

Ice::~Ice()
{
	std::cout << typeid(this).name() << " 소멸자 호출" << std::endl;
}

Ice::Ice(const Ice &ice) : AMateria(ice)
{
	std::cout << typeid(this).name() << " 복사 생성자 호출" << std::endl;
}

Ice &Ice::operator=(const Ice &ice)
{
	AMateria::operator=(ice);
	std::cout << typeid(this).name() << " 대입연산자 호출" << std::endl;
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