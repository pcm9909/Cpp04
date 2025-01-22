#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		materias[i] = NULL;
		used[i] = 0;
	}
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
	if(!m)
	{
		std::cout <<"[learnMateria] invalid Materia!" << std::endl;
		return ;
	}
	for(int i = 0; i < 4; i++)
	{
		if(this->materias[i] == NULL)
		{
			std::cout <<"[learnMateria] learn Materia!" << i << std::endl;
			this->materias[i] = m;
			this->name[i] = m->getType();
			break;
		}
		if(i == 3)
		{
			std::cout << "[learnMateria] inventory full" << std::endl;
			delete m;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->name[i] == type && !this->used[i])
		{
			std::cout << "[Create Materia] Materia Created" << std::endl;
			this->used[i] = 1;
			return materias[i]->clone();
		}
	}
	std::cout << "[Create Materia] Fail to Create Materia" << std::endl;
	return NULL;
}