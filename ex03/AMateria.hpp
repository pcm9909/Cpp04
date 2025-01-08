#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string type;
public:
	AMateria(std::string const &type);
	virtual ~AMateria();				  // 가상 소멸자 추가
	std::string const &getType() const;	  // Materia 타입을 반환
	virtual AMateria *clone() const = 0;  // 순수 가상 함수
	virtual void use(ICharacter &target); // Materia 사용
};

AMateria::AMateria(std::string const &type)
{
	this->type = type;
}

AMateria::~AMateria()
{
}

std::string const &AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}

#endif