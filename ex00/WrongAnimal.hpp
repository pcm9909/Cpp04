#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>
#include <typeinfo>

class WrongAnimal
{
	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(const WrongAnimal &dog);
		WrongAnimal &operator= (const WrongAnimal &dog);
		std::string getType() const;
		void makeSound() const;
	protected:
		std::string type;
};

#endif