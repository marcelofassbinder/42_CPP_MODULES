#include "RPN.hpp"

std::stack<int> RPN::_stack;

RPN::RPN() {}

RPN::RPN(const RPN &src) {(void) src;}

RPN& RPN::operator=(const RPN &src) {
	(void) src;
	return *this;
}

RPN::~RPN() {}

void RPN::calculate(const char *args) {

	std::string validOperators("+-/*");
	std::string input(args);
	if (!checkInput(input))
		return (printError("Wrong input"));
	for (std::string::iterator it = input.begin(); it != input.end(); it++) {
		if (std::isdigit(*it))
			RPN::_stack.push(*it - '0');
		else if (validOperators.find(*it) != validOperators.npos) {
			if (RPN::_stack.size() < 2)
				return (printError("Invalid synthax"));
			doOperation(*it, RPN::_stack);
		}
	}
	if (RPN::_stack.size() == 1)
		std::cout << RPN::_stack.top() << std::endl;
	else
		printError("Invalid synthax");
}

void	doOperation(char op, std::stack<int> &s) {
	
	int n1, n2, result;
	n1 = s.top();
	s.pop();
	n2 = s.top();
	s.pop();

	switch (op)
	{
		case '+':
			result = n2 + n1;	
			break;
		case '-':
			result = n2 - n1;	
			break;
		case '*':
			result = n2 * n1;	
			break;
		case '/':
			result = n2 / n1;	
			break;
	}
	s.push(result);
}

bool	checkInput(std::string input) {
	//cannot be something different from numbers, operators or spaces. cannot be two sequent digits
	std::string validOperators("+-/*");
	for (std::string::iterator it = input.begin(); it != input.end(); it++) {
		if ((!std::isdigit(*it) && !std::isspace(*it) && validOperators.find(*it) == validOperators.npos) || (std::isdigit(*it) && std::isdigit(*(it - 1))))
			return false;
	}
	return true;
}

void	printError(std::string &error) {
	std::cerr << "Error: " << error << std::endl;
}