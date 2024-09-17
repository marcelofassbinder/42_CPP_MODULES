#include "../includes/Cure.hpp"

Cure::Cure() {
	this->_type = "cure";
}

Cure::Cure(const Cure &src) {
	*this = src;
}

Cure& Cure::operator=(const Cure &src) {
	(void) src;
	return (*this);
}

Cure::~Cure() {}

Cure* Cure::clone() const {
	Cure* newCure = new Cure();
	return (newCure);
}

void Cure::use(ICharacter &target) {
	std::cout << GREEN BOLD "* heals " << target.getName() << "'s wounds *" RESET << std::endl;
}