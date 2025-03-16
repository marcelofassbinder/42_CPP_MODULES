#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {

	try {
		if (argc != 2)
			throw(std::runtime_error("Invalid argument."));
		BitcoinExchange::calculateBtc(argv[1]);
	}
	catch(std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}