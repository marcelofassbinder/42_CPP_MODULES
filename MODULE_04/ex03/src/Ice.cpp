#include "../includes/Ice.hpp"

Ice::Ice() : AMateria() {
	this->_type = "ice";
}

Ice::Ice(const Ice &src) : AMateria(src) {
}

Ice& Ice::operator=(const Ice &src) {
	(void) src;
	return (*this);
}

Ice::~Ice() {}

Ice* Ice::clone() const {
	Ice* newIce = new Ice();
	return (newIce);
}

void Ice::use(ICharacter &target) {
	std::cout << BLUE BOLD "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}