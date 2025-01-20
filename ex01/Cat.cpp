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

Cat::Cat(const Cat &dog)
{
	std::cout << typeid(*this).name() << " Copy Constructor called" << std::endl;
	this->brain = new Brain(*dog.brain);
	this->type = dog.type;
}

Cat &Cat::operator=(const Cat &dog)
{
	std::cout << typeid(*this).name() << " Assignation Operator called" << std::endl;
	if (this != &dog)
	{
		delete this->brain;
		this->brain = new Brain(*dog.brain);
		this->type = dog.type;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

std::string Cat::getIdeas(int i)
{
	return brain->ideas[i];
}

void Cat::setIdeas(int index, std::string str)
{
	if(this->brain->ideas[index].empty())
	{
		this->brain->ideas[index] = str;
	}
	else
	{
		std::cout << "already in use !" << std::endl;
	}
}