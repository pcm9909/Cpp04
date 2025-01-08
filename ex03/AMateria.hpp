#include <string>
#include <iostream>

class AMateria
{
	protected:
		std::string type; // Materia의 타입을 저장하는 멤버 변수
	public:
		AMateria(std::string const & type);
		std::string const & getType() const; // Materia 타입을 반환
		virtual AMateria* clone() const = 0; // 순수 가상 함수
		virtual void use(ICharacter& target); // Materia 사용
};


AMateria::AMateria(std::string const & type)
{
	this->type = type;
}

std::string const &AMateria::getType() const
{
	return this->type;
}