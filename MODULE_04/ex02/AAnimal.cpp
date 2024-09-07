#include "AAnimal.hpp"

AAnimal::AAnimal(){
	std::cout << YELLOW <<"AAnimal-> Default constructor called" << RESET << std::endl;
	this->type = "Default AAnimal";
}

AAnimal::AAnimal(const AAnimal &src) {
	std::cout << YELLOW <<"AAnimal-> Copy constructor called" << RESET << std::endl;
	*this = src;
}

AAnimal& AAnimal::operator=(const AAnimal &src) {
	
	if (this != &src) {
		std::cout << YELLOW <<"AAnimal-> Copy operator assignment called" << RESET << std::endl;
		this->type = src.type;
	}
	return (*this);
}

AAnimal::~AAnimal() {
	std::cout << YELLOW <<"AAnimal-> Destructor called\n" << RESET << std::endl;
}

void AAnimal::makeSound() const{
	std::cout << YELLOW BOLD <<"*** Default AAnimal Sound ***" << RESET << std::endl;
}

std::string AAnimal::getType() const {
	return (this->type);
}