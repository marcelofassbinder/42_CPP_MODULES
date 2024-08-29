#include "ClapTrap.hpp"

// - - - - - ORTHODOX CANONICAL FORM - - - - - - 
ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << BLUE << "Default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << BLUE << "Parametrized constructor called for " << this->_name << RESET << std::endl;\
}

ClapTrap::ClapTrap(const ClapTrap &src) {
	*this = src;
}

ClapTrap::~ClapTrap() {
	std::cout << BLUE << "Destructor called" << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &src) {
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return (*this);
}

// - - - - - GETTERS - - - - - - 
std::string ClapTrap::getName(void) const {
	return (this->_name);
}

int ClapTrap::getHit(void) const {
	return (this->_hitPoints);
}

int ClapTrap::getEnergy(void) const {
	return (this->_energyPoints);
}

int ClapTrap::getAttack(void) const {
	return (this->_attackDamage);
}

// - - - - - MEMBER FUNCTIONS - - - - - - 
void ClapTrap::attack(const std::string& target) {
	if (target.empty()) {
		std::cout << "please insert a valid target" << std::endl;
		return ;
	}
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		std::cout << GREEN BOLD << "ClapTrap " << this->_name;
		std::cout << " attacks " << target << ", causing " ;
		std::cout << this->_attackDamage << " points of damage!" << RESET << std::endl;
		this->_energyPoints--;
	}
	else if (this->_hitPoints <= 0){
		std::cout << RED BOLD BLINK << "Clap Trap " << this->_name << " is dead" << RESET << std::endl;
	}
	else if (this->_energyPoints <= 0){
		std::cout << BOLD BLINK << this->_name << " has no energy points left to attack!" << RESET << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (amount <= 0) {
		std::cout << "please insert a valid amount of damage" << std::endl;
		return ;
	}
	if (this->_hitPoints <= 0)
		std::cout << RED BOLD BLINK << "Clap Trap " << this->_name << " is dead" << RESET << std::endl;
	else {
		std::cout << RED BOLD << "Clap Trap " << this->_name << " took " << amount;
		std::cout << " points of damage!" << RESET << std::endl;
		this->_hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (amount <= 0) {
		std::cout << "please insert a valid amount for repairing" << std::endl;
		return ;
	}if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		std::cout << YELLOW BOLD << "ClapTrap " << this->_name << " was repaired in ";
		std::cout << amount << " points" << RESET << std::endl;
		this->_hitPoints+= amount;
		this->_energyPoints--;
	}
	else if (this->_hitPoints <= 0){
		std::cout << RED BOLD BLINK << "Clap Trap " << this->_name << " is dead" << RESET << std::endl;
	}
	else if (this->_energyPoints <= 0){
		std::cout << BOLD BLINK << this->_name << " has no energy points left to be repaired!" << RESET << std::endl;
	}
}