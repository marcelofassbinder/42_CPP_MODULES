#include "Wrong.hpp"

//WRONG ANIMAL FUNCTIONS
WrongAnimal::WrongAnimal(){
	std::cout << RED << "WrongAnimal-> Default constructor called" << RESET << std::endl;
	this->_type = "Default WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) : _type(src._type){
	std::cout << RED << "WrongAnimal-> Copy constructor called" << RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &src) {
	if (this != &src) {
		std::cout << RED << "WrongAnimal-> Copy operator assignment called" << RESET << std::endl;
		(void) src;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << RED << "WrongAnimal-> Destructor called" << RESET << std::endl;
}

void WrongAnimal::makeSound() const{
	std::cout << RED BOLD << "*** Default WrongAnimal Sound ***" << RESET << std::endl;
}

std::string WrongAnimal::getType() const {
	return (this->_type);
}

//WRONG CAT FUNCTIONS
WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "WrongCat-> Default constructor called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {
	std::cout << "WrongCat-> Copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &src) {
	if (this != &src) {
		std::cout << RED << "WrongCat-> Copy operator assignment called" << RESET << std::endl;
		WrongAnimal::operator=(src);
	}
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat-> Destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "*** MIAU ***" << std::endl;
}