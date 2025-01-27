#include "RobotomyRequestForm.hpp"

//DEFAULT CONSTRUCTOR
RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy Request Form", 72, 45){
	std::cout << CYAN << "RobotomyRequestForm -> Default constructor called" << RESET << std::endl;
}

//PARAMETRIZED CONSTRUCTOR
RobotomyRequestForm::RobotomyRequestForm(const std::string target) : Form("Robotomy Request Form", 72, 45), _target(target) {
	std::cout << CYAN << "RobotomyRequestForm -> Parametrized constructor called" << RESET << std::endl;
}

//COPY CONSTRUCTOR
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : Form(src), _target(src._target) {
	std::cout << CYAN << "RobotomyRequestForm -> Copy constructor called" << RESET << std::endl;
}

//ASSIGNMENT OPERATOR
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
	if (this != &src) {
		(void) src;
		std::cout << CYAN << "RobotomyRequestForm -> Operator Assignment called" << RESET << std::endl;
	}
	return *this;
}

//DESTRUCTOR
RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << CYAN << "RobotomyRequestForm -> Destructor called" << RESET << std::endl;
}

//GETTER
std::string	RobotomyRequestForm::getTarget() const {
	return this->_target;
}

//EXECUTE
void	RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (!this->getIsSigned())
		throw Form::FormIsNotSignedException();
	if (executor.getGrade() > this->getGradeToExec())
		throw Bureaucrat::GradeTooLowException();
	else {
		static int randomNumber = 0;
		//Drilling noises
		std::cout << BOLD << "TRRR TRRR... \nVRRRR VRRRR..." << RESET << std::endl;
		if (randomNumber % 2 == 0)
			std::cout << GREEN BOLD << this->getTarget() << " has been robotomized successfully!" << RESET << std::endl;
		else
			std::cout << RED BOLD << "Fail... " << this->getTarget() << " has  NOT been robotomized!" << RESET << std::endl;
		randomNumber++;
	}
}