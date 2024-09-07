#include "Dog.hpp"
#include "Cat.hpp"
#include "Wrong.hpp"

int main() {
	{
		std::cout << BOLD " - - - - SUBJECT TEST - - - - \n" RESET << std::endl;
		Animal *arrayOfAnimals[4] = {new Cat, new Cat, new Dog, new Dog};

		for(int i = 0; i < 4; i++) {
			arrayOfAnimals[i]->makeSound();
		}
		for (int i = 0; i < 4; i++) {
			delete(arrayOfAnimals[i]);
		}
	}
	{
		std::cout << BOLD " - - - - ADD IDEAS TO BRAIN - - - - \n" RESET << std::endl;
		Cat *cat = new Cat();
		Dog *dog = new Dog();

		cat->setBrainIdea("ola eu sou um gato");
		cat->setBrainIdea("gosto de cacar ratos");
		cat->setBrainIdea("tambem me apetece um whiskas");
		cat->setBrainIdea("tenho medo de caes grandes!!!");

		cat->displayBrainIdeas();

		dog->setBrainIdea("ola eu sou um cao");
		dog->setBrainIdea("gosto de cacar gatos laranjas");
		dog->setBrainIdea("adoro roer ossos");
		dog->setBrainIdea("hoje vou passear com meu dono :)");

		dog->displayBrainIdeas();

		Animal *arrayOfAnimals[2] = {cat, dog};
		
		arrayOfAnimals[0]->makeSound();
		arrayOfAnimals[1]->makeSound();

		delete(arrayOfAnimals[0]);
		delete(arrayOfAnimals[1]);
	}
	{
		std::cout << BOLD " - - - - ADD MORE THAN 100 IDEAS TO BRAIN - - - - \n" RESET << std::endl;
		Cat a;

		for (int i = 0; i < 103; i++) {
			a.setBrainIdea("new idea");
		}
		a.displayBrainIdeas();
	}
}