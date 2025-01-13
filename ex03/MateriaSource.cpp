#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << typeid(this).name() << " 생성자 호출" << std::endl;
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
	count = 0;
}

MateriaSource::~MateriaSource()
{
	std::cout << typeid(this).name() << " 소멸자 호출" << std::endl;
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
	if(count < 4)
	{
		for (int i = 0; i < 4; i++)
		{
			if (materias[i] != NULL && materias[i]->getType() == type)
			{
				return materias[i]->clone();
			}
		}
	}
	return NULL;
}