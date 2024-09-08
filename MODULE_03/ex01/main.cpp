#include "ScavTrap.hpp"

int main(void) {
	{
		std::cout << BOLD "\n - - - - REGULAR TESTS - - - - \n" RESET << std::endl;
		ScavTrap chitao("CHITAOZINHO");
		ScavTrap xororo("XORORO");

		chitao.attack("XORORO");
		xororo.takeDamage(chitao.getAttack());
		xororo.beRepaired(40);
		xororo.guardGate();

		chitao.displayInfo();
		xororo.displayInfo();
	}
	{
		std::cout << BOLD "\n - - - - KILL CHITAOZINHO - - - - \n" RESET << std::endl;
		ScavTrap chitao("CHITAOZINHO");
		ScavTrap xororo("XORORO");

		for (int i = 0; i < 5; i++) {
			xororo.attack(chitao.getName());
			chitao.takeDamage(xororo.getAttack());
		}
		chitao.displayInfo();
		xororo.displayInfo();
	}
	{
		std::cout << BOLD "\n - - - - NO ENERGY POINTS - - - - \n" RESET << std::endl;
		ScavTrap chitao("CHITAOZINHO");
		ScavTrap xororo("XORORO");

		for(int i = 0; i < 51; i++) {
			chitao.attack("XORORO");
		}
		chitao.displayInfo();
		xororo.displayInfo();
	}
}