#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(){
	AForm *a = new ShrubberyCreationForm("home");
	AForm *b = new RobotomyRequestForm("Messi");
	Bureaucrat messi("messi", 1);

	messi.signForm(*a);
	messi.signForm(*b);
	messi.executeForm(*a);
	messi.executeForm(*b);
}