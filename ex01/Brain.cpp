#include "Brain.hpp"

Brain::Brain()
{
	std::cout << typeid(this).name() << " constructor called!" << std::endl;
}

Brain::~Brain()
{
	std::cout << typeid(this).name() << " destructor called!" << std::endl;
}

Brain::Brain(const Brain &brain)
{
	std::cout << typeid(this).name() << " Copy Constructor called" << std::endl;
	*this = brain;
}
Brain &Brain::operator=(const Brain &brain)
{
	if(this != &brain)
	{
		std::cout << typeid(this).name() << " Assignation Operator called" << std::endl;
	}
	return *this;
}
