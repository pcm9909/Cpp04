#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "MateriaList.hpp"

class Character : public ICharacter
{
	private:
		AMateria *inventory[4];
	public:
		Character(std::string name);
		~Character();
		Character(const Character &character);
		Character &operator=(const Character &character);

		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);

		MateriaList* m;
		void deleteAll(MateriaList* m);
};

#endif