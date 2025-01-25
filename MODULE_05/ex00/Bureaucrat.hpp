#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

//COLORS
#define RED "\e[31m"
#define BLUE "\e[34m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BOLD "\e[1m"
#define RESET "\e[0m"

class Bureaucrat {

	private:
		const std::string	_name;
		int					_grade;

	public:
		//ORTHODOX CANONICAL FORM
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat&);
		Bureaucrat& operator=(const Bureaucrat&);
		~Bureaucrat();

		//EXCEPTIONS CLASSES
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		//METHODS
		const std::string	getName() const;
		int					getGrade() const;
		void				setGrade(int);
		void				incrementGrade();
		void				decrementGrade();

};
	//OPERATOR OVERLOAD
	std::ostream &operator<<(std::ostream &output, const Bureaucrat &obj);

#endif