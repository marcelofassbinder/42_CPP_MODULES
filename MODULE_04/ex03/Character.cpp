#include "Character.hpp"

Character::Character() {
	std::cout << "Character-> Default constructor called" << std::endl;
}

Character::Character(std::string const &name) : _name(name){
	std::cout << "Character-> Parametrized constructor called for " << name << std::endl;
	for(int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	
}

Character::Character(const Character &src) {
	std::cout << "Character-> Copy constructor called" << std::endl;
	*this = src;
}

Character& Character::operator=(const Character &src) {
	if (this != &src) {
		std::cout << "Character-> Copy assignment operator called" << std::endl;
		this->_name = src._name;
		this->copyInventory(src);
	}
	return (*this);
}

Character::~Character() {
	std::cout << "Character-> Destructor called" << std::endl;
	int i = 0;
	while (this->_inventory[i]) {
		delete(this->_inventory[i]);
		i++;
	}
}

void Character::copyInventory(const Character &src) {
	int i = 0;
	while (this->_inventory[i]) {
		delete(this->_inventory[i]);
		i++;
	}
	for(int i = 0; i < 4; i++) {
		this->_inventory[i] = src._inventory[i]->clone();
	}
}

std::string const& Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria *m) {
	int i = 0;

	while(this->_inventory[i]) {
		i++;
	}
	if (i == 3) 
		std::cout << "Inventory is full! Unequip a Materia to free space!" << std::endl;
	else {
		if (this->checkMateriaInInventory(*m)) {
			std::cout << m->getType() << " already exists in the inventory!" << std::endl;
		}
		else {
			this->_inventory[i] = m;
			std::cout << m->getType() << " added to " << this->getName() << "'s inventory" << std::endl;
		}
	}
}

void Character::unequip(int idx) {

	AMateria *toUnequip = this->_inventory[idx];
	if (idx < 0 || idx > 3)
		std::cout << "The inventory contains 4 slots. Please input a number from 0 to 3!" << std::endl;
	else if (!toUnequip)
		std::cout << "No Materia found at this index!" << std::endl;
	else {
		this->_inventory[idx] = NULL;
		std::cout << toUnequip->getType() << " left on the floor by " << this->getName() << std::endl;
		this->addToGarbage(toUnequip);
	}
}

void Character::addToGarbage(AMateria *m) { //mudar garbage para "floor" - criar uma classe singleton(que utiliza apenas uma instancia no programa inteiro, de forma com que as materias desequipadas possam ser equipadas por outros players)
	int i = 0;
	while(this->garbage[i])
		i++;
	this->garbage[i] = m;
}

void Character::use(int idx, ICharacter &target) {
	AMateria *toUse = this->_inventory[idx];
	
	if (idx < 0 || idx > 3)
		std::cout << "The inventory contains 4 slots. Please input a number from 0 to 3!" << std::endl;
	else if(!toUse) {
		std::cout << "No Materia found at this index!" << std::endl;
	}
	else
		toUse->use(target);
}

void Character::displayInfo() {
	std::cout << this->getName() << " INFOS:\n" << std::endl;

	std::cout << "Inventory:" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i])
			std::cout << "Item " << i + 1 <<": " << this->_inventory[i]->getType() << std::endl;
	}
	std::cout << "Garbage:" << std::endl;
	int i = 0;
	while (this->garbage[i]) {
		std::cout << "Item " << i + 1 <<": " << this->garbage[i]->getType() << std::endl;
		i++;
	}
}

bool Character::checkMateriaInInventory(const AMateria& m) {
	int i = 0;
	while (this->_inventory[i]) {
		if (this->_inventory[i] == &m)
			return true;
		i++;
	}
	return false;
}