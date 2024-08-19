#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {
	std::cout << "Human " << this->_name << " is BORN" << std::endl;
}

HumanA::~HumanA(void) {
	std::cout << "Human " << this->_name << " is DEAD" << std::endl;
}

void HumanA::attack(void) {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}