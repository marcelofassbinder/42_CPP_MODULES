#include "DiamondTrap.hpp"

// - - - - - ORTHODOX CANONICAL FORM - - - - - 
DiamondTrap::DiamondTrap() {

	std::cout << YELLOW << "DiamondTrap-> Default constructor called" << RESET << std::endl;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;

}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") {

	std::cout << YELLOW << "DiamondTrap-> Parametrized constructor called for " <<  name << RESET << std::endl;
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) {

	std::cout << YELLOW << "DiamondTrap-> Copy constructor called" << RESET << std::endl;
	*this = src;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &src) {
	
	std::cout << YELLOW << "DiamondTrap-> Copy operator assignment called" << RESET << std::endl;
	this->ClapTrap::_name = src.ClapTrap::_name;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;

	return (*this);
}

DiamondTrap::~DiamondTrap(){
	std::cout << YELLOW << "DiamondTrap-> Destructor called for " << this->_name << RESET << std::endl;
}

// - - - - - MEMBER FUNCTIONS - - - - - 
void DiamondTrap::whoAmI() {
	std::cout << BOLD <<"\nHey folks, my ClapTrap name is " << GREEN << this->ClapTrap::_name << RESET; 
	std::cout << BOLD <<" and my DiamondTrap name is " << GREEN << this->_name << RESET << std::endl;
}