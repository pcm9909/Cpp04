#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	Animal *meta[10];

	for (int i = 0; i < 5; i++) {
		meta[i] = new Dog();
	}

	for (int i = 5; i < 10; i++) {
		meta[i] = new Cat();
	}

	Cat a;
	Cat b;
	a.getBrain()->setIdeas(1, "a");
	b.getBrain()->setIdeas(1, "b");


	a = b;
	std::cout << "after deep copy execution." << std::endl;
	const std::string *a_ideas = a.getBrain()->getIdeas();
	std::cout << "a: " << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << a_ideas[i];
	}
	std::cout << std::endl;

	const std::string *b_ideas = b.getBrain()->getIdeas();
	std::cout << "b: " << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << b_ideas[i];
	}
	std::cout << std::endl;

	a.getBrain()->setIdeas(1, "c");
	std::cout << "after changed one`s data" << std::endl;
	a_ideas = a.getBrain()->getIdeas();
	std::cout << "a: " << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << a_ideas[i];
	}
	std::cout << std::endl;

	b_ideas = b.getBrain()->getIdeas();
	std::cout << "b: " << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << b_ideas[i];
	}
	std::cout << std::endl;

	for (int i = 0; i < 10; i++) {
		delete meta[i];
	}
	return 0;
}