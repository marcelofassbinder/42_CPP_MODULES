#include <iostream>
#include "Array.hpp"

void	testIntArray(void) {
	std::cout << BOLD << "\nTEST 1 : ARRAY OF INTEGERS" << RESET << std::endl;

	Array<int> a(5);

	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	try {
		a.printArray();
	}
	catch(std::exception &e) {
		std::cout << RED BOLD << e.what() << RESET << std::endl;
	}
}

void	testCharArray(void) {
	std::cout << BOLD << "\nTEST 2 : ARRAY OF CHARS" << RESET << std::endl;

	Array<char> a(5);

	a[0] = 'o';
	a[1] = 'l';
	a[2] = 'a';

	try {
		a.printArray();
	}
	catch(std::exception &e) {
		std::cout << RED BOLD << e.what() << RESET << std::endl;
	}
}

void	testDoubleArray(void) {
	std::cout << BOLD << "\nTEST 3 : ARRAY OF DOUBLES" << RESET << std::endl;

	Array<double> a(5);

	a[0] = 3.4;
	a[1] = 9.76;
	a[2] = 88.9712;

	try {		
		a.printArray();
	}
	catch(std::exception &e) {
		std::cout << RED BOLD << e.what() << RESET << std::endl;
	}
}

void	testStringArray(void) {
	std::cout << BOLD << "\nTEST 4 : ARRAY OF STRINGS" << RESET << std::endl;

	Array<std::string> a(5);

	a[0] = "ola";
	a[1] = "tudo";
	a[2] = "bem?";

	try {
		a.printArray();
	}
	catch(std::exception &e) {
		std::cout << RED BOLD << e.what() << RESET << std::endl;
	}
}

void	testException1(void) {
	std::cout << BOLD << "\nTEST 5 : TESTING EXCEPTION: PRINT INVALID ELEMENT" << RESET << std::endl;

	Array<int> a(5);

	try {
		std::cout << a[7] << std::endl;
	}
	catch(std::exception &e) {
		std::cout << "EXCEPTION CAUGHT: " << RED BOLD << e.what() << RESET << std::endl;
	}
}

void	testException2(void) {
	std::cout << BOLD << "\nTEST 6 : TESTING EXCEPTION 2: MODIFY INVALID ELEMENT" << RESET << std::endl;

	Array<int> a(2);

	try {
		a[0] = 1;
		a[1] = 2;
		a[2] = 3;
		a.printArray();
	}
	catch(std::exception &e) {
		std::cout << "EXCEPTION CAUGHT: " << RED BOLD << e.what() << RESET << std::endl;
	}
}

int main() {
	testIntArray();
	testCharArray();
	testDoubleArray();
	testStringArray();
	testException1();
	testException2();
}