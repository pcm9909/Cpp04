#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << typeid(this).name() << " constructor called!" << std::endl;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << typeid(this).name() << " destructor called!" << std::endl;
}

Dog::Dog(const Dog &dog)
{
	std::cout << typeid(this).name() << " Copy Constructor called" << std::endl;
	*this = dog;
}
Dog &Dog::operator=(const Dog &dog)
{
	std::cout << typeid(this).name() << " Assignation Operator called" << std::endl;
	if(this != &dog)
	{
		this->brain = new Brain();
		this->type = getType();
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "bow-wow" << std::endl;
}