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
	std::string date, value;
	std::string::iterator it;
	int pipePos = 0;
	for(it = line.begin(); *it != '|'; it++)
		pipePos++;
	date.assign(line, 0, pipePos);
	value.assign(line, pipePos + 1, line.length());
	
	std::pair<std::string, std::string> newPair;
	newPair.first = date;
	newPair.second = value;
	return newPair;
}

void	BitcoinExchange::searchInMap(std::string &line) {

	std::string date;
	float value, result, rate;
	std::pair<std::string, std::string> dateValue;

	dateValue = extractDateValue(line);
	date = dateValue.first;
	date.erase(date.length() - 1); //take out the space at the end
	value = atof(dateValue.second.c_str());

	std::map<std::string, float>::iterator it = BitcoinExchange::_map.upper_bound(date);
	if (it != BitcoinExchange::_map.begin())
		it--;
	rate = it->second;
	result = value * rate;
	std::cout  << date << " => " << value << " = " <<  result << std::endl;
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
		if (line == "date | value" || !isLineValid(line))
			continue ;
		BitcoinExchange::searchInMap(line);
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
	return true;
}

bool	checkValue(std::string &value) {
	if ((countChar(value, '.') != 0 && countChar(value, '.') != 1) || countChar(value, ' ') != 1)
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


bool	isLineValid(std::string &line) {
	std::pair<std::string, std::string> dateValue = extractDateValue(line);
	if (!checkDate(dateValue.first))
		return (printError("bad input => " + line, 0),false);
	if (!checkValue(dateValue.second))
		return (printError("not a valid number.", 0),false);
	return true;
}

void	printError(const std::string& error, bool exitFlag) {
	std::cerr << "Error: " << error << std::endl;
	if (exitFlag)
		exit(EXIT_FAILURE);
}