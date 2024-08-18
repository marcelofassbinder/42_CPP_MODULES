#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

#define BOLD "\e[1m"
#define RESET "\e[0m"
#define RED "\e[31m"
#define BLUE "\e[34m"

class Zombie{
	private:
		std::string name;
	public:
		Zombie();
		~Zombie();
		void announce(void);
		void setZombieName(std::string name);
};

#endif