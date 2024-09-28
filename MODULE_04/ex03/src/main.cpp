#include "../includes/Character.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/MateriaSource.hpp"

int subjectTest(void) {
	std::cout << BOLD " - - - - SUBJECT TEST - - - - \n" RESET << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}

int floorTest(void) {
	
	std::cout << BOLD "\n - - - - FLOOR TEST - - - - \n" RESET << std::endl;
	ICharacter* kenan = new Character("Kenan");
	ICharacter* kel = new Character("Kel");
	AMateria *ice = new Ice;
	AMateria *cure = new Cure;
	Floor *floor = Floor::getInstance();

	kenan->equip(ice);
	kenan->equip(cure);
	kenan->use(0, *kel);
	kenan->use(1, *kenan);
	kenan->unequip(0);
	kenan->unequip(1);

	kel->equip(cure);
	kel->use(0, *kel);

	floor->displayFloor();
	floor->cleanFloorMaterias();
	delete(kenan);
	delete(kel);
	
	return 0;
}

int unexistingMateriaTest(void) {
	std::cout << BOLD "\n - - - - UNEXISTING MATERIA TEST - - - - \n" RESET << std::endl;
	ICharacter* kenan = new Character("Kenan");
	AMateria* ice = NULL;
	
	kenan->equip(ice);
	kenan->use(0, *kenan);
	kenan->use(1, *kenan);
	kenan->unequip(0);

	delete(kenan);

	return 0;
}

int main() {
	subjectTest();
	floorTest();
	unexistingMateriaTest();	
}