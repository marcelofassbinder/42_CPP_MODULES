#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	
	{
		std::cout << BOLD "\n - - - - REGULAR TESTS - - - - \n" RESET << std::endl;
		ClapTrap ney("NEYMAR");
		ScavTrap cr7("CRISTIANO RONALDO");
		FragTrap messi("MESSI");

		ney.attack(cr7.getName());
		cr7.takeDamage(0);
		cr7.attack(messi.getName());
		messi.beRepaired(30);
		messi.takeDamage(cr7.getAttack());
		messi.attack(ney.getName());
		ney.takeDamage(messi.getAttack());

		ney.displayInfo();
		cr7.displayInfo();
		messi.displayInfo();
	}
	{
		std::cout << BOLD "\n - - - - TEST HIGH FIVE - - - - \n" RESET << std::endl;
		FragTrap messi("MESSI");

		messi.highFivesGuys();
	}

}