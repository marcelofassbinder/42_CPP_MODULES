#include "PresidentialPardonForm.hpp"

//DEFAULT CONSTRUCTOR
PresidentialPardonForm::PresidentialPardonForm() : Form("Presidential Pardon Form", 25, 5){
	std::cout << CYAN << "PresidentialPardonForm -> Default constructor called" << RESET << std::endl;
}

//PARAMETRIZED CONSTRUCTOR
PresidentialPardonForm::PresidentialPardonForm(const std::string target) : Form("Presidential Pardon Form", 25, 5), _target(target) {
	std::cout << CYAN << "PresidentialPardonForm -> Parametrized constructor called" << RESET << std::endl;
}

//COPY CONSTRUCTOR
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : Form(src), _target(src._target) {
	std::cout << CYAN << "PresidentialPardonForm -> Copy constructor called" << RESET << std::endl;
}

//ASSIGNMENT OPERATOR
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
	if (this != &src) {
		(void) src;
		std::cout << CYAN << "PresidentialPardonForm -> Operator Assignment called" << RESET << std::endl;
	}
	return *this;
}

//DESTRUCTOR
PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << CYAN << "PresidentialPardonForm -> Destructor called" << RESET << std::endl;
}

//GETTER
std::string	PresidentialPardonForm::getTarget() const {
	return this->_target;
}

//EXECUTE
void	PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (!this->getIsSigned())
		throw Form::FormIsNotSignedException();
	if (executor.getGrade() > this->getGradeToExec())
		throw Bureaucrat::GradeTooLowException();
	else {
		std::cout << BLUE BOLD << this->getTarget() << " has been pardoned by Zaphod Beeblebrox!" << RESET << std::endl;
	}
}