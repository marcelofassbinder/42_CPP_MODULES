#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>

class RPN {

	private:
		static std::stack<int>	_stack;

		RPN();
		RPN(const RPN&);
		RPN& operator=(const RPN&);
		~RPN();

	public:
		static void calculate(const char* args);
};

//AUXILIAR FUNCTIONS
bool	checkInput(std::string input);
void	printError(std::string error);
void	doOperation(char op, std::stack<int> &s);


#endif