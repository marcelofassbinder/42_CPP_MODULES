#include "Form.hpp"

//DEFAULT CONSTRUCTOR
Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(1), _gradeToExec(1) {
	std::cout << YELLOW << "Form -> Default constructor called" << RESET << std::endl;
}

//PARAMETRIZED CONSTRUCTOR
Form::Form(const std::string name, const int gradeToSign, const int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	std::cout << YELLOW << "Form -> Parametrized constructor called" << RESET << std::endl;
	if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw GradeTooHighException();
	else if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw GradeTooLowException();

}

//COPY CONSTRUCTOR
Form::Form(const Form &src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec) {
	std::cout << YELLOW << "Form -> Copy constructor called" << RESET << std::endl;
}

//ASSIGNMENT OPERATOR
Form& Form::operator=(const Form &src) {
	if (this != &src) {
		this->_isSigned = src._isSigned;
		std::cout << YELLOW << "Form -> Operator Assignment called" << RESET << std::endl;
	}
	return *this;
}

//DESTRUCTOR
Form::~Form() {
	std::cout << YELLOW << "Form -> Destructor called" << RESET << std::endl;
}

//EXCEPTIONS
const char *Form::GradeTooHighException::what() const throw() {
	return "Form grade is too High!";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Form grade is too Low!";
}

const char *Form::FormIsAlreadySignedException::what() const throw() {
	return "The Form has already been signed!";
}

//GETTERS
const std::string Form::getName() const {
	return this->_name;
}

bool Form::getIsSigned() const {
	return this->_isSigned;
}

int Form::getGradeToSign() const {
	return this->_gradeToSign;
}

int Form::getGradeToExec() const {
	return this->_gradeToExec;
}

//METHOD
void Form::beSigned(Bureaucrat &bureaucrat) {
	if (this->getIsSigned() == true)
		throw Form::FormIsAlreadySignedException();
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw Form::GradeTooHighException();
	else
		this->_isSigned = true;
}


//OPERATOR OVERLOAD
std::ostream &operator<<(std::ostream &out, const Form &form) {
	out << "FORM NAME: " << form.getName() << std::endl;
	out << "IS THE FORM SIGNED? " << std::boolalpha << form.getIsSigned() << std::endl;
	out << "GRADE REQUIRED TO SIGN: " << form.getGradeToSign() << std::endl;
	out << "GRADE REQUIRED TO EXECUTE: " << form.getGradeToExec() << std::endl;

	return out;
}
