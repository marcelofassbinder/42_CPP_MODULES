#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const &type) : _type(type) {
}

AMateria::AMateria(const AMateria &src) {
	*this = src;
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
