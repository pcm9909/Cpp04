// Dog.cpp
#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << typeid(*this).name() << " constructor called!" << std::endl;
}

Dog::~Dog()
{
	std::cout << typeid(*this).name() << " destructor called!" << std::endl;
}

Dog::Dog(const Dog &dog)
{
	std::cout << typeid(*this).name() << " Copy Constructor called" << std::endl;
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << typeid(*this).name() << " Assignation Operator called" << std::endl;
	if (this != &dog)
	{
		this->brain = new Brain(*dog.brain); // 깊은 복사 수행
		this->type = dog.type;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Bark" << std::endl;
}

Brain* Dog::getBrain()
{
	return brain;
}