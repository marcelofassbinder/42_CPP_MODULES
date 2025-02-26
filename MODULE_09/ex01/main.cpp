#include "RPN.hpp"

int main(int argc, char **argv) {

	if (argc != 2) 
		return (printError("Wrong numer of arguments."), 1);
	RPN::calculate(argv[1]);
	/* (void) argc;
	(void) argv;

	std::stack<int> a;

	a.push(1);
	a.pop();
	a.pop();
	a.pop(); */	
}