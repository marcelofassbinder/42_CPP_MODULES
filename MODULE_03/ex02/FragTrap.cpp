#include "FragTrap.hpp"

// - - - - - ORTHODOX CANONICAL FORM - - -  -
FragTrap::FragTrap() {
	std::cout << CYAN << "FragTrap-> Default constructor called" << RESET << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) {
	std::cout << CYAN << "FragTrap-> Parametrized constructor called for " << name << RESET << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &src) {
	std::cout << CYAN << "FragTrap-> Copy constructor called" << RESET << std::endl;
	*this = src;
}

FragTrap& FragTrap::operator=(const FragTrap &src) {

	if (this != &src) {
		std::cout << CYAN << "FragTrap-> Copy asssignment operator called" << RESET << std::endl;
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << CYAN << "FragTrap-> Destructor called for "<< this->_name << RESET << std::endl;
}

// - - - - - MEMBER FUNCTION - - - - 
void FragTrap::highFivesGuys() {
	std::cout << BOLD GREEN << "FragTrap " << this->_name << " sends a " << std::endl;

	std::cout << "⠀   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⠿⠿⣶⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⠏⠀⠀⠀⠀⠙⣷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠘⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⠇⠀⠀⠀⠀⠀⠀⠀⢹⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⡏⠀⠀⠀⠀⠀⠀⠀⠀⢸⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⠃⠀⠀⠀⠀⠀⠀⠀⢀⣾⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⡇⠀⠀⣀⠀⠀⠀⠀⠀⣼⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⡟⠀⠀⠀⡻⢿⣗⡒⢢⡾⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⠏⠀⠀⠀⠀⢿⣯⠉⠀⡾⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣾⠟⠁⠀⠀⠀⠀⠀⠀⠛⠀⣼⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣄⡀⠀⠀⠀⠀⠀⣀⣀⣀⣀⣀⣀⣀⣀⡀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠛⠛⠛⠛⠋⠉⠉⣀⣀⠤⠄⠈⠉⠛⢿⣦⡀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀⢠⣀⡀⠀⠀⠀⠀⠀⠀⣠⠞⣄⠀⣠⡴⠛⠁⠀⠀⠀⠀⠀⠀⠀⢹⡧⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⡿⠃⠀⠀⠀⠀⠀⠀⠀⠠⣼⡛⠿⣭⣗⢦⣄⡀⢀⣼⣡⡞⠁⣴⣫⣤⣄⣀⠀⠀⠀⠀⠀⠀⠀⣾⡇⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣏⡓⢶⣮⡿⠟⠛⠚⠛⠛⠛⠋⠉⠁⠀⠀⠉⠉⠂⠀⠀⠀⠀⢼⡟⡀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⢳⡟⠀⠀⠀⠀⠀⠠⠤⠤⠤⣴⣶⣶⠀⠀⠀⠀⠀⢀⠆⠈⠻⣧⣀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣾⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣿⡇⠀⠀⠠⣤⣤⡤⠤⠭⠭⠭⠿⠿⡀⠀⠀⠀⢠⡞⠀⠀⠀⠈⢻⣦" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣤⣶⠿⠟⠛⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠤⠤⠭⢿⣿⣷⣄⡀⠀⢀⣀⡉⣭⠭⠭⠭⠭⢭⠇⠀⢀⣴⠋⠀⠀⠀⠀⠀⣼⡿" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⢀⣀⣠⣤⣤⣶⠶⠟⠛⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⡖⠒⠒⢒⣒⣿⡿⠟⠉⠛⠷⢶⣶⣯⣭⣭⣬⣭⣽⣭⣤⡴⠟⠁⠀⠀⠀⠀⢀⣾⠟⠐" << std::endl;
	std::cout << "⠹⠿⠟⠛⠛⠛⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⣼⡓⠾⢭⣭⣭⣭⣿⡏⠀⠀⠀⠀⠀⠠⣤⣤⣤⣤⣤⣀⣤⠀⠀⠀⠀⠀⠀⠀⢠⠆⠀⢿⣇⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣍⠳⠬⣍⣓⡲⢶⣾⣾⡇⠀⠀⠀⣤⠤⠤⢤⣭⣍⣙⣚⣛⣻⡆⠀⠀⠀⠀⠀⣰⠋⠀⠀⣸⡿⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠨⣙⡒⠤⢬⣭⣽⣿⣿⣿⣄⠀⠀⠘⢻⡭⠿⢟⣛⣺⣿⣷⣶⡆⠀⠀⠀⢀⠜⠁⠀⠀⠀⣟⠁⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣗⠦⣌⣉⡓⠲⠶⠬⢿⣿⣿⡿⠿⢶⣤⣤⣉⣉⣓⠒⠚⠛⠿⠿⠁⣀⣠⠞⠃⠀⠀⠀⠀⠀⣿⡀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡀⠀⠀⠀⠀⣈⠓⠦⣭⣍⣛⣻⣿⢿⣿⡟⠀⠀⠀⠈⠉⠭⠭⣿⣿⣻⣻⣿⠶⠞⠋⠁⠀⠀⠀⢀⠀⠀⠀⣿⡇⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⡤⠶⠶⣛⣻⣷⠀⠀⠀⡄⢦⣉⠲⠦⣄⣉⣉⣛⣻⣿⡇⠀⠀⠀⢵⣲⣶⠮⣭⣉⣳⣾⣿⣿⠀⠀⠀⠀⠀⡼⠁⠀⢀⣾⠋⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⢉⣁⡤⠶⠖⠛⠉⠉⣿⣄⠀⠘⢿⡳⢌⡛⠶⢶⣾⣭⣭⣿⣿⣿⣦⣄⠐⠾⢝⣺⣿⠿⣗⣒⣶⣾⡿⠀⠀⠀⣠⠎⠀⠀⣠⡿⠁⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠴⠚⠋⠁⠀⠀⠀⠀⠀⠀⠈⣻⣦⡀⠘⢿⣳⡽⢿⣷⣶⣬⣿⣿⣿⣿⣿⣿⠛⠻⠶⢤⣬⣭⣻⣿⣶⣾⣃⣀⡤⠞⠁⠀⠀⢠⣿⠃⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣴⣶⡾⠟⠛⠛⢿⣦⣝⣺⢭⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⡀⠀⠀⢀⣀⡀⢩⣟⣯⣍⠉⠉⠀⠀⠀⠀⣠⣿⠋⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⡶⠟⠛⠉⠉⠀⠀⠀⠀⠀⠀⠉⠛⠿⢿⣿⣿⣿⣿⣿⣿⠿⠿⠿⠛⣦⣄⠀⣂⣸⣿⣟⡭⣶⡿⠀⠀⠀⠀⣠⣾⠟⠁⠀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣶⠾⠟⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠻⢶⣿⣥⣁⣚⣻⣃⣀⣠⣴⠾⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⠀⠀⢀⣠⣴⡾⠟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠙⠛⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "⠀⠀⠀⢀⣿⡿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	std::cout << "For you!!!" << RESET << std::endl;

}