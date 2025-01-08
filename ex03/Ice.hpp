#include "AMateria.hpp"

class Ice : public AMateria
{
	Ice();
};

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice 생성" << std::endl;
}