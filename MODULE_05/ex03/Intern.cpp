#include "Intern.hpp"

//DEFAULT CONSTRUCTOR
Intern::Intern() {
	std::cout << BOLD << "Intern -> Default constructor called" << RESET << std::endl;
}

//COPY CONSTRUCTOR
Intern::Intern(const Intern &src) {
	(void) src;
	std::cout << BOLD << "Intern -> Copy constructor called" << RESET << std::endl;
}

//OPERATOR ASSIGNMENT
Intern& Intern::operator=(const Intern &src) {
	if (this != &src) {
		(void) src;
		std::cout << BOLD << "Intern -> Operator assignment called" << RESET << std::endl;
	}
	return *this;
}

//DESTRUCTOR
Intern::~Intern() {
	std::cout << BOLD << "Intern -> Destructor called" << RESET << std::endl;
}

//EXCEPTION
const char *Intern::NoExistantFormException::what() const throw() {
	return "Error! The name passed as parameter does NOT match any form type!";
}

//METHODS
Form *Intern::makeShrubberyCreationForm(const std::string target) {
	return (new ShrubberyCreationForm(target));
}
Form *Intern::makeRobotomyRequestForm(const std::string target) {
	return (new RobotomyRequestForm(target));
}
Form *Intern::makePresidentialPardonForm(const std::string target) {
	return (new PresidentialPardonForm(target));
}

Form *Intern::makeForm(const std::string formName, std::string formTarget) {

	std::string formPossibleNames[3] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};
	Form *(Intern::*memberFunctions[3])(std::string formTarget) = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};

	for (int i = 0; i < 3; i++) {
		if (formName == formPossibleNames[i]) {
			std::cout << GREEN BOLD << "Intern successfully created " << formName << RESET << std::endl;
			return ((this->*memberFunctions[i])(formTarget));
		}
	}
	throw Intern::NoExistantFormException();
}