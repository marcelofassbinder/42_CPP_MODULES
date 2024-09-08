#include "Ice.hpp"

Ice::Ice() {
	this->_type = "ice";
}

Ice::Ice(const Ice &src) {
	*this = src;
}

Ice& Ice::operator=(const Ice &src) {
	if (this != &src) {
		this->_type = src._type;
	}
	return (*this);
}

Ice::~Ice() {}

Ice* Ice::clone() const {
	Ice* newIce = new Ice();
	return (newIce);
}

void Ice::use(ICharacter &target) {
	std::cout << BLUE BOLD "* shoots an ice bolt at " << target.getName() << RESET << std::endl;
}
