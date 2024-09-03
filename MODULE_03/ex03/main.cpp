#include "DiamondTrap.hpp"

int main(void) {
	DiamondTrap kaka("KAKA");
	DiamondTrap dida("DIDA");

	kaka.attack("DIDA");
	dida.takeDamage(kaka.getAttack());

	
	dida.whoAmI();

	DiamondTrap dida2(dida);
	dida2.whoAmI();

}