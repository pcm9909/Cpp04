#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>
#include <typeinfo>

class Brain
{
	public:
		Brain();
		virtual ~Brain();
		Brain(const Brain &animal);
		Brain &operator= (const Brain &ct);
	private:
		std::string ideas[100];
};

#endif