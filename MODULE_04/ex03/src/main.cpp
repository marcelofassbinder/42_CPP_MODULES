#include "../includes/Character.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"

int main() {
	ICharacter* bob = new Character("BOB");
	AMateria* ice = new Ice;
	AMateria *cure = new Cure;
	Floor *floor = Floor::getInstance();

	std::cout << bob->getName() << std::endl;
	bob->equip(ice);
	bob->equip(cure);
	bob->use(0, *bob);
	bob->use(1, *bob);
	bob->unequip(0);
	bob->unequip(1);
	floor->displayFloor();
	floor->cleanFloor();
	delete(bob);
}