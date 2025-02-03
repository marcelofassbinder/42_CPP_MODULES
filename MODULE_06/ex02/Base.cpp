#include "Base.hpp"

//DESTRUCTOR
Base::~Base() {}

Base	*generate(void) {


	int randomNumber = std::rand() % 3; // generates a value from 0 to 2

	switch (randomNumber)
	{
		case 0:
			return new A();
		case 1:
			return new B();	
		case 2:
			return new C();
		default:
			return NULL;
	}
}

void	identify(Base *p) {
	
	std::cout << "The derived class is -> ";

	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base &p) {

	std::cout << "The derived class is -> ";

	try {
		A &ARef= dynamic_cast<A&>(p);
		(void) ARef;
		std::cout << "A" << std::endl;
	}
	catch(std::exception &e) {}
	try {
		B &BRef= dynamic_cast<B&>(p);
		(void) BRef;
		std::cout << "B" << std::endl;
	}
	catch(std::exception &e) {}
	try {
		C &CRef= dynamic_cast<C&>(p);
		(void) CRef;
		std::cout << "C" << std::endl;
	}
	catch(std::exception &e) {}
}