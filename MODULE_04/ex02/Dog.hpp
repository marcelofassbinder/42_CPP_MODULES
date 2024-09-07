#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Colors.hpp"

class Dog : public AAnimal {

	private:
		Brain* brain;

	public:
		Dog();
		Dog(const Dog&);
		Dog& operator=(const Dog&);
		~Dog();

		void makeSound() const;
		//NEW FUNCTIONS
		std::string* getBrainIdeas();
		void setBrainIdea(std::string);
		void displayBrainIdeas();
};

#endif