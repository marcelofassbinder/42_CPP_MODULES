#include "Dog.hpp"
#include "Cat.hpp"
#include "Wrong.hpp"

int main() {
	{
		std::cout << BOLD "- - - - SUBJECT TEST - - - - \n" RESET << std::endl;
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		j->makeSound();
		i->makeSound();
		meta->makeSound();

		delete(meta);
		delete(j);
		delete(i);
	}
	{
		std::cout << BOLD "\n- - - - WRONG ANIMAL TEST - - - - \n" RESET << std::endl;
		const WrongAnimal *a = new WrongAnimal();
		const WrongAnimal *b = new WrongCat();

		std::cout << "a->getType() -> " << a->getType() << std::endl;
		std::cout << "b->getType() -> " << b->getType() << std::endl;

		std::cout << "a->makeSound() -> ";
		a->makeSound();
		std::cout << "b->makeSound() -> ";
		b->makeSound();

		delete(a);
		delete(b);
	}
	{
		std::cout << BOLD "\n- - - - MY TEST - - - - \n" RESET << std::endl;
		Animal *a = new Dog();
		Animal *b = a;
		Dog c;
		Animal *d = new Dog(c);
		//Dog *c = new Animal();// erro de compilacao
		
		std::cout << "a->getType() -> " << a->getType() << std::endl;
		std::cout << "b->getType() -> " << b->getType() << std::endl;
		std::cout << "c.getType() -> " << c.getType() << std::endl;
		std::cout << "d->getType() -> " << d->getType() << std::endl;
		std::cout << "a->makeSound() -> ";
		a->makeSound();
		std::cout << "b->makeSound() -> ";
		b->makeSound();
		std::cout << "c.makeSound() -> ";
		c.makeSound();
		std::cout << "d.makeSound() -> ";
		d->makeSound();

		delete(a);
		delete(d);
	}
}