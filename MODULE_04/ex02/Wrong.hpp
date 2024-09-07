#ifndef WRONG_HPP
#define WRONG_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Colors.hpp"

class WrongAnimal {

	protected:
		std::string type;
	
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &);
		WrongAnimal& operator=(const WrongAnimal &);
		~WrongAnimal();
		
		void makeSound() const;
		std::string getType() const;
	
};

class WrongCat : public WrongAnimal {

	public:
		WrongCat();
		WrongCat(const WrongCat&);
		WrongCat& operator=(const WrongCat&);
		~WrongCat();

		void makeSound() const;
};

#endif