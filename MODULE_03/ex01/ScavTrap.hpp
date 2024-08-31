#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	public:
		// ORTHODOX CANONICAL FORM
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap&);
		ScavTrap& operator=(const ScavTrap&);
		~ScavTrap();

		// MEMBER FUNCTIONS
		void attack(const std::string& target);
		void guardGate();
};

#endif