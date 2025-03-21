#include "RPN.hpp"

int main(int argc, char **argv) {

	if (argc != 2) 
		return (printError("Wrong numer of arguments."), 1);
	RPN::calculate(argv[1]);
}