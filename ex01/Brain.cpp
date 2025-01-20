// Brain.cpp
#include "Brain.hpp"
#include <iostream>

Brain::Brain() : refCount(new int(1))
{
	std::cout << typeid(*this).name() << " constructor called!" << std::endl;
}

Brain::Brain(const Brain &other) : ideas(), refCount(other.refCount)
{
	++(*refCount);
	std::cout << typeid(*this).name() << " Copy Constructor called" << std::endl;
}

Brain::~Brain()
{
	if (--(*refCount) == 0)
	{
		delete refCount;
		std::cout << typeid(*this).name() << " destructor called!" << std::endl;
	}
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		if (--(*refCount) == 0)
		{
			delete refCount;
		}
		refCount = other.refCount;
		++(*refCount);
	}
	std::cout << typeid(*this).name() << " Assignation Operator called" << std::endl;
	return *this;
}

std::string* Brain::getIdeas()
{
	return ideas;
}

void Brain::setIdeas(int index, std::string str)
{
	ideas[index] = str;
}