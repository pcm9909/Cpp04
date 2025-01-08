#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
public:
    Character(std::string name);
    ~Character();
    Character(const Character &character);
    Character &operator=(const Character &character);

    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
};

Character::Character(std::string name)
{
    this->name = name;
    for (int i = 0; i < 4; i++)
        materias[i] = NULL;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (materias[i] != NULL)
            delete materias[i];
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
    if (idx >= 0 && idx < 4)
        materias[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && materias[idx] != NULL)
        materias[idx]->use(target);
}

#endif