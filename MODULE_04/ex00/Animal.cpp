#include "Animal.hpp"

Animal::Animal(){
	std::cout << YELLOW <<"Animal-> Default constructor called" << RESET << std::endl;
	this->type = "Default Animal";
}

Animal::Animal(const Animal &src) {
	std::cout << YELLOW <<"Animal-> Copy constructor called" << RESET << std::endl;
	*this = src;
}

Animal& Animal::operator=(const Animal &src) {
	std::cout << YELLOW <<"Animal-> Copy operator assignment called" << RESET << std::endl;
	this->type = src.type;
	return (*this);
}

Animal::~Animal() {
	std::cout << YELLOW <<"Animal-> Destructor called" << RESET << std::endl;
}

void Animal::makeSound() const{
	std::cout << YELLOW BOLD <<"*** Default Animal Sound ***" << RESET << std::endl;
}

std::string Animal::getType() const {
	return (this->type);
}