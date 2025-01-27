#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	test1() {
	std::cout << std::endl;
	std::cout << BOLD << " - - - - - TEST 1" << " - - - - - " << RESET << std::endl;

	std::cout << BOLD YELLOW << "Testing SHRUBBERY CREATION FORM..." << RESET << std::endl;
	
	Bureaucrat marcelo("Marcelo", 1);
	AForm *form = new ShrubberyCreationForm("home");

	marcelo.signForm(*form);
	marcelo.executeForm(*form);

	delete form;
}

void	test2() {
	std::cout << std::endl;
	std::cout << BOLD << " - - - - - TEST 2" << " - - - - - " << RESET << std::endl;

	std::cout << BOLD YELLOW << "Testing ROBOTOMY REQUEST FORM..." << RESET << std::endl;

	Bureaucrat marcelo("Marcelo", 1);
	AForm *form = new RobotomyRequestForm("Claudinei");
	
	marcelo.signForm(*form);
	for (int i = 0; i < 4; i++) {
		marcelo.executeForm(*form);
	}

	delete form;
}

void	test3() {
	std::cout << std::endl;
	std::cout << BOLD << " - - - - - TEST 3" << " - - - - - " << RESET << std::endl;

	std::cout << BOLD YELLOW << "Testing PRESIDENTIAL PARDON FORM..." << RESET << std::endl;

	Bureaucrat marcelo("Marcelo", 1);
	AForm *form = new PresidentialPardonForm("Lula");
	
	marcelo.signForm(*form);
	marcelo.executeForm(*form);

	delete form;
}

void	test4() {
	std::cout << std::endl;
	std::cout << BOLD << " - - - - - TEST 4" << " - - - - - " << RESET << std::endl;

	std::cout << BOLD YELLOW << "Testing BUREAUCRAT GRADE EXCEPTIONS..." << RESET << std::endl;

	Bureaucrat marcelo("Marcelo", 150);
	AForm *form1 = new ShrubberyCreationForm("home");
	AForm *form2 = new RobotomyRequestForm("Claudinei");
	AForm *form3 = new PresidentialPardonForm("Lula");
	
	marcelo.signForm(*form1);
	marcelo.signForm(*form2);
	marcelo.signForm(*form3);

	marcelo.executeForm(*form1);
	marcelo.executeForm(*form2);
	marcelo.executeForm(*form3);

	delete form1;
	delete form2;
	delete form3;
}

void	test5() {
	std::cout << std::endl;
	std::cout << BOLD << " - - - - - TEST 5" << " - - - - - " << RESET << std::endl;

	std::cout << BOLD YELLOW << "Testing 2 SIGNATURES IN SAME FORM..." << RESET << std::endl;

	Bureaucrat marcelo("Marcelo", 1);
	AForm *form1 = new ShrubberyCreationForm("home");
	AForm *form2 = new RobotomyRequestForm("Claudinei");
	AForm *form3 = new PresidentialPardonForm("Lula");

	marcelo.signForm(*form1);
	marcelo.signForm(*form1);
	marcelo.signForm(*form2);
	marcelo.signForm(*form2);
	marcelo.signForm(*form3);
	marcelo.signForm(*form3);

	marcelo.executeForm(*form1);
	marcelo.executeForm(*form2);
	marcelo.executeForm(*form3);

	delete form1;
	delete form2;
	delete form3;
}

void	test6() {
	std::cout << std::endl;
	std::cout << BOLD << " - - - - - TEST 6" << " - - - - - " << RESET << std::endl;

	std::cout << BOLD YELLOW << "Testing BUREAUCRAT ABLE TO SIGN BUT NOT TO EXECUTE..." << RESET << std::endl;

	Bureaucrat marcelo("Marcelo", 140);
	std::cout << marcelo << std::endl;

	AForm *form1 = new ShrubberyCreationForm("home"); // to sign: 145; to exec: 137
	marcelo.signForm(*form1);
	marcelo.executeForm(*form1);
	
	marcelo.setGrade(50);
	std::cout << marcelo << std::endl;

	AForm *form2 = new RobotomyRequestForm("Claudinei");// to sign: 72; to exec: 45
	marcelo.signForm(*form2);
	marcelo.executeForm(*form2);

	marcelo.setGrade(15);
	std::cout << marcelo << std::endl;

	AForm *form3 = new PresidentialPardonForm("Lula");// to sign: 25; to exec: 5 
	marcelo.signForm(*form3);
	marcelo.executeForm(*form3);

	delete form1;
	delete form2;
	delete form3;
}

int main(){
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
}