#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Colors.hpp"

class Animal {

	protected:
		std::string type;
	
	public:
		Animal();
		Animal(const Animal &);
		Animal& operator=(const Animal &);
		virtual ~Animal(); //Destrutor deve ser virtual para que o destrutor correto seja chamado quando ha polimorfismo
		
		virtual void makeSound() const; //funcao deve ser virtual para que o programa entenda qual makeSound chamar para ponteiros/ref. para classes derivadas de Animal
		std::string getType() const;
	
};

#endif