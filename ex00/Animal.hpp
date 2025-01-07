#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include <typeinfo>

class Animal
{
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal &animal);
		Animal &operator= (const Animal &ct);
		virtual void makeSound() const;
		std::string getType() const;
	protected:
		std::string type;
};

#endif