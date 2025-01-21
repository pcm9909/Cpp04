#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << typeid(*this).name() << " constructor called!" << std::endl;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << typeid(*this).name() << " destructor called!" << std::endl;
}

Dog::Dog(const Dog &dog)
{
	std::cout << typeid(*this).name() << " Copy Constructor called" << std::endl;
	this->brain = new Brain(*(dog.brain));
	this->type = dog.type;
}

Dog &Dog::operator=(const Dog& dog)
{
	std::cout << typeid(*this).name() << " Assignation Operator called" << std::endl;
	if (this != &dog)
	{
		delete this->brain;
		this->brain = new Brain(*(dog.brain));
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