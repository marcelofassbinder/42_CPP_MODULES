#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include "Colors.hpp"

class Cat : public Animal {

	private:
		Brain* brain;

	public:
		Cat();
		Cat(const Cat&);
		Cat& operator=(const Cat&);
		~Cat();

		void makeSound() const;
		// NEW FUNCTIONS
		std::string* getBrainIdeas();
		void	setBrainIdea(std::string);
		void	displayBrainIdeas();
};

#endif