#include "AForm.hpp"

//DEFAULT CONSTRUCTOR
AForm::AForm() : _name("Default AAForm"), _isSigned(false), _gradeToSign(1), _gradeToExec(1) {
	std::cout << YELLOW << "AAForm -> Default constructor called" << RESET << std::endl;
}

//PARAMETRIZED CONSTRUCTOR
AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	std::cout << YELLOW << "AForm -> Parametrized constructor called" << RESET << std::endl;
	if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw GradeTooHighException();
	else if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw GradeTooLowException();

}

//COPY CONSTRUCTOR
AForm::AForm(const AForm &src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec) {
	std::cout << YELLOW << "AForm -> Copy constructor called" << RESET << std::endl;
}

//ASSIGNMENT OPERATOR
AForm& AForm::operator=(const AForm &src) {
	if (this != &src) {
		this->_isSigned = src._isSigned;
		std::cout << YELLOW << "AForm -> Operator Assignment called" << RESET << std::endl;
	}
	return *this;
}

//EXCEPTIONS
const char *AForm::GradeTooHighException::what() const throw() {
	return "Form grade is too High!";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Form grade is too Low!";
}

const char *AForm::FormIsAlreadySignedException::what() const throw() {
	return "The Form has already been signed!";
}

const char *AForm::FormIsNotSignedException::what() const throw() {
	return "The Form is not signed!";
}

//DESTRUCTOR
AForm::~AForm() {
	std::cout << YELLOW << "AForm -> Destructor called" << RESET << std::endl;
}

//GETTERS
const std::string AForm::getName() const {
	return this->_name;
}

bool AForm::getIsSigned() const {
	return this->_isSigned;
}

int AForm::getGradeToSign() const {
	return this->_gradeToSign;
}

int AForm::getGradeToExec() const {
	return this->_gradeToExec;
}

//METHOD
void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (this->getIsSigned() == true)
		throw AForm::FormIsAlreadySignedException();
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooHighException();
	else
		this->_isSigned = true;
}

//VIRTUAL PURE FUNCTION
void	AForm::execute(const Bureaucrat &executor) const {
	(void) executor;
	/* if (this->getIsSigned() == true && executor.getGrade() <= this->getGradeToExec())
		//CONTINUAR FUNCAO */
}


//OPERATOR OVERLOAD
std::ostream &operator<<(std::ostream &out, const AForm &AForm) {
	out << "AForm NAME: " << AForm.getName() << std::endl;
	out << "IS THE AForm SIGNED? " << std::boolalpha << AForm.getIsSigned() << std::endl;
	out << "GRADE REQUIRED TO SIGN: " << AForm.getGradeToSign() << std::endl;
	out << "GRADE REQUIRED TO EXECUTE: " << AForm.getGradeToExec() << std::endl;

	return out;
}
