#include "Cat.hpp"

Cat::Cat(){
	std::cout << CYAN << "Cat-> Default constructor called" << RESET << std::endl;
	this->brain = new Brain();
	this->type = "Cat";
}

Cat::Cat(const Cat &src) {
	std::cout << CYAN << "Cat-> Copy constructor called" << RESET << std::endl;
	this->brain = src.brain;
	*this = src;
}

Cat& Cat::operator=(const Cat &src) {
	
	if (this != &src) {
		std::cout << CYAN << "Cat-> Copy operator assignment called" << RESET << std::endl;
		this->brain = src.brain;
		this->type = src.type;
	}
	return (*this);
}

Cat::~Cat() {
	delete(this->brain);
	std::cout << CYAN << "Cat-> Destructor called" << RESET << std::endl;
}

void Cat::makeSound() const {
	std::cout << CYAN BOLD << "*** MIAU ***" << RESET << std::endl;
}

void	Cat::displayBrainIdeas() {
	this->brain->displayIdeas();
}

void	Cat::setBrainIdea(std::string newIdea) {
	this->brain->setIdea(newIdea);
}

std::string* Cat::getBrainIdeas() {
	return this->brain->getIdeas();
}