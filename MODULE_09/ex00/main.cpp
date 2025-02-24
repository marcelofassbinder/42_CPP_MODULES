#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {

	if (argc != 2)
		printError("Invalid argument.", 1);
	BitcoinExchange::calculateBtc(argv[1]);

}