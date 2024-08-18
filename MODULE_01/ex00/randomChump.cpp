#include "Zombie.hpp"

void randomChump(std::string name) {
	Zombie z;

	z.setZombieName(name);
	z.announce();
}