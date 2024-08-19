#include "Zombie.hpp"

Zombie::Zombie() { 
	std::cout << BLUE << "*** NEW ZOMBIE CREATED ***\n" << RESET << std::endl;
}

Zombie::~Zombie() { 
	std::cout << BOLD RED << "\nZOMBIE " << this->_name << " IS DEAD!\n" << RESET << std::endl;
}

void Zombie::announce(void){
	std::cout << BOLD << this->_name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

void Zombie::setZombieName(std::string name) { 
	this->_name = name;
}
