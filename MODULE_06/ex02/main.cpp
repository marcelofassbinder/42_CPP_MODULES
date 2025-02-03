
#include "Base.hpp"

int main() {

	std::srand(static_cast<unsigned int>(std::time(0))); //starts the generator seed
	{
		std::cout << " - - - TEST 1: DYNAMIC CAST WITH POINTER - - - " << std::endl;
		Base *ptr = generate();

		identify(ptr);

		delete ptr;
	}
	std::cout << std::endl;
	{
		std::cout << " - - - TEST 2: DYNAMIC CAST WITH REFERENCE - - - " << std::endl;
		Base *ref = generate();
		
		identify(ref);

		delete ref;
	}
	std::cout << std::endl;
	{
		std::cout << " - - - TEST 3: DYNAMIC CAST WITH POINTER AND REFERENCE - - - " << std::endl;
		Base *ptr = generate();
		Base &ref = *ptr;
		
		std::cout << "IDENTIFY BY POINTER: " << std::endl;
		identify(ptr);
		
		std::cout << "IDENTIFY BY REFERENCE: " << std::endl;
		identify(ref);

		delete ptr;

	}
}