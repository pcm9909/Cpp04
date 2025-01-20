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
		delete this->brain;
		this->brain = new Brain();
		for (int i = 0; i < 100; ++i)
		{
			this->brain->ideas[i] = cat.brain->ideas[i];
		}
		this->type = getType();
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