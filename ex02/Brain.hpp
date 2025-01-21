// Brain.hpp
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <typeinfo>

class Brain
{
	public:
		Brain();
		Brain(const Brain &other);
		~Brain();
		Brain &operator=(const Brain &other);
		void setIdeas(int index, std::string str);
		std::string getIdeas(int i);
	protected:
		std::string ideas[100];
};

#endif