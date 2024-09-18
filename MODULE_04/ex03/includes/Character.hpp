#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "Floor.hpp"

class Character : public ICharacter {

	private:
		AMateria*	_inventory[4];
		std::string	_name;

	public: 
		//CANONICAL FORM
		Character();
		Character(std::string const &name);
		Character(const Character&);
		Character& operator=(const Character&);
		~Character();
		
		//METHODS 
		std::string const& getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
		void copyInventory(const Character&);
		void displayInventory();
		bool checkMateriaInInventory(const AMateria&);
};

#endif