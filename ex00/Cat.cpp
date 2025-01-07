#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << typeid(this).name() << " constructor called!" << std::endl;
}

Cat::~Cat()
{
	std::cout << typeid(this).name() << " destructor called!" << std::endl;
}

Cat::Cat(const Cat &cat)
{
	std::cout << typeid(this).name() << " Copy Constructor called" << std::endl;
	*this = cat;
}
Cat &Cat::operator=(const Cat &cat)
{
	if(this != &cat)
	{
		this->type = getType();
		std::cout << typeid(this).name() << " Assignation Operator called" << std::endl;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}