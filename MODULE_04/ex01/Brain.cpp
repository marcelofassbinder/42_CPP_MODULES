#include "Brain.hpp"

//ORTHODOX CANONICAL FORM
Brain::Brain() {
	std::cout << "Brain-> Default constructor called\n" << std::endl;
}

Brain::Brain(const Brain &src) {
	std::cout << "Brain-> Copy constructor called" << std::endl;
	this->copyIdeas(src);
}

Brain& Brain::operator=(const Brain &src) {
	
	if (this!= &src) {
		std::cout << "Brain-> Copy assignment operator called" << std::endl;
		this->copyIdeas(src);
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain-> Destructor operator called" << std::endl;
}

//GETTER
std::string*	Brain::getIdeas() {
	return (this->ideas);
}

//SETTER
void	Brain::setIdea(std::string newIdea) {
	
	if (newIdea.empty()){
		std::cout << "Please insert a valid idea" << std::endl;
		return ;
	}

	int i = 0;

	while(i < 100 && !this->ideas[i].empty()){
		i++;
	}
	if (i < 100){
		this->ideas[i] = newIdea;
		std::cout << BOLD MAGENTA "New idea '" << newIdea << "' added to the brain" << std::endl;
		std::cout << "There are still " << 100 - 1 - i << " spaces left.\n" RESET << std::endl;
	}
	else
		std::cout << BOLD RED "Brain is FULL!! No space for new ideas.\n" RESET << std::endl;
}

// METHODS
void 	Brain::copyIdeas(const Brain &src) {

	for (int i = 0; i < 100; i++) {
		this->ideas[i] = src.ideas[i];
	}
}

void	Brain::displayIdeas() {
	
	int i = 0;

	while(!this->ideas[i].empty()) {
		std::cout << "IDEA "<< i + 1 << " -> " BOLD GREEN << this->ideas[i] << RESET "\n" << std::endl;
		i++;
		if (i == 100)
			break;
	}
	if (i == 0)
		std::cout << "Brain is EMPTY! Please add an idea" << std::endl;
}
