#include "../includes/AMateria.hpp"

AMateria::AMateria() : isEquiped(false), atFloor(false) {
}

AMateria::AMateria(std::string const &type) : _type(type), isEquiped(false), atFloor(false) {
}

AMateria::AMateria(const AMateria &src) : _type(src._type), isEquiped(false), atFloor(false) {
}

AMateria& AMateria::operator=(const AMateria &src) {
	(void) src;
	return(*this);
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter &target) {
	(void) target;
	std::cout << "Default Materia use" << std::endl;
}
