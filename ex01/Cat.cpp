#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << typeid(*this).name() << " constructor called!" << std::endl;
}

Cat::~Cat()
{
	brain->releaseRef();
	std::cout << typeid(*this).name() << " destructor called!" << std::endl;
}

Cat::Cat(const Cat &cat)
{
	std::cout << typeid(*this).name() << " Copy Constructor called" << std::endl;
	this->brain = cat.brain; // 얕은 복사 수행
	brain->addRef();
	this->type = cat.type;
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << typeid(*this).name() << " Assignation Operator called" << std::endl;
	if (this != &cat)
	{
		brain->releaseRef();
		this->brain = new Brain(*cat.brain); // 깊은 복사 수행
		brain->addRef();
		this->type = cat.type;
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
	if (this->brain->ideas[index].empty())
	{
		this->brain->ideas[index] = str;
	}
	else
	{
		std::cout << "already in use !" << std::endl;
	}
}