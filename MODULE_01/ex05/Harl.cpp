#include "Harl.hpp"

Harl::Harl(){
	return ;
}

Harl::~Harl(){
	return ;
}

void Harl::debug(void) {
	std::cout << BOLD << "[ DEBUG ]" << RESET << std::endl;
	std::cout << GREEN << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!\n" << RESET << std::endl;
}

void Harl::info(void) {
	std::cout << BOLD << "[ INFO ]" << RESET << std::endl;
	std::cout << BLUE << "I cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n" << RESET <<std::endl;
}

void Harl::warning(void) {
	std::cout << BOLD << "[ WARNING ]" << RESET << std::endl;
	std::cout << YELLOW << "I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month.\n" << RESET <<std::endl;
}

void Harl::error(void) {
	std::cout << BOLD << "[ ERROR ]" << RESET << std::endl;
	std::cout << RED << "This is unacceptable! I want to speak to the manager now.\n" << RESET << std::endl;
}

void Harl::complain(std::string level) {
	void (Harl::*deb)(void) = &Harl::debug;
	void (Harl::*inf)(void) = &Harl::info;
	void (Harl::*warn)(void) = &Harl::warning;
	void (Harl::*err)(void) = &Harl::error;

	void (Harl::*memberFunctions[4])(void) = {deb, inf, warn, err};
	std::string levelStrings[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for(int i = 0; i < 4; i++) {
		if (level == levelStrings[i])
			return ((this->*memberFunctions[i])());
	}
	std::cout << "Input must be one of the following strings: 'DEBUG', 'INFO', 'WARNING', 'ERROR'" << std::endl;
}