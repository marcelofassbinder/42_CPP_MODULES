#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << BLUE << "Dog-> Default constructor called" << RESET << std::endl;
	this->brain = new Brain();
	this->_type = "Dog";
}

Dog::Dog(const Dog &src) : Animal(src) {
	std::cout << BLUE << "Dog-> Copy constructor called" << RESET << std::endl;
	this->brain = new Brain(*src.brain);
}

Dog& Dog::operator=(const Dog &src) {
	
	if (this != &src) {
		std::cout << CYAN << "Dog-> Copy operator assignment called" << RESET << std::endl;
		Animal::operator=(src);
		delete(this->brain);
		this->brain = new Brain(*src.brain);
	}
	return (*this);
}

Dog::~Dog() {
	delete(this->brain);
	std::cout << BLUE << "Dog-> Destructor called" << RESET << std::endl;
}

void Dog::makeSound() const {
	std::cout << BLUE BOLD << "*** AUAU ***" << RESET << std::endl;
}

void	Dog::displayBrainIdeas() {
	this->brain->displayIdeas();
}

void	Dog::setBrainIdea(std::string newIdea) {
	this->brain->setIdea(newIdea);
}

std::string* Dog::getBrainIdeas() {
	return this->brain->getIdeas();
}