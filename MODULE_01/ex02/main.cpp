#include <iostream>

int main(void) {
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "memory address of string variable: " << &string << std::endl;
	std::cout << "memory address of stringPTR: " << stringPTR << std::endl;
	std::cout << "memory address of stringREF: " << &stringREF << std::endl;

	std::cout << "\nvalue of string variable = " << string << std::endl;
	std::cout << "value of stringPTR = " << *stringPTR << std::endl;
	std::cout << "value of stringREF = " << stringREF << std::endl;
}