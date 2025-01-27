#include "ShrubberyCreationForm.hpp"

//DEFAULT CONSTRUCTOR
ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery Creation Form", 145, 137){
	std::cout << CYAN << "ShrubberyCreationForm -> Default constructor called" << RESET << std::endl;
}

//PARAMETRIZED CONSTRUCTOR
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : Form("Shrubbery Creation Form", 145, 137), _target(target) {
	std::cout << CYAN << "ShrubberyCreationForm -> Parametrized constructor called" << RESET << std::endl;
}

//COPY CONSTRUCTOR
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : Form(src), _target(src._target) {
	std::cout << CYAN << "ShrubberyCreationForm -> Copy constructor called" << RESET << std::endl;
}

//ASSIGNMENT OPERATOR
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
	if (this != &src) {
		(void) src;
		std::cout << CYAN << "ShrubberyCreationForm -> Operator Assignment called" << RESET << std::endl;
	}
	return *this;
}

//DESTRUCTOR
ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << CYAN << "ShrubberyCreationForm -> Destructor called" << RESET << std::endl;
}

//GETTER
std::string	ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

//EXECUTE
void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (!this->getIsSigned())
		throw Form::FormIsNotSignedException();
	if (executor.getGrade() > this->getGradeToExec())
		throw Bureaucrat::GradeTooLowException();
	else {
		std::ofstream newFile(this->getTarget().append("_shrubbery").c_str());
		newFile << "   *\n";
    	newFile << "  ***\n";
    	newFile << " *****\n";
    	newFile << "*******\n";
    	newFile << "   |\n";
		newFile.close();
	}
} 