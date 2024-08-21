#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"

#define BOLD "\e[1m"
#define RESET "\e[0m"

class Harl {

	public:
		Harl();
		~Harl();
		void complain(std::string level);

	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

#endif
