#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria *) = 0;					  // Materia 학습
		virtual AMateria *createMateria(std::string const &type) = 0; // Materia 생성
};

#endif