#include "Zombie.hpp"

void randomChump(std::string name) {
	Zombie z2;

	z2.setZombieName(name);
	z2.announce();
}