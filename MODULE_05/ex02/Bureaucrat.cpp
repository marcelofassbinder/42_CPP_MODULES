#include "Bureaucrat.hpp"

//DEFAULT CONSTRUCTOR
Bureaucrat::Bureaucrat() : _name("Default Name"), _grade(150) {
	std::cout << BLUE << "Bureaucrat -> Default constructor called" << RESET << std::endl;
}

//COPY CONSTRUCTOR
Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade){
	std::cout << BLUE << "Bureaucrat -> Copy constructor called" <<  RESET << std::endl;
}

//PARAMETRIZED CONSTRUCTOR
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	std::cout << BLUE << "Bureaucrat -> Parametrized constructor called" <<  RESET << std::endl;
	if (this->_grade < 1) {
		throw GradeTooHighException();
	}
	else if (this->_grade > 150) {
		throw GradeTooLowException();
	}
} 

//ASSIGNMENT OPERATOR
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src) {
	
	if (this != &src) {
		this->_grade = src._grade;
		std::cout << BLUE << "Bureaucrat -> Assignment operator called" <<  RESET << std::endl;
	}
	return (*this);
}

//DESTRUCTOR
Bureaucrat::~Bureaucrat() {
	std::cout << BLUE << "Bureaucrat -> Destructor called" <<  RESET << std::endl;
}

//EXCEPTIONS
const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Bureaucrat Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Bureaucrat Grade is too low!";
}

//METHODS
const std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void	Bureaucrat::setGrade(int new_grade) {
	this->_grade = new_grade;
	if (this->_grade < 1)
		throw GradeTooHighException();
	else if (this->_grade > 150)
		throw GradeTooLowException();
}

void	Bureaucrat::incrementGrade() {
	std::cout << GREEN << this->getName() << " incremented the grade from " << this->getGrade() << " to " << this->getGrade() - 1 << RESET << std::endl;
	this->_grade--;
	if (this->_grade < 1)
		throw GradeTooHighException();
}

void	Bureaucrat::decrementGrade() {
	std::cout << GREEN << this->getName() << " decremented the grade from " << this->getGrade() << " to " << this->getGrade() + 1 << RESET << std::endl;
	this->_grade++;
	if (this->_grade > 150)
		throw GradeTooLowException();
}

//FORM RELATED METHODS
void	Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
	}
	catch (std::exception &e) {
		std::cerr << RED BOLD << "EXCEPTION CAUGHT: Bureaucrat " << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << RESET << std::endl;
		return ;
	}
	std::cout << GREEN << "Bureaucrat " << this->getName() << " signed " << form.getName() << RESET << std::endl;
}

void	Bureaucrat::executeForm(AForm const &form){
	try {
		form.execute(*this);
	}
	catch (std::exception &e) {
		std::cerr << RED BOLD<< "EXCEPTION CAUGHT: Bureaucrat " << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << RESET << std::endl;
		return ;
	}
	std::cout << GREEN << "Bureaucrat " << this->getName() << " executed " << form.getName() << RESET << std::endl;
}

//OPERATOR OVERLOAD
std::ostream &operator<<(std::ostream &output, const Bureaucrat &obj) {
	output << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return output;
}