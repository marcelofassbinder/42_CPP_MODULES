
#include "Serializer.hpp"


//uintptr_t is the data type able to store the value of a pointer(any kind and size), in an unsigned int.
int main() {

	Data *a = new Data();

	std::cout << "original pointer adress: " << a << std::endl;

	uintptr_t u = Serializer::serialize(a);
	std::cout << "serialize = " << u << std::endl;
	
	Data *ptr = Serializer::deserialize(u);
	std::cout << "deserialize = " << ptr << std::endl;

	delete a;

}