// #include "AMateria.hpp"
// #include "Character.hpp"
// #include "MateriaSource.hpp"
// #include "Ice.hpp"
// #include "Cure.hpp"

// using namespace std;

// void subjectTest(void){
// 	std::cout << "Subject Test START" << std::endl;
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	delete bob;
// 	delete me;
// 	delete src;
// 	std::cout << "Subject Test START" << std::endl << std::endl;
// }
// int main(void){
// 	subjectTest();
// 	return 0;
// }


#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include <iostream>

int main() {
    // {
    //     std::cout << "1. subject testcase" << std::endl;
    //     IMateriaSource *src = new MateriaSource();
    //     src->learnMateria(new Ice());
    //     src->learnMateria(new Cure());

    //     ICharacter *me = new Character("me");

    //     AMateria* tmp;
    //     tmp = src->createMateria("ice");
    //     me->equip(tmp);

    //     tmp = src->createMateria("cure");
    //     me->equip(tmp);

    //     ICharacter* bob = new Character("bob");

    //     me->use(0, *bob);
    //     me->use(1, *bob);

    //     delete bob;
    //     delete me;
    //     delete src;

    //     std::cout << std::endl;
    // }

    // {
    //     std::cout << "2. test MateriaSource & Character inventory overflow" << std::endl;
    //     IMateriaSource *src = new MateriaSource();
    //     src->learnMateria(new Ice());
    //     src->learnMateria(new Cure());
    //     src->learnMateria(new Cure());
    //     src->learnMateria(new Cure());
    //     src->learnMateria(new Cure());

    //     ICharacter *me = new Character("me");
    //     AMateria* tmp;
    //     tmp = src->createMateria("ice");
    //     me->equip(tmp);
	// 	tmp = src->createMateria("ice");
    //     me->equip(tmp);
    //     tmp = src->createMateria("cure");
    //     me->equip(tmp);
    //     tmp = src->createMateria("cure");
    //     me->equip(tmp);
    //     tmp = src->createMateria("ice");
    //     me->equip(tmp);

    //     delete src;
    //     delete me;
    //     std::cout << std::endl;
    // }

    {
        std::cout << "3. if somebody try to unequip empty slot " << std::endl;
        IMateriaSource *src = new MateriaSource();
        src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
        ICharacter *me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        tmp = src->createMateria("ice");
        me->unequip(1);
        me->unequip(2);
        me->unequip(3);
		me->unequip(3);
        me->unequip(3);
        me->unequip(3);
        me->unequip(3);
        me->unequip(3);


        delete src;
        delete me;

        std::cout << std::endl;
    }

    return 0;
}
