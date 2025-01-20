// Brain.hpp
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
public:
	Brain();
	Brain(const Brain &other);
	~Brain();
	Brain &operator=(const Brain &other);
	void setIdeas(int index, std::string str);
	std::string getIdeas(int index);
	std::string ideas[100];

private:
	int *refCount;
};

#endif