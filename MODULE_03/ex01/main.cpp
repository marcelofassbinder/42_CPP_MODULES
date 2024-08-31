#include "ScavTrap.hpp"

int main(void) {
	ScavTrap chitao("CHITAOZINHO");
	ScavTrap xororo("XORORO");

	chitao.attack("XORORO");
	xororo.takeDamage(20);
	xororo.beRepaired(40);
	xororo.guardGate();

	//make chitaozinho die
	/* for (int i = 0; i < 5; i++) {
		xororo.attack(chitao.getName());
		chitao.takeDamage(xororo.getAttack());
	} */

	//test what happens if scavtrap has no energy points
	/* for(int i = 0; i < 51; i++) {
		a.attack("josmar");
	} */

	//test what happens if scavtrap has no hit points
	/* chitao.takeDamage(100);
	chitao.attack("josmar");
	chitao.beRepaired(50);
	chitao.takeDamage(50); */

}