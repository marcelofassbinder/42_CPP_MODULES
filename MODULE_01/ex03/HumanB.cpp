#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
	std::cout << "Human " << this->_name << " is BORN" << std::endl;
}

HumanB::~HumanB(void) {
	std::cout << "Human " << this->_name << " is DEAD" << std::endl;
}

void HumanB::attack(void) {
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}