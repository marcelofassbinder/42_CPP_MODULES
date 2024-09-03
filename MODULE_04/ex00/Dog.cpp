#include "Dog.hpp"

Dog::Dog(){
	std::cout << BLUE << "Dog-> Default constructor called" << RESET << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &src) {
	std::cout << BLUE << "Dog-> Copy constructor called" << RESET << std::endl;
	*this = src;
}

Dog& Dog::operator=(const Dog &src) {
	std::cout << BLUE << "Dog-> Copy operator assignment called" << RESET << std::endl;
	this->type = src.type;
	return (*this);
}

Dog::~Dog() {
	std::cout << BLUE << "Dog-> Destructor called" << RESET << std::endl;
}

void Dog::makeSound() const {
	std::cout << BLUE BOLD << "*** AUAU ***" << RESET << std::endl;
}