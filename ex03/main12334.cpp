/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_03.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <chunpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 21:05:40 by sejjeong          #+#    #+#             */
/*   Updated: 2025/01/13 17:00:47 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
// #include "Floor.hpp"

void test42();
void testCharacter();
void testUnequip();
void testCopiedCharacter();

void testMateriaSource();
void testCopiedSource();

int main(void)
{
    // test42();
    testCharacter();
    // testMateriaSource();

    //Floor::destroyInstance();
    return 0;
}

void test42()
{
    std::cout << "--------------- 42 Test !!! -------------------" << std::endl;
    std::cout << "..." << std::endl;
    std::cout << "..." << std::endl;
    std::cout << "..." << std::endl;

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
}

void testCharacter()
{
    // std::cout << "--------------- Character Test !!! -------------------" << std::endl;
    // std::cout << "..." << std::endl;
    // std::cout << "..." << std::endl;
    // std::cout << "..." << std::endl;

    // Character human("sejin");
    // ICharacter* sejjeong = new Character("sejjeong");

    // std::cout << "-----------equip Test" << std::endl;
    // std::cout << ".." << std::endl;

    // std::cout << "empty slot use(all) " << std::endl;
    // std::cout << "." << std::endl;
    // for (int i = 0; i < 4; ++i)
    // {
    //     human.use(i, *sejjeong);
    // }

    // std::cout << "." << std::endl;
    // std::cout << "equip(ice) -> use(0)" << std::endl;
    // std::cout << "." << std::endl;

    // human.equip(new Ice());
    // human.use(0, *sejjeong);

    // std::cout << "." << std::endl;

    // std::cout << "equip(ice) -> use(1)" << std::endl;
    // std::cout << "." << std::endl;

    // human.equip(new Ice());
    // human.use(1, *sejjeong);

    // std::cout << "." << std::endl;

    // std::cout << "equip(Cure) -> use(0) -> use(2) -> use(3)" << std::endl;
    // std::cout << "." << std::endl;

    // human.equip(new Cure());
    // human.use(0, *sejjeong);
    // human.use(2, *sejjeong);
    // human.use(3, *sejjeong);

    // std::cout << "." << std::endl;

    // std::cout << "equip(Cure) -> use(All)" << std::endl;
    // std::cout << "." << std::endl;

    // human.equip(new Cure());
    // for (int i = 0; i < 4; ++i)
    // {
    //     human.use(i, *sejjeong);
    // }

    // std::cout << "." << std::endl;

    // std::cout << "use(4, 5, 6)" << std::endl;
    // std::cout << "." << std::endl;
    // human.use(4, *sejjeong);
    // human.use(5, *sejjeong);
    // human.use(6, *sejjeong);
    // std::cout << "." << std::endl;

    // std::cout << ".." << std::endl;
    // std::cout << "--------------- more Materia" << std::endl;
    // std::cout << ".." << std::endl;

    // std::cout << "equip(ice) x 3 -> use(All)" << std::endl;
    // std::cout << "." << std::endl;
    // Ice* ice = new Ice();
    // human.equip(ice);
    // Ice* ice2 = new Ice();
    // human.equip(ice2);
    // Ice* ice3 = new Ice();
    // human.equip(ice3);

    // for (int i = 0; i < 4; ++i)
    // {
    //     human.use(i, *sejjeong);
    // }
    // std::cout << "." << std::endl;
    // std::cout << ".." << std::endl;
    // delete ice;
    // delete ice2;
    // delete ice3;


    // delete sejjeong;
    testUnequip();
    // testCopiedCharacter();
    std::cout << "..." << std::endl;
    std::cout << "..." << std::endl;
    std::cout << "..." << std::endl;
}

void testUnequip()
{
    std::cout << "--------------- unequip test" << std::endl;
    std::cout << ".." << std::endl;

    Character human("newSejin");
    ICharacter* sejjeong = new Character("newSejjeong");

    std::cout << "unequip(All)" << std::endl;
    std::cout << "." << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        human.unequip(i);
    }
    std::cout << "." << std::endl;

    std::cout << "equip(All) -> use(All) -> unequip(All) -> use(All)" << std::endl;
    std::cout << "." << std::endl;
    human.equip(new Cure());
    human.equip(new Cure());
    human.equip(new Cure());
    human.equip(new Ice());

    for (int i = 0; i < 4; ++i)
    {
        human.use(i, *sejjeong);
    }

    for (int i = 0; i < 4; ++i)
    {
        human.unequip(i);
    }

    for (int i = 0; i < 4; ++i)
    {
        human.use(i, *sejjeong);
    }
    std::cout << "." << std::endl;
    std::cout << "equip(all)-> unequip(1) -> unequip(3) -> use(All)" << std::endl;
    std::cout << "." << std::endl;

    human.equip(new Cure());
    human.equip(new Cure());
    human.equip(new Cure());
    human.equip(new Ice());
    human.unequip(1);
    human.unequip(3);
    for (int i = 0; i < 4; ++i)
    {
        human.use(i, *sejjeong);
    }

    std::cout << ".." << std::endl;
    delete sejjeong;
}

void testCopiedCharacter()
{
    std::cout << "--------------- copied character test" << std::endl;
    std::cout << ".." << std::endl;

    Character human("Sejins");
    ICharacter* sejjeong = new Character("Sejjeongs");

    std::cout << "human.equip(cure, cure) ->use(All)" << std::endl;
    std::cout << "." << std::endl;

    human.equip(new Cure());
    human.equip(new Cure());

    for (int i = 0; i < 4; ++i)
    {
        human.use(i, *sejjeong);
    }
    std::cout << "." << std::endl;

    std::cout << "copied human2.equip(ice, ice) ->use(All)" << std::endl;
    std::cout << "." << std::endl;

    Character human2(human);
    human2.equip(new Ice());
    human2.equip(new Ice());

    for (int i = 0; i < 4; ++i)
    {
        human2.use(i, *sejjeong);
    }
    std::cout << "." << std::endl;

    std::cout << "copied human2.unequip(1, 3) ->  human2.use(All)" << std::endl;
    std::cout << "." << std::endl;

    human2.unequip(1);
    human2.unequip(3);

    for (int i = 0; i < 4; ++i)
    {
        human2.use(i, *sejjeong);
    }
    std::cout << "." << std::endl;

    std::cout << "human.use(All)" << std::endl;
    std::cout << "." << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        human.use(i, *sejjeong);
    }
    std::cout << "." << std::endl;

    std::cout << "human2.unequip(0) -> equip(ice, cure) -> human2.use(All)" << std::endl;
    std::cout << "." << std::endl;

    human2.unequip(0);
    human2.equip(new Ice());
    human2.equip(new Cure());

    for (int i = 0; i < 4; ++i)
    {
        //std::cout << i << std::endl;
        human2.use(i, *sejjeong);
    }


    std::cout << ".." << std::endl;

    // Character* human3 = new Character(human);
    // Character human4 = *human3;

    // for (int i = 0; i < 4; ++i)
    // {
    //     human3->use(i, *sejjeong);
    // }
    // delete human3;
    // for (int i = 0; i < 4; ++i)
    // {
    //     human4.use(i, *sejjeong);
    // }

    delete sejjeong;
}

void testMateriaSource()
{
    std::cout << "--------------- MateriaSource Test !!! -------------------" << std::endl;
    std::cout << "..." << std::endl;
    std::cout << "..." << std::endl;
    std::cout << "..." << std::endl;

    IMateriaSource* src = new MateriaSource();

    std::cout << "--------------- learn, create" << std::endl;
    std::cout << ".." << std::endl;


    std::cout << "not learn cure, learn ice -> create cure, ice -> equip -> use(All)" << std::endl;
    std::cout << "." << std::endl;
    src->learnMateria(new Ice());

    ICharacter* me = new Character("me");
    ICharacter* sejjeong = new Character("Sejjeongs");

    AMateria* tmp;
    tmp = src->createMateria("cure");
    if (tmp != 0)
    {
        std::cout << "find materia 1" << std::endl;
        me->equip(tmp);
    }
    tmp = src->createMateria("ice");
    if (tmp != 0)
    {
        std::cout << "retry find materia" << std::endl;
        me->equip(tmp);
    }

    for (int i = 0; i < 4; ++i)
    {
        me->use(i, *sejjeong);
    }

    std::cout << "." << std::endl;

    std::cout << "learn cure, learn ice -> create cure -> equip -> use(All)" << std::endl;
    std::cout << "." << std::endl;


    src->learnMateria(new Cure());
    tmp = src->createMateria("cure");
    if (tmp != 0)
    {
        std::cout << "retry find cure materia" << std::endl;
        me->equip(tmp);
    }

    for (int i = 0; i < 4; ++i)
    {
        me->use(i, *sejjeong);
    }

    std::cout << "." << std::endl;
    std::cout << ".." << std::endl;
    delete me;
    delete src;
    delete sejjeong;

    testCopiedSource();
}

void testCopiedSource()
{
    std::cout << "--------------- copied source test" << std::endl;
    std::cout << ".." << std::endl;


    MateriaSource src;

    src.learnMateria(new Cure());

    AMateria* tmp;

    tmp = src.createMateria("cure");
    if (tmp == 0)
    {
        std::cout << "src not found materia" << std::endl;
    }
    delete tmp;

    MateriaSource src2(src);
    tmp = src2.createMateria("cure");
    if (tmp == 0)
    {
        std::cout << "src2 not found materia" << std::endl;
    }
    delete tmp;

    tmp = src2.createMateria("ice");
    if (tmp == 0)
    {
        std::cout << "src2 not found ice" << std::endl;
    }

    src.learnMateria(new Ice());

    tmp = src.createMateria("ice");
    if (tmp == 0)
    {
        std::cout << "src not found ice" << std::endl;
    }
    delete tmp;

    tmp = src2.createMateria("ice");
    if (tmp == 0)
    {
        std::cout << "src2 not found ice" << std::endl;
    }

    std::cout << "." << std::endl;
    std::cout << "all Cure learn -> ice learn " << std::endl;
    std::cout << "." << std::endl;


    src2.learnMateria(new Cure());
    src2.learnMateria(new Cure());
    src2.learnMateria(new Cure());
    AMateria* temp = new Ice();
    src2.learnMateria(temp);
    tmp = src2.createMateria("ice");
    if (tmp == 0)
    {
        std::cout << "src2 not found ice, last" << std::endl;
    }
    delete temp;
    std::cout << "." << std::endl;
    std::cout << ".." << std::endl;
}
