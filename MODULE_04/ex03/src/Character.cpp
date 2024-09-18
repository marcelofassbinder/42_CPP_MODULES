#include "../includes/Character.hpp"

Character::Character() {
	std::cout << "Character-> Default constructor called" << std::endl;
	for(int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
}

Character::Character(std::string const &name) : _name(name){
	std::cout << "Character-> Parametrized constructor called for " << name << std::endl;
	for(int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	
}

Character::Character(const Character &src) : _name(src._name) {
	std::cout << "Character-> Copy constructor called" << std::endl;
	for(int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	this->copyInventory(src);
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
	std::cout << "Character " << this->getName() << " -> Destructor called" << std::endl;
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
	while (src._inventory[i]) {
		this->_inventory[i] = src._inventory[i]->clone();
		i++;
	}
}

std::string const& Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria *m) {
	int i = 0;
	
	if (!m)
		return ;
	while(this->_inventory[i]) {
		i++;
	}
	if (i == 3) 
		std::cout << "Inventory is full! Unequip a Materia to free space!" << std::endl;
	else {
		if (this->checkMateriaInInventory(*m)) {
			std::cout << m->getType() << " already exists in the inventory!" << std::endl;
		}
		else if (m->isEquiped == true) {
			std::cout << m->getType() << " has already been equiped by another character!" << std::endl;
		}
		else {
			if (m->atFloor == true)
				Floor::getInstance()->cleanFloor(m);
			this->_inventory[i] = m;
			std::cout << m->getType() << " added to " << this->getName() << "'s inventory" << std::endl;
			m->isEquiped = true;
		}
	}
}

void Character::unequip(int idx) {

	Floor *floor = Floor::getInstance();
	AMateria *toUnequip = this->_inventory[idx];
	if (idx < 0 || idx > 3)
		std::cout << "The inventory contains 4 slots. Please input a number from 0 to 3!" << std::endl;
	else if (!toUnequip)
		std::cout << "No Materia found at this index!" << std::endl;
	else {
		this->_inventory[idx] = NULL;
		std::cout << toUnequip->getType() << " left on the floor by " << this->getName() << std::endl;
		floor->leaveMateriaAtFloor(toUnequip);
	}
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

void Character::displayInventory() {
	std::cout << this->getName() << "'s INVENTORY:" << std::endl;

	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i])
			std::cout << "Item " << i + 1 <<": " << this->_inventory[i]->getType() << std::endl;
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