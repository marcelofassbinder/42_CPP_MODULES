#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include "Colors.hpp"

class Brain {

	private:
		std::string ideas[100];

	public:
		//CANONICAL FORM
		Brain();
		Brain(const Brain&);
		Brain& operator=(const Brain&);
		~Brain();

		//GETTER FUNCTION
		std::string *getIdeas();

		//SETTER FUNCTION
		void setIdea(std::string);

		//METHODS
		void copyIdeas(const Brain&);
		void displayIdeas();
};

#endif