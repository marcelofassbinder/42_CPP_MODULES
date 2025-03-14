#include "PmergeMe.hpp"

bool	checkInput(int argc, char **argv) {
	
	if (argc < 2)
		return false;
	
	for (int i = 1; i < argc; i++) {
		std::string input(argv[i]);
		for (std::string::iterator it = input.begin(); it != input.end(); it++) {
			if (!std::isdigit(*it))
				return false;
		}
	}
	return true;
}

void	printError(std::string error) {
	std::cerr << "Error: " << error << std::endl;
}

void	printVector(std::vector<int> v) {
	std::vector<int>::iterator it;

	for (it = v.begin(); it != v.end(); it++) {
		std::cout << *it;
		if (it != v.end() - 1)
			std::cout << ", ";
		else
			std::cout << std::endl;
	}
}

void	printDeque(std::deque<int> d) {
	std::deque<int>::iterator it;

	for (it = d.begin(); it != d.end(); it++) {
		std::cout << *it;
		if (it != d.end() - 1)
			std::cout << ", ";
		else
			std::cout << std::endl;
	}
}