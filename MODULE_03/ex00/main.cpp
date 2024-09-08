
#include "ClapTrap.hpp"

int main(void) {
	{
		std::cout << BOLD "\n - - - - REGULAR TESTS - - - - \n" RESET << std::endl;
		ClapTrap bruno("BRUNO");
		ClapTrap marrone("MARRONE");

		bruno.attack("MARRONE");
		marrone.takeDamage(2);
		marrone.beRepaired(4);
		
		bruno.displayInfo();
		marrone.displayInfo();
	}
	{
		std::cout << BOLD "\n - - - - KILL MARRONE - - - - \n" RESET << std::endl;
		ClapTrap bruno("BRUNO");
		ClapTrap marrone("MARRONE");

		for (int i  = 0; i < 5; i++) {
			marrone.takeDamage(2);
		}
		bruno.displayInfo();
		marrone.displayInfo();
	}
}