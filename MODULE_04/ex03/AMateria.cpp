#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const &type) : _type(type) {
}

AMateria::AMateria(const AMateria &src) {
	*this = src;
}

AMateria& AMateria::operator=(const AMateria &src) {
	if (this != &src) {
		this->_type = src._type;
	}
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter &target) {
	(void) target;
	std::cout << "Default Materia use" << std::endl;
}