#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << typeid(this).name() << " constructor called!" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << typeid(this).name() << " destructor called!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &dog)
{
	std::cout << typeid(this).name() << " Copy Constructor called" << std::endl;
	*this = dog;
}

WrongCat &WrongCat::operator=(const WrongCat &dog)
{
	if(this != &dog)
	{
		this->type = getType();
		std::cout << typeid(this).name() << " Assignation Operator called" << std::endl;
	}
	return *this;
}