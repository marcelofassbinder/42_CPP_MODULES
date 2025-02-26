#include "BitcoinExchange.hpp"

std::map<std::string, float> BitcoinExchange::_map;

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {(void) src;}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &src) {
	(void) src;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::readData() {

	std::ifstream file("data.csv");
	if (!file)
		printError("could not open file.", 1);
	std::string line, key, value;
	while(std::getline(file, line)) {
		if (line.find_first_of("0123456789") == line.npos)
			continue ;
		key.assign(line, 0, 10);
		value.assign(line, 11, line.length());
		std::pair<std::string, float> newPair(key, atof(value.c_str()));
		BitcoinExchange::_map.insert(newPair);
	}
	file.close();
}

std::pair<std::string, std::string> extractDateValue(std::string &line) {
	
	if (line.find("|") == line.npos) // if did not encounter pipe
		return (std::pair<std::string, std::string>("", ""));
	std::string date, value;
	std::string::iterator it;
	int pipePos = 0;
	for(it = line.begin(); *it != '|'; it++)
		pipePos++;
	date.assign(line, 0, pipePos);
	value.assign(line, pipePos + 1, line.length());
	
	return (std::pair<std::string, std::string> (date, value));
}

void	BitcoinExchange::convertBtc(std::pair<std::string, std::string> &dateValue) {

	std::string date;
	float value, result, rate;

	date = dateValue.first;
	date.erase(date.length() - 1); //take out the space at the end
	value = atof(dateValue.second.c_str());

	std::map<std::string, float>::iterator it = BitcoinExchange::_map.upper_bound(date);
	if (it != BitcoinExchange::_map.begin())
		it--;
	rate = it->second;
	result = value * rate;
	std::cout << date << " => " << value << " = " <<  result << std::endl;
}

void	BitcoinExchange::calculateBtc(const char *inputFile) {
	
	BitcoinExchange::readData();
	
	std::ifstream file(inputFile);
	if (!file)
		printError("could not open file.", 1);
	std::string line;
	std::getline(file, line);
	if (line.compare("date | value") != 0)
		printError("'date | value' not find at first line", 1);
	while(std::getline(file, line)) {
		std::pair<std::string, std::string> dateValue = extractDateValue(line);
		if (!checkDate(dateValue.first))
			printError("bad input => " + line, 0);
		else if (!checkValue(dateValue.second))
			printError("not a valid number.", 0);
		else
			BitcoinExchange::convertBtc(dateValue);
	}
	file.close();
}	

int	countChar(std::string &str, char c) {
	int counter = 0;
	for (std::string::iterator it = str.begin(); it != str.end(); it++) {
		if (*it == c)
			counter++;
	}
	return counter;
}

bool	strIsNumeric(std::string &str) {
	for (std::string::iterator it = str.begin(); it != str.end(); it++) {
		if (!isdigit(*it))
			return false;
	}
	return true;
}

bool	isLeapYear(int year) {
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		return true;
	return false;
}

bool	checkDate(std::string &date) {
	if (date.length() != 11 || countChar(date, '-') != 2)
		return false;
	std::string year, month, day;
	year.assign(date, 0, 4);
	month.assign(date, 5, 2);
	day.assign(date, 8, 2);
	if (!strIsNumeric(year) || !strIsNumeric(month) || !strIsNumeric(day))
		return  false;
	int yearInt, monthInt, dayInt;
	yearInt = atoi(year.c_str());
	monthInt = atoi(month.c_str());
	dayInt = atoi(day.c_str());
	if (monthInt == 0 || monthInt > 12 || dayInt == 0 || dayInt > 31)
		return false;
	if (dayInt == 31 && (monthInt != 1 && monthInt != 3 && monthInt != 5 &&
			monthInt != 7 && monthInt != 8 && monthInt != 10 && monthInt != 12))
			return false; // months with 31 days check
	if (monthInt == 2 && (dayInt > 29 || (dayInt == 29 && !isLeapYear(yearInt))))
		return false; //february and leap year check
	return true;
}

bool	checkValue(std::string &value) {
	if ((countChar(value, '.') != 0 && countChar(value, '.') != 1) || countChar(value, ' ') != 1 || value[0] != ' ')
		return false;
	for (std::string::iterator it = value.begin(); it != value.end(); it++) {
		if (!isdigit(*it) && *it != '.' && *it != ' ')
			return false;
	}
	double valueDouble = atof(value.c_str());
	if (valueDouble < 0 || valueDouble > 1000)
		return false;
	return true;
}

void	printError(const std::string& error, bool exitFlag) {
	std::cerr << "Error: " << error << std::endl;
	if (exitFlag)
		exit(EXIT_FAILURE);
}