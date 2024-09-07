#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include "Colors.hpp"

class AAnimal {

	protected:
		std::string type;
	
	public:
		AAnimal();
		AAnimal(const AAnimal &);
		AAnimal& operator=(const AAnimal &);
		virtual ~AAnimal(); //Destrutor deve ser virtual para que o destrutor correto seja chamado quando ha polimorfismo
		
		virtual void makeSound() const = 0; //virtual pure function, transforma a classe em abstrata.
		std::string getType() const;
	
};

#endif