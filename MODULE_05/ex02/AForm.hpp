/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:28:40 by mfassbin          #+#    #+#             */
/*   Updated: 2025/01/26 17:38:41 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExec;

	public:
	//ORTHODOX CANONICAL AForm
		AForm();
		AForm(const std::string name, const int gradeToSign, const int gradeToExec);
		AForm(const AForm&);
		AForm& operator=(const AForm&);
		virtual ~AForm();

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
		class FormIsNotSignedException: public std::exception {
			public:
				virtual const char *what() const throw();
		};

	//GETTERS
		const std::string	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;
	
	//METHODS
		void				beSigned(Bureaucrat&);

	//VIRTUAL PURE FUNCTION
		virtual void		execute(Bureaucrat const &executor) const = 0;

};

std::ostream &operator<<(std::ostream&, const AForm&);

#endif