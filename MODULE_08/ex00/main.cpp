#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

template <typename T>
void	printContainerElements(T container) {

	typename T::iterator it;

	std::cout << BOLD << "CONTAINER ELEMENTS -> ";
	for (it = container.begin(); it != container.end(); ++it){
		std::cout << YELLOW << *it << " ";
	}
	std::cout << RESET << std::endl;
}

void	testVector(void) {
	std::cout << BLUE BOLD << "\n- - - - - TEST 1: VECTOR - - - - - \n" << RESET << std::endl;

	std::vector<int> a;
	
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);

	printContainerElements(a);

	try {
		std::cout << "Looking for a 3 in container..." << std::endl;
		std::cout << GREEN BOLD << easyfind(a, 3) << RESET << std::endl;
		std::cout << "Looking for a 0 in container" << std::endl;
		std::cout << GREEN BOLD << easyfind(a, 0) << RESET << std::endl;
	}
	catch(const char *e) {
		std::cerr << RED BOLD <<"EXCEPTION CAUGHT: " << e << RESET << std::endl;
	}
}

void	testList(void) {
	std::cout << BLUE BOLD << "\n- - - - - TEST 2: LIST - - - - - \n" << RESET << std::endl;
	
	std::list<int> a;

	a.push_back(5); 
	a.push_back(75); 
	a.push_back(42);

	printContainerElements(a);
	
	try {
		std::cout << "Looking for a 42 in container..." << std::endl;
		std::cout << GREEN BOLD << easyfind(a, 42) << RESET << std::endl;
		std::cout << "Looking for a 0 in container" << std::endl;
		std::cout << GREEN BOLD << easyfind(a, 0) << RESET << std::endl;
	}
	catch(const char *e) {
		std::cerr << RED BOLD <<"EXCEPTION CAUGHT: " << e << RESET << std::endl;
	}
}

void	testDeque(void) {
	std::cout << BLUE BOLD << "\n- - - - - TEST 3: DEQUE - - - - - \n" << RESET << std::endl;
	
	std::deque<int> a;

	a.push_back(22);
	a.push_back(692);
	a.push_back(88);
	a.push_back(931);
	a.push_back(47);

	printContainerElements(a);
	
	try {
		std::cout << "Looking for a 22 in container..." << std::endl;
		std::cout << GREEN BOLD << easyfind(a, 22) << RESET << std::endl;
		std::cout << "Looking for a 0 in container" << std::endl;
		std::cout << GREEN BOLD << easyfind(a, 0) << RESET << std::endl;
	}
	catch(const char *e) {
		std::cerr << RED BOLD <<"EXCEPTION CAUGHT: " << e << RESET << std::endl;
	}
}

int main(){

	testVector();
	testList();
	testDeque();
}