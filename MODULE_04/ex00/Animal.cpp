#include "Animal.hpp"

Animal::Animal() : _type("Default Animal") {
	std::cout << YELLOW <<"Animal-> Default constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal &src) : _type(src._type) {
	std::cout << YELLOW <<"Animal-> Copy constructor called" << RESET << std::endl;
}

Animal& Animal::operator=(const Animal &src) {
	if (this != &src) {
		std::cout << YELLOW <<"Animal-> Copy operator assignment called" << RESET << std::endl;
		(void) src;
	}
	return (*this);
}

Animal::~Animal() {
	std::cout << YELLOW <<"Animal-> Destructor called" << RESET << std::endl;
}

void Animal::makeSound() const{
	std::cout << YELLOW BOLD <<"*** Default Animal Sound ***" << RESET << std::endl;
}

std::string Animal::getType() const {
	return (this->_type);
}