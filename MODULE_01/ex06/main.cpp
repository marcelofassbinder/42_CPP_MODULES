#include "Harl.hpp"

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cerr << "Error!\nNumber of arguments must be 2!"<< std::endl;
		return 1;
	}

	Harl harlInstance;
	harlInstance.complain(argv[1]);
}