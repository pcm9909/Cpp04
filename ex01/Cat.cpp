#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << typeid(*this).name() << " constructor called!" << std::endl;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << typeid(*this).name() << " destructor called!" << std::endl;
}

Cat::Cat(const Cat &cat)
{
	std::cout << typeid(*this).name() << " Copy Constructor called" << std::endl;
	this->brain = new Brain(*(cat.brain));
	this->type = cat.type;
}

Cat &Cat::operator=(const Cat& cat)
{
	std::cout << typeid(*this).name() << " Assignation Operator called" << std::endl;
	if (this != &cat)
	{
		delete this->brain;
		this->brain = new Brain(*(cat.brain));
		this->type = cat.type;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

Brain* Cat::getBrain()
{
	return brain;
}