// Brain.cpp
#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << typeid(*this).name() << " constructor called!" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << typeid(*this).name() << " Copy Constructor called" << std::endl;
	*this = other;
}

Brain::~Brain()
{
	std::cout << typeid(*this).name() << " destructor called!" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for(int i = 0; i < 100; i++)
		{
			this->ideas[i] = other.ideas[i];
		}
	}
	std::cout << typeid(*this).name() << " Assignation Operator called" << std::endl;
	return *this;
}

std::string Brain::getIdeas(int i)
{
	return ideas[i];
}

void Brain::setIdeas(int index, std::string str)
{
	ideas[index] = str;
}