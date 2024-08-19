#include "Zombie.hpp"

Zombie::Zombie() { 
	std::cout << BLUE << "*** NEW ZOMBIE CREATED ***\n" << RESET << std::endl;
}

Zombie::~Zombie() { 
	std::cout << BOLD RED << "\nZOMBIE " << this->_name << " IS DEAD!" << RESET << std::endl;
}

void Zombie::announce(void){
	std::cout << BOLD << /* this->id << " - " <<  */this->_name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

void Zombie::setZombieName(std::string name) { 
	this->_name = name;
}

/* void Zombie::setZombieId(int id) { 
	this->id = id;
}
 */
