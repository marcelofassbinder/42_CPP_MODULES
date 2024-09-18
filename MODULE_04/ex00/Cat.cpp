#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << CYAN << "Cat-> Default constructor called" << RESET << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat &src) : Animal(src) {
	std::cout << CYAN << "Cat-> Copy constructor called" << RESET << std::endl;
}

Cat& Cat::operator=(const Cat &src) {
	if (this != &src) {
		std::cout << CYAN << "Cat-> Copy operator assignment called" << RESET << std::endl;
		Animal::operator=(src);
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << CYAN << "Cat-> Destructor called" << RESET << std::endl;
}

void Cat::makeSound() const {
	std::cout << CYAN BOLD << "*** MIAU ***" << RESET << std::endl;
}