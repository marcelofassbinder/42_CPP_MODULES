#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include "iostream"

#define RED "\e[31m"
#define BLUE "\e[34m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"

#define BOLD "\e[1m"
#define BLINK "\e[5m"
#define RESET "\e[0m"

class ClapTrap {

	private:
		std::string _name;
		int 		_hitPoints;
		int 		_energyPoints;
		int 		_attackDamage;

	public:
		//- - - - CANONICAL FORM - - - - -
		ClapTrap();
		ClapTrap(std::string);
		ClapTrap(const ClapTrap&);
		ClapTrap& operator=(const ClapTrap&);
		~ClapTrap();

		//GETTERS
		std::string getName(void) const;
		int 		getHit(void) const;
		int 		getEnergy(void) const;
		int 		getAttack(void) const;

		// - - - - - MEMBER FUNCTIONS - - - - -
		void		 attack(const std::string& target);
		void 		takeDamage(unsigned int amount);
		void 		beRepaired(unsigned int amount);
		void		displayInfo();

};

#endif