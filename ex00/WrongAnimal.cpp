#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "WrongAnimal";
	std::cout << typeid(this).name() << " constructor called!" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << typeid(this).name() << " destructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &dog)
{
	std::cout << typeid(this).name() << " Copy Constructor called" << std::endl;
	*this = dog;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &dog)
{
	if(this != &dog)
	{
		this->type = getType();
		std::cout << typeid(this).name() << " Assignation Operator called" << std::endl;
	}
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal Sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}