#include <string>

class ICharacter
{
public:
    virtual ~ICharacter() {}
    virtual std::string const & getName() const = 0; // 이름 반환
    virtual void equip(AMateria* m) = 0; // Materia 장착
    virtual void unequip(int idx) = 0; // Materia 해제
    virtual void use(int idx, ICharacter& target) = 0; // Materia 사용
};
