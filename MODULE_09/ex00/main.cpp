#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {

	if (argc != 2)
		return (printError("Invalid number of arguments"), 1);
	BitcoinExchange::calculateBtc(argv[1]);
}