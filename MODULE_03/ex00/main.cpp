
#include "ClapTrap.hpp"

int main(void) {
	ClapTrap bruno("bruno");
	ClapTrap marrone("marrone");

	bruno.attack("marrone");
	marrone.takeDamage(2);
	marrone.beRepaired(4);

	/* for (int i  = 0; i < 11; i++) {
		marrone.takeDamage(2);
	}
	marrone.attack("bruno"); */


	std::cout << bruno.getName() << "-> hit points = " << bruno.getHit() << ", energy points = " << bruno.getEnergy() << std::endl;
	std::cout << marrone.getName() << "-> hit points = " << marrone.getHit() << ", energy points = " << marrone.getEnergy() << std::endl;
}