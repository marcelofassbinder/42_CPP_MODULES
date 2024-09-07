#include "Wrong.hpp"

//WRONG ANIMAL FUNCTIONS
WrongAnimal::WrongAnimal(){
	std::cout << RED << "WrongAnimal-> Default constructor called" << RESET << std::endl;
	this->type = "Default WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
	std::cout << RED << "WrongAnimal-> Copy constructor called" << RESET << std::endl;
	*this = src;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &src) {
	std::cout << RED << "WrongAnimal-> Copy operator assignment called" << RESET << std::endl;
	this->type = src.type;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << RED << "WrongAnimal-> Destructor called" << RESET << std::endl;
}

void WrongAnimal::makeSound() const{
	std::cout << RED BOLD << "*** Default WrongAnimal Sound ***" << RESET << std::endl;
}

std::string WrongAnimal::getType() const {
	return (this->type);
}

//WRONG CAT FUNCTIONS
WrongCat::WrongCat(){
	std::cout << "WrongCat-> Default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src) {
	std::cout << "WrongCat-> Copy constructor called" << std::endl;
	*this = src;
}

WrongCat& WrongCat::operator=(const WrongCat &src) {
	std::cout << "WrongCat-> Copy operator assignment called" << std::endl;
	this->type = src.type;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat-> Destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "*** MIAU ***" << std::endl;
}