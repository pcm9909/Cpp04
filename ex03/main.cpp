#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

using namespace std;

void subjectTest(void){
	std::cout << "Subject Test START" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	std::cout << "Subject Test START" << std::endl << std::endl;
}

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include <iostream>

int main()
{
	{
		subjectTest();
	}
    {
        std::cout << "1. subject testcase" << std::endl;
        IMateriaSource *src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter *me = new Character("me");

        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);

        tmp = src->createMateria("cure");
        me->equip(tmp);

        ICharacter* bob = new Character("bob");

        me->use(0, *bob);
        me->use(1, *bob);

        delete bob;
        delete me;
        delete src;

        std::cout << std::endl;
    }

    {
        std::cout << "2. test MateriaSource & Character inventory overflow" << std::endl;
        IMateriaSource *src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        src->learnMateria(new Cure());
        src->learnMateria(new Cure());
        src->learnMateria(new Cure());

        ICharacter *me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
		tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        tmp = src->createMateria("ice");
        me->equip(tmp);

        delete src;
        delete me;
        std::cout << std::endl;
    }

    {
        std::cout << "3. if somebody try to unequip empty slot " << std::endl;
        IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
        ICharacter *me = new Character("me");
		AMateria* tmp;
		ICharacter *bob = new Character("bob");
		tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        tmp = src->createMateria("cure");
		me->use(11, *bob);
		me->equip(tmp);
        me->unequip(1);
        me->unequip(2);
        me->unequip(3);
		me->unequip(3);
        me->unequip(0);
        me->unequip(3);
        me->unequip(3);
        me->unequip(3);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		me->use(0, *bob);

		IMateriaSource *asd = new MateriaSource();
		Character a("hi");
		asd->learnMateria(new Cure());
		AMateria *qwe;

		qwe = asd->createMateria("cure");
		a.equip(qwe);
		a.use(0,*bob);
		a.unequip(0);

		delete bob;
        delete src;
        delete me;
		delete asd;

        std::cout << std::endl;
    }

    return 0;
}
