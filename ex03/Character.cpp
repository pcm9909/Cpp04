#include "Character.hpp"

Character::Character(std::string name)
{
	std::cout << typeid(this).name() << " 생성자 호출" << std::endl;
    this->name = name;
    for (int i = 0; i < 4; i++)
        materias[i] = NULL;
}

Character::~Character()
{
	std::cout << typeid(this).name() << " 소멸자 호출" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (materias[i] != NULL)
		{
            delete materias[i];
			materias[i] = NULL;
		}
    }
}

Character::Character(const Character &character)
{
    this->name = character.name;
    for (int i = 0; i < 4; i++)
    {
        if (character.materias[i] != NULL)
            materias[i] = character.materias[i]->clone();
        else
            materias[i] = NULL;
    }
}

Character &Character::operator=(const Character &character)
{
    this->name = character.name;
    for (int i = 0; i < 4; i++)
    {
        if (materias[i] != NULL)
            delete materias[i];
        if (character.materias[i] != NULL)
            materias[i] = character.materias[i]->clone();
        else
            materias[i] = NULL;
    }
    return *this;
}

std::string const &Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (materias[i] == NULL)
        {
            materias[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if ((idx >= 0 && idx < 4) )
	{
		delete materias[idx];
        materias[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && materias[idx] != NULL)
        materias[idx]->use(target);
}