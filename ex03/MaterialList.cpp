#include "MateriaList.hpp"

MateriaList::MateriaList(const MateriaList &ml) { *this = ml; }

MateriaList::MateriaList(AMateria* materia) : content(materia), next(NULL), prev(NULL) {}

MateriaList::~MateriaList() { delete content; }

MateriaList &MateriaList::operator=(const MateriaList &ml)
{
	if (this != &ml)
	{
		this->prev = ml.prev;
		this->next = ml.next;
		this->content = ml.content;
	}
    return *this;
}