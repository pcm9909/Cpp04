#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
#include <typeinfo>
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

#endif