#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << typeid(this).name() << " constructor called!" << std::endl;
}

Dog::~Dog()
{
	std::cout << typeid(this).name() << " destructor called!" << std::endl;
}

Dog::Dog(const Dog &dog)
{
	std::cout << typeid(this).name() << " Copy Constructor called" << std::endl;
	*this = dog;
}
Dog &Dog::operator=(const Dog &dog)
{
	if(this != &dog)
	{
		this->type = getType();
		std::cout << typeid(this).name() << " Assignation Operator called" << std::endl;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "bow-wow" << std::endl;
}