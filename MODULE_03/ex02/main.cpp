#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
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

	for(int i=0; i < 4; i++) {
		messi.attack(cr7.getName());
		cr7.takeDamage(messi.getAttack());
	}
	messi.highFivesGuys();
}