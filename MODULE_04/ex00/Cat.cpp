#include "Cat.hpp"

Cat::Cat(){
	std::cout << CYAN << "Cat-> Default constructor called" << RESET << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &src) {
	std::cout << CYAN << "Cat-> Copy constructor called" << RESET << std::endl;
	*this = src;
}

Cat& Cat::operator=(const Cat &src) {
	std::cout << CYAN << "Cat-> Copy operator assignment called" << RESET << std::endl;
	this->type = src.type;
	return (*this);
}

Cat::~Cat() {
	std::cout << CYAN << "Cat-> Destructor called" << RESET << std::endl;
}

void Cat::makeSound() const {
	std::cout << CYAN BOLD << "*** MIAU ***" << RESET << std::endl;
}