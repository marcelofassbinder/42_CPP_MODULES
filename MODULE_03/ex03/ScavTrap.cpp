#include "ScavTrap.hpp"

// - - - - - - ORTHODOX CANONICAL FORM - - - - -  
ScavTrap::ScavTrap() {
	std::cout << MAGENTA << "ScavTrap-> Default constructor called" << RESET << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) {
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << MAGENTA << "ScavTrap-> Parametrized constructor called for " << this->_name << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) {
	std::cout << MAGENTA << "ScavTrap-> Copy constructor called" << RESET << std::endl;
	*this = src;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &src) {
	
	if (this != &src) {
		std::cout << MAGENTA << "ScavTrap-> Copy assignment operator called" << RESET << std::endl;
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << MAGENTA << "ScavTrap-> Destructor called for " << this->_name << RESET << std::endl;
}


// - - - - - MEMBER FUNCTIONS - - - - - 
void ScavTrap::attack(const std::string& target) {
	if (target.empty()) {
		std::cout << "please insert a valid target" << std::endl;
		return ;
	}
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		std::cout << GREEN BOLD << "\nScavTrap " << this->_name;
		std::cout << " attacks " << target << ", causing " ;
		std::cout << this->_attackDamage << " points of damage!" << RESET << std::endl;
		this->_energyPoints--;
	}
	else if (this->_hitPoints <= 0){
		std::cout << RED BOLD BLINK << "\nScavTrap " << this->_name << " is dead and cannot attack!" << RESET << std::endl;
	}
	else if (this->_energyPoints <= 0){
		std::cout << BOLD BLINK << this->_name << " has no energy points left to attack!" << RESET << std::endl;
	}
}

void ScavTrap::guardGate() {
	std::cout << CYAN BOLD << "\nScavTrap " << this->_name << " activated the GATE KEEPER mode!" << RESET << std::endl;
}
