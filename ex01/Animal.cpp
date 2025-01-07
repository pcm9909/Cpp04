#include "Animal.hpp"

Animal::Animal()
{
	std::cout << typeid(this).name() << " constructor called!" << std::endl;
}

Animal::~Animal()
{
	std::cout << typeid(this).name() << " destructor called!" << std::endl;
}

Animal::Animal(const Animal &animal)
{
	std::cout << typeid(this).name() << " Copy Constructor called" << std::endl;
	*this = animal;
}
Animal &Animal::operator=(const Animal &animal)
{
	if(this != &animal)
	{
		this->type = getType();
		std::cout << typeid(this).name() << " Assignation Operator called" << std::endl;
	}
	return *this;
}

std::string Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << "can't make a sound !" << std::endl;
}