#ifndef MATERIALIST_HPP
# define MATERIALIST_HPP

#include "AMateria.hpp"

class MateriaList
{
    public:
        AMateria* content;
        MateriaList* next;
        MateriaList* prev;

        MateriaList(AMateria* materia);
        ~MateriaList();
		MateriaList(const MateriaList &MateriaList);
		MateriaList &operator=(const MateriaList &ml);
};

#endif