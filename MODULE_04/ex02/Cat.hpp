#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Colors.hpp"

class Cat : public AAnimal {

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