#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	
	private:
		const std::string	_target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm&);
		PresidentialPardonForm &operator=(const PresidentialPardonForm&);
		~PresidentialPardonForm();

		std::string	getTarget() const;

		void	execute(Bureaucrat const &executor) const;
};


#endif