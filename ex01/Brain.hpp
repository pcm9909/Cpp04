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

	void addRef();
	void releaseRef();

	std::string ideas[100];

private:
	int *refCount;
};

#endif