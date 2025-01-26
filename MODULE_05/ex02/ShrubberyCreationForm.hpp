#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
	
	private:
		const std::string	_target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm&);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm&);
		~ShrubberyCreationForm();

		std::string	getTarget() const;

		void	execute(Bureaucrat const &executor) const;
};

#endif