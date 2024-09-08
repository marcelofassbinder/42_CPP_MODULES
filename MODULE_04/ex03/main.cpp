#include "Character.hpp"
#include "Ice.hpp"

int main() {
	ICharacter* bob = new Character("BOB");
	AMateria* ice = new Ice;
	AMateria *a = ice;

	std::cout << bob->getName() << std::endl;
	bob->equip(ice);
	bob->equip(a);
	bob->use(0, *bob);
	bob->use(1, *bob);
	bob->unequip(0);
	delete(bob);
}