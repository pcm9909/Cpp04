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

class MateriaSource : public IMateriaSource
{
private:
	AMateria *materias[4];
	int count;

public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource &ms);
	MateriaSource &operator=(const MateriaSource &ms);

	void learnMateria(AMateria *m);
	AMateria *createMateria(std::string const &type);
};

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
	count = 0;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (materias[i] != NULL)
			delete materias[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource &ms)
{
	for (int i = 0; i < 4; i++)
	{
		if (ms.materias[i] != NULL)
			materias[i] = ms.materias[i]->clone();
		else
			materias[i] = NULL;
	}
	count = ms.count;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &ms)
{
	for (int i = 0; i < 4; i++)
	{
		if (materias[i] != NULL)
			delete materias[i];
		if (ms.materias[i] != NULL)
			materias[i] = ms.materias[i]->clone();
		else
			materias[i] = NULL;
	}
	count = ms.count;
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (count < 4)
	{
		materias[count] = m;
		count++;
	}
	else
		delete m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (materias[i] != NULL && materias[i]->getType() == type)
			return materias[i]->clone();
	}
	return NULL;
}

#endif