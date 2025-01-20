/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chunpark <chunpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:36:21 by sejjeong          #+#    #+#             */
/*   Updated: 2025/01/20 23:12:29 by chunpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


void test42();
void testDeepCopiedCat();
void testDeepCopiedDog();

int main(void)
{
    test42();
    std::cout << std::endl;
    std::cout << std::endl;

    testDeepCopiedCat();
    std::cout << std::endl;
    std::cout << std::endl;

    testDeepCopiedDog();
    std::cout << std::endl;
    std::cout << std::endl;

     std::cout << "--------array Test!!!------" << std::endl;

    Animal* animals[16];
    for (int i = 0; i < 8; ++i)
    {
        std::cout << "i :" << i << std::endl;
        animals[i] = new Cat();
    }
    for (int i = 8; i < 16; ++i)
    {
        std::cout << "i :" << i << std::endl;
        animals[i] = new Dog();
    }

    for (int i = 0; i < 16; ++i)
    {
        delete animals[i];
    }
}

void test42()
{
    const Animal* j = new Dog();
    const Animal* k = new Cat();

    delete j;
    delete k;
}

void testDeepCopiedCat()
{
    std::cout << "--------Cat Test!!!------" << std::endl;

    Cat* newCat1 = new Cat();

    std::cout << "--------deep copy Test!!!------" << std::endl;
    std::cout << "." << std::endl;
    std::cout << "." << std::endl;
    std::cout << "." << std::endl;

    std::cout << "newCat1->idea 1 : " << newCat1->getIdeas(1) << std::endl;


	// no idea
	newCat1->setIdeas(0,"oh... amazing");
    newCat1->setIdeas(1,"oh......... amazing2");
    std::cout << "newCat1->idea 0 : " << newCat1->getIdeas(0) << std::endl;
    std::cout << "newCat1->idea 1 : " << newCat1->getIdeas(1) << std::endl;

    Cat copyCat(*newCat1);   // create

    std::cout << "copyCat->idea 1 : " << copyCat.getIdeas(1) << std::endl;
    copyCat.setIdeas(2,"oh...,,,,,,, amazing3");
    copyCat.setIdeas(3,"oh.........,,,,, amazing4");
    std::cout << "copyCat->idea 0 : " << copyCat.getIdeas(0) << std::endl;
    std::cout << "copyCat->idea 1 : " << copyCat.getIdeas(1) << std::endl;
    std::cout << "copyCat->idea 2 : " << copyCat.getIdeas(2) << std::endl;
    std::cout << "copyCat->idea 3 : " << copyCat.getIdeas(3) << std::endl;


    std::cout << "newCat1->idea 2 : " << newCat1->getIdeas(2) << std::endl;
    std::cout << "newCat1->idea 3 : " << newCat1->getIdeas(3) << std::endl;
    newCat1->setIdeas(4,"oh...;;; amazing5");
    newCat1->setIdeas(5,"oh.........;;;;; amazing6");
    std::cout << "newCat1->idea 2 : " << newCat1->getIdeas(2) << std::endl;
    std::cout << "newCat1->idea 3 : " << newCat1->getIdeas(3) << std::endl;

    Cat copyCat1;
    copyCat1 = *newCat1;
    std::cout << "copyCat1->idea 0 : " << copyCat1.getIdeas(0) << std::endl;
    std::cout << "copyCat1->idea 1 : " << copyCat1.getIdeas(1) << std::endl;
    std::cout << "copyCat1->idea 2 : " << copyCat1.getIdeas(2) << std::endl;
    std::cout << "copyCat1->idea 3 : " << copyCat1.getIdeas(3) << std::endl;


    std::cout << "--------destroy!!!------" << std::endl;
    std::cout << "." << std::endl;
    std::cout << "." << std::endl;
    std::cout << "." << std::endl;


    delete newCat1;
}

void testDeepCopiedDog()
{
    std::cout << "--------Dog Test!!!------" << std::endl;

    Dog* newDog1 = new Dog();

    std::cout << "--------deep copy Test!!!------" << std::endl;
    std::cout << "." << std::endl;
    std::cout << "." << std::endl;
    std::cout << "." << std::endl;

    std::cout << "newDog1->idea 1 : " << newDog1->getIdeas(1) << std::endl;
    newDog1->setIdeas(0, "new dog1 - 1");
    newDog1->setIdeas(1, "new dog1 - 2");
    std::cout << "newDog1->idea 0 : " << newDog1->getIdeas(0) << std::endl;
    std::cout << "newDog1->idea 1 : " << newDog1->getIdeas(1) << std::endl;

    Dog copyDog(*newDog1);   // create

    std::cout << "copyDog->idea 1 : " << copyDog.getIdeas(1) << std::endl;
    copyDog.setIdeas(0,"copy dog add 1");
    copyDog.setIdeas(1,"copy dog add 2");
    std::cout << "copyDog->idea 0 : " << copyDog.getIdeas(0) << std::endl;
    std::cout << "copyDog->idea 1 : " << copyDog.getIdeas(1) << std::endl;
    std::cout << "copyDog->idea 2 : " << copyDog.getIdeas(2) << std::endl;
    std::cout << "copyDog->idea 3 : " << copyDog.getIdeas(3) << std::endl;

    std::cout << "newDog1->idea 2 : " << newDog1->getIdeas(2) << std::endl;
    std::cout << "newDog1->idea 3 : " << newDog1->getIdeas(3) << std::endl;
    newDog1->setIdeas(2,"new dog1 - 3");
    newDog1->setIdeas(3,"new dog1 - 4");
    std::cout << "newDog1->idea 2 : " << newDog1->getIdeas(2) << std::endl;
    std::cout << "newDog1->idea 3 : " << newDog1->getIdeas(3) << std::endl;

    std::cout << "copyDog->idea 4 : " << copyDog.getIdeas(4) << std::endl;
    std::cout << "copyDog->idea 5 : " << copyDog.getIdeas(5) << std::endl;

    Dog copyDog1;
    copyDog1 = *newDog1;
    std::cout << "copyDog1->idea 0 : " << copyDog1.getIdeas(0) << std::endl;
    std::cout << "copyDog1->idea 1 : " << copyDog1.getIdeas(1) << std::endl;
    std::cout << "copyDog1->idea 2 : " << copyDog1.getIdeas(2) << std::endl;
    std::cout << "copyDog1->idea 3 : " << copyDog1.getIdeas(3) << std::endl;
    std::cout << "copyDog1->idea 4 : " << copyDog1.getIdeas(4) << std::endl;

    std::cout << "--------destroy!!!------" << std::endl;
    std::cout << "." << std::endl;
    std::cout << "." << std::endl;
    std::cout << "." << std::endl;

    delete newDog1;
}
