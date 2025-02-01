#include "conversions.hpp"

bool	isChar(std::string &toConvert) {

	if (toConvert.length() == 1 && isprint(toConvert[0]) && !isdigit(toConvert[0]))
		return true;
	return false;
}

bool	isInteger(std::string &toConvert) {

	int signal = 0;
	if (toConvert[0] == '-' || toConvert[0] == '+')
		signal++;
	for (size_t i = signal; i < toConvert.length(); i++) {
		if (!isdigit(toConvert[i]))
			return false;
	}
	return true;
}

bool	isFloat(std::string &toConvert) {

	int	dotsCount = 0;
	int	floatCount = 0;
	size_t len = toConvert.length();

	for (size_t i = 0; i < len; i++) {
		if (isdigit(toConvert[i]) || toConvert[i] == '-' || toConvert[i] == '+')
			continue;
		else if (toConvert[i] == '.')
			dotsCount++;
		else if (toConvert[i] == 'f')
			floatCount++;
		else
			return false;
	}
	if (toConvert.length() > 2 && dotsCount == 1 && floatCount == 1 && toConvert[len - 1] == 'f')
		return true;
	else
		return false;
}

bool	isDouble(std::string &toConvert) {

	int dotsCount = 0;

	for(size_t i = 0; i < toConvert.length(); i++) {
		if (isdigit(toConvert[i]) || toConvert[i] == '-' || toConvert[i] == '+')
			continue ;
		else if (toConvert[i] == '.')
			dotsCount++;
		else
			return false;
	}
	if (toConvert.length() > 1 && dotsCount == 1)
		return true;
	else
		return false;
}

bool	isSpecial(std::string &toConvert) {

	std::string possibleStrings[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

	for (int i = 0; i < 6; i++) {
		if (toConvert.compare(possibleStrings[i]) == 0)
			return true;
	}
	return false;
}

e_data_type	identifyDataType(std::string &toConvert) {

	if (toConvert.find("++") != std::string::npos || toConvert.find("--") != std::string::npos ||
			toConvert.find("+-") != std::string::npos || toConvert.find("-+") != std::string::npos)
		return INVALID;
	else if (toConvert.empty())
		return IS_NULL;
	else if (isChar(toConvert))
		return CHAR;
	else if (isInteger(toConvert))
		return INT;
	else if (isFloat(toConvert))
		return FLOAT;
	else if (isDouble(toConvert))
		return DOUBLE;
	else if (isSpecial(toConvert))
		return SPECIAL;
	else
		return INVALID;	
}