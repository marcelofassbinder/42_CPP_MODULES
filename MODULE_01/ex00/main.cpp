#include "Zombie.hpp"

int main(void) {
	Zombie *z1 = newZombie("Leandro");
	randomChump("Leonardo");

	z1->announce();
	delete(z1);
}