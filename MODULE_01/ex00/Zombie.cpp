#include "Zombie.hpp"

Zombie::Zombie() { 
	std::cout << BLUE << "*** NEW ZOMBIE CREATED ***\n" << RESET << std::endl;
}

Zombie::~Zombie() { 
	std::cout << BOLD RED << "\nZOMBIE " << name << " IS DEAD!\n" << RESET << std::endl;
}

void Zombie::announce(void){
	std::cout << BOLD << name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

void Zombie::setZombieName(std::string name) { 
	this->name = name;
}
