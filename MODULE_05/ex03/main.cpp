#include "Intern.hpp"

void	test1() {
	std::cout << std::endl;
	std::cout << BOLD << " - - - - - TEST 1" << " - - - - - " << RESET << std::endl;

	std::cout << BOLD YELLOW << "Testing SHRUBBERY CREATION FORM..." << RESET << std::endl;
	try {
		Bureaucrat marcelo("Marcelo", 1);
		Intern randomIntern;
		Form *newForm;

		newForm = randomIntern.makeForm("Shrubbery Creation", "home");
		marcelo.signForm(*newForm);
		marcelo.executeForm(*newForm);

		delete newForm;
	}
	catch(std::exception &e) {
		std::cerr << RED BOLD << "EXCEPTION CAUGHT: " << e.what() << RESET << std::endl;
	}
}

void	test2() {
	std::cout << std::endl;
	std::cout << BOLD << " - - - - - TEST 2" << " - - - - - " << RESET << std::endl;

	std::cout << BOLD YELLOW << "Testing ROBOTOMY REQUEST FORM..." << RESET << std::endl;
	try {
		Bureaucrat marcelo("Marcelo", 1);
		Intern randomIntern;
		Form *newForm;

		newForm = randomIntern.makeForm("Robotomy Request", "Vini Jr");
		marcelo.signForm(*newForm);
		marcelo.executeForm(*newForm);

		delete newForm;
	}
	catch(std::exception &e) {
		std::cerr << RED BOLD << "EXCEPTION CAUGHT: " << e.what() << RESET << std::endl;
	}
}

void	test3() {
	std::cout << std::endl;
	std::cout << BOLD << " - - - - - TEST 3" << " - - - - - " << RESET << std::endl;

	std::cout << BOLD YELLOW << "Testing PRESIDENTIAL PARDON FORM..." << RESET << std::endl;
	try {
		Bureaucrat marcelo("Marcelo", 1);
		Intern randomIntern;
		Form *newForm;

		newForm = randomIntern.makeForm("Presidential Pardon", "Mbappe");
		marcelo.signForm(*newForm);
		marcelo.executeForm(*newForm);	

		delete newForm;
	}
	catch(std::exception &e) {
		std::cerr << RED BOLD << "EXCEPTION CAUGHT: " << e.what() << RESET << std::endl;
	}
}

void	test4() {
	std::cout << std::endl;
	std::cout << BOLD << " - - - - - TEST 4" << " - - - - - " << RESET << std::endl;

	std::cout << BOLD YELLOW << "Testing EXCEPTION..." << RESET << std::endl;
	try {
		Bureaucrat marcelo("Marcelo", 1);
		Intern randomIntern;
		Form *newForm;

		newForm = randomIntern.makeForm("Non Existant Form", "Mbappe");
		marcelo.signForm(*newForm);	// this will not be executed
		marcelo.executeForm(*newForm);	// this will not be executed

		delete newForm;
	}
	catch(std::exception &e) {
		std::cerr << RED BOLD << "EXCEPTION CAUGHT: " << e.what() << RESET << std::endl;
	}
}

int main(){
	test1();
	test2();
	test3();
	test4();
}
