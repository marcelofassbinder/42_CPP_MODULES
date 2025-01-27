#include "Bureaucrat.hpp"

void	test1() {
	std::cout << std::endl;
	std::cout << BOLD << " - - - - - TEST 1" << " - - - - - " << RESET << std::endl;

	std::cout << BOLD YELLOW << "Testing CORRECT cases..." << RESET << std::endl;
	try {
		Bureaucrat messi("Messi", 10);
		Bureaucrat cr7("CR7", 25);
		std::cout << messi << std::endl;
		std::cout << cr7 << std::endl;

		Form recForm("Recruitment Form", 50, 35);
		Form copyRecForm(recForm);
		std::cout << recForm << std::endl;
		std::cout << copyRecForm << std::endl;

		messi.signForm(recForm);
		cr7.signForm(copyRecForm);

		std::cout << recForm << std::endl;
		std::cout << copyRecForm << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED BOLD << "EXCEPTION CAUGHT: " << e.what() << RESET << std::endl;
	}
}

void	test2() {
	std::cout << std::endl;
	std::cout << BOLD << " - - - - - TEST 2" << " - - - - - " << RESET << std::endl;

	std::cout << BOLD YELLOW << "Testing OUT OF RANGE constructions..." << RESET << std::endl;
	try {
		Form recForm("Recruitment Form", 151, 35);
		std::cout << recForm << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED BOLD << "EXCEPTION CAUGHT: " << e.what() << RESET << std::endl;
	}
	try {
		Form finForm("Finance Form", 0, 35);
		std::cout << finForm << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED BOLD << "EXCEPTION CAUGHT: " << e.what() << RESET << std::endl;
	}
}

void	test3() {
	std::cout << std::endl;
	std::cout << BOLD << " - - - - - TEST 3" << " - - - - - " << RESET << std::endl;

	std::cout << BOLD YELLOW << "Testing FORMS GRADES..." << RESET << std::endl;
	try {
		Bureaucrat messi("Messi", 10);
		Bureaucrat cr7("CR7", 25);
		std::cout << messi << std::endl;
		std::cout << cr7 << std::endl;

		Form recForm("Recruitment Form", 20, 35);
		Form copyRecForm(recForm);
		std::cout << recForm << std::endl;
		std::cout << copyRecForm << std::endl;

		messi.signForm(recForm);
		cr7.signForm(copyRecForm);

		std::cout << recForm << std::endl;
		std::cout << copyRecForm << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED BOLD << "EXCEPTION CAUGHT: " << e.what() << RESET << std::endl;
	}
}

void	test4() {
	std::cout << std::endl;
	std::cout << BOLD << " - - - - - TEST 4" << " - - - - - " << RESET << std::endl;
	
	std::cout << BOLD YELLOW << "Testing 2 SIGNATURES IN SAME FORM..." << RESET << std::endl;
	try {
		Bureaucrat messi("Messi", 10);
		Bureaucrat cr7("CR7", 10);
		std::cout << messi << std::endl;
		std::cout << cr7 << std::endl;

		Form recForm("Recruitment Form", 20, 35);
		std::cout << recForm << std::endl;

		messi.signForm(recForm);
		cr7.signForm(recForm);

		std::cout << recForm << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED BOLD << "EXCEPTION CAUGHT: " << e.what() << RESET << std::endl;
	}
}

int main(){
	test1();
	test2();
	test3();
	test4();
}