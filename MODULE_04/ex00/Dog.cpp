#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << BLUE << "Dog-> Default constructor called" << RESET << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog &src) : Animal(src) {
	std::cout << BLUE << "Dog-> Copy constructor called" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog &src) {
	if (this != &src) {
		std::cout << BLUE << "Dog-> Copy operator assignment called" << RESET << std::endl;
		Animal::operator=(src);
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << BLUE << "Dog-> Destructor called" << RESET << std::endl;
}

void Dog::makeSound() const {
	std::cout << BLUE BOLD << "*** AUAU ***" << RESET << std::endl;
}