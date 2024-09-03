#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

	public:
		//CANONICAL FORM
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap&);
		FragTrap& operator=(const FragTrap&);
		~FragTrap();

		//MEMBER FUNCTIONS
		void highFivesGuys();

};

#endif