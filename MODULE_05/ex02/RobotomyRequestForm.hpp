#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <stdlib.h> //for std::rand()

class RobotomyRequestForm : public AForm {
	
	private:
		const std::string	_target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm&);
		RobotomyRequestForm &operator=(const RobotomyRequestForm&);
		~RobotomyRequestForm();

		std::string	getTarget() const;

		void	execute(Bureaucrat const &executor) const;
};

#endif