#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <cstdlib>

class BitcoinExchange {

	private:
	//MAP TO STORE THE BTC RATES
		static std::map<std::string, float>	_map;
	//ORTHODOX CANONICAL FORM
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange&);
		BitcoinExchange& operator=(const BitcoinExchange&);
		~BitcoinExchange();

	public:
		static void	calculateBtc(const char* inputFile);
		static void	readData();
		static void	convertBtc(std::pair<std::string, std::string> &dateValue);
};

//AUXILIAR FUNCTIONS
std::pair<std::string, std::string>	extractDateValue(std::string &line);
void								printError(const std::string& error, bool exitFlag);
int									countChar(std::string &str, char c);
bool								strIsNumeric(std::string &str);
bool								checkDate(std::string &date);
bool								checkValue(std::string &value);
bool								isLeapYear(int year);

#endif