#include "Character.hpp"

Character::Character(std::string name)
{
    this->name = name;
	this->m = NULL;
    for(int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] != NULL)
		{
            delete inventory[i];
			inventory[i] = NULL;
		}
    }
	deleteAll(this->m);

}

Character::Character(const Character &character)
{
    this->name = character.name;
    for (int i = 0; i < 4; i++)
    {
        if (character.inventory[i] != NULL)
            inventory[i] = character.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
}

Character &Character::operator=(const Character &character)
{
    this->name = character.name;
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] != NULL)
            delete inventory[i];
        if (character.inventory[i] != NULL)
            inventory[i] = character.inventory[i]->clone();
        else
            inventory[i] = NULL;
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
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
			std::cout << "Equip success" << std::endl;
            break;
        }
		if(i == 5)
		{
			std::cout << "inventory Full" <<std::endl;
		}
    }
}

void Character::unequip(int idx)
{
    if ((idx >= 0 && idx < 4) && inventory[idx] != NULL)
	{
		std::cout << "[UNEQUIP] " << this->name[idx] <<std::endl;
		MateriaList *node = new MateriaList(inventory[idx]);
		node->prev = this->m;
		this->m->next = node;
		this->m = node;
        inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && inventory[idx] != NULL)
	{
        inventory[idx]->use(target);
	}
	else
		std::cout << "can't find use" << std::endl;
}

void Character::deleteAll(MateriaList* head) {
    MateriaList* current = head;
    MateriaList* nextNode;

    while (current)
	{
		std::cout << "called" << std::endl;
        nextNode = current->prev;
        delete current;
        current = nextNode;
    }
}