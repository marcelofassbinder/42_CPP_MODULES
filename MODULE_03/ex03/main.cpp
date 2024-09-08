#include "DiamondTrap.hpp"

int main(void) {
	
	{
		std::cout << BOLD "\n - - - - REGULAR TESTS - - - - \n" RESET << std::endl;
		ClapTrap ney("NEYMAR");
		ScavTrap cr7("CRISTIANO RONALDO");
		FragTrap messi("MESSI");
		DiamondTrap kaka("KAKA");

		ney.displayInfo();
		cr7.displayInfo();
		messi.displayInfo();
		kaka.displayInfo();
		
		kaka.attack(cr7.getName());
		cr7.takeDamage(kaka.getAttack());
	}
	{
		std::cout << BOLD "\n - - - - WHO AM I TESTS - - - - \n" RESET << std::endl;
		DiamondTrap kaka("KAKA");
		DiamondTrap kakaCopy(kaka);
		DiamondTrap dida("DIDA");

		kaka.whoAmI();
		kakaCopy.whoAmI();
		dida.whoAmI();
		
		dida = kaka;
		dida.whoAmI();
	}

}