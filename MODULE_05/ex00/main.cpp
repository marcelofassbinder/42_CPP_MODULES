#include "Bureaucrat.hpp"

void	test1() {
	std::cout << std::endl;
	std::cout << BOLD << " - - - - - TEST 1" << " - - - - - " << RESET << std::endl;

	std::cout << BOLD YELLOW << "Testing CORRECT constructions..." << RESET << std::endl;
	try {
		Bureaucrat a("luisito suarez", 1);
		Bureaucrat b("carlitos tevez", 87);
		Bureaucrat c("samuel etoo", 150);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
	}
	catch(std::exception& e) {
		std::cerr << RED << "EXCEPTION CAUGHT: " << e.what() << RESET << std::endl;
	}
}

void	test2() {
	std::cout << std::endl;
	std::cout << BOLD << " - - - - - TEST 2" << " - - - - - " << RESET << std::endl;

	std::cout << BOLD YELLOW << "Testing OUT OF RANGE constructions..." << RESET << std::endl;
	try {
		Bureaucrat a("luisito suarez", 0);
	}
	catch(std::exception& e) {
		std::cerr << RED << "EXCEPTION CAUGHT: " << e.what() << RESET << std::endl;
	}
	try {
		Bureaucrat b("carlitos tevez", 152);
	}
	catch(std::exception &e) {
		std::cerr << RED << "EXCEPTION CAUGHT: " << e.what() << RESET << std::endl;
	}
}

void	test3() {
	std::cout << std::endl;
	std::cout << BOLD << " - - - - - TEST 3" << " - - - - - " << RESET << std::endl;

	std::cout << BOLD YELLOW << "Testing INCREMENT EXCEPTIONS..." << RESET << std::endl;
	try {
		Bureaucrat a("superman", 15);
		std::cout << a << std::endl;
		for (int i = 0; i < 20; i++) {
			a.incrementGrade();
		}
	}
	catch(std::exception& e) {
		std::cerr << RED << "EXCEPTION CAUGHT: " << e.what() << RESET << std::endl;
	}
}

void	test4() {
	std::cout << std::endl;
	std::cout << BOLD << " - - - - - TEST 4" << " - - - - - " << RESET << std::endl;
	
	std::cout << BOLD YELLOW << "Testing DECREMENT EXCEPTIONS..." << RESET << std::endl;
	try {
		Bureaucrat a("spiderman", 140);
		std::cout << a << std::endl;
		for (int i = 0; i < 20; i++) {
			a.decrementGrade();
		}
	}
	catch(std::exception& e) {
		std::cerr << RED << "EXCEPTION CAUGHT: " << e.what() << RESET << std::endl;
	}
}
int main(){
	test1();
	test2();
	test3();
	test4();
}