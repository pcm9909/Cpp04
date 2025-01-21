#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* materias[4];
		std::string name[4];
		int count;
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource &ms);
		MateriaSource &operator=(const MateriaSource &ms);

		void learnMateria(AMateria *m);
		AMateria *createMateria(std::string const &type);
};

#endif