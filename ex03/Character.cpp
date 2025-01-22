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
        if (inventory[i])
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
    if (character.m)
    {
        this->m = new MateriaList(*character.m);
        MateriaList *current = this->m;
        MateriaList *source = character.m->next;
        while (source)
        {
            current->next = new MateriaList(*source);
            current->next->prev = current;
            current = current->next;
            source = source->next;
        }
    }
    else
    {
        this->m = NULL;
    }
}

Character &Character::operator=(const Character &character)
{
    if (this != &character)
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
        deleteAll(this->m);
        if (character.m)
        {
            this->m = new MateriaList(*character.m);
            MateriaList *current = this->m;
            MateriaList *source = character.m->next;
            while (source)
            {
                current->next = new MateriaList(*source);
                current->next->prev = current;
                current = current->next;
                source = source->next;
            }
        }
        else
        {
            this->m = NULL;
        }
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
            std::cout << "[equip] Equip success" << std::endl;
            return;
        }
    }
    std::cout << "[equip] Inventory full" << std::endl;
    MateriaList *node = new MateriaList(m);
    if (this->m)
    {
        node->prev = this->m;
        this->m->next = node;
    }
    this->m = node;
}

void Character::unequip(int idx)
{
    if ((idx >= 0 && idx < 4) && inventory[idx] != NULL)
    {
        std::cout << "[UNEQUIP] unequip Materia" << std::endl;
        MateriaList *node = new MateriaList(inventory[idx]);
        if (this->m)
        {
            node->prev = this->m;
            this->m->next = node;
        }
        this->m = node;
        inventory[idx] = NULL;
    }
    else
    {
        std::cout << "[UNEQUIP] Fail to unequip Materia" << std::endl;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4)
    {
        if (inventory[idx] != NULL)
            inventory[idx]->use(target);
        else
            std::cout << "[use] inventory empty" << std::endl;
    }
    else
        std::cout << "[use] invalid idx num" << std::endl;
}

void Character::deleteAll(MateriaList* head) {
    MateriaList* current = head;
    MateriaList* nextNode;

    while (current)
    {
        nextNode = current->prev;
        delete current;
        current = nextNode;
    }
}