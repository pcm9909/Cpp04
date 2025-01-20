#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{

    Cat *a = new Cat();
    a->getBrain()->setIdeas(0, "I am a cat");

    Cat b = *a;
    b.getBrain()->setIdeas(0, "I am a dog");

    std::cout << a->getBrain()->getIdeas()[0] << std::endl;
    std::cout << b.getBrain()->getIdeas()[0] << std::endl;

    delete a;
    return 0;
}