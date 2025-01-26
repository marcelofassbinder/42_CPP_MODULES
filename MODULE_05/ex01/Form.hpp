#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExec;

	public:
	//ORTHODOX CANONICAL FORM
		Form();
		Form(const std::string name, const int gradeToSign, const int gradeToExec);
		Form(const Form&);
		Form& operator=(const Form&);
		~Form();

	//EXCEPTIONS CLASSES
		class GradeTooHighException: public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class FormIsAlreadySignedException: public std::exception {
			public:
				virtual const char *what() const throw();
		};

	//GETTERS
		const std::string	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;
	
	//METHODS
		void	beSigned(Bureaucrat&);

};

std::ostream &operator<<(std::ostream&, const Form&);

#endif