#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {

	public:
	//CANONICAL ORTHODOX FORM
		Intern();
		Intern(const Intern &);
		Intern& operator=(const Intern &);
		~Intern();

	//EXCEPTION
		class NoExistantFormException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	//METHODS
		Form *makeShrubberyCreationForm(const std::string target);
		Form *makeRobotomyRequestForm(const std::string target);
		Form *makePresidentialPardonForm(const std::string target);
		Form* makeForm(const std::string formName, const std::string formTarget);
};

#endif