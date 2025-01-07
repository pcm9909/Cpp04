#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << typeid(this).name() << " constructor called!" << std::endl;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << typeid(this).name() << " destructor called!" << std::endl;
}

Cat::Cat(const Cat &cat)
{
	std::cout << typeid(this).name() << " Copy Constructor called" << std::endl;
	*this = cat;
}
Cat &Cat::operator=(const Cat &cat)
{
	std::cout << typeid(this).name() << " Assignation Operator called" << std::endl;
	if(this != &cat)
	{
		this->brain = new Brain();
		this->type = getType();
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}