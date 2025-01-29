#include "ScalarConverter.hpp"

//CONSTRUCTOR
ScalarConverter::ScalarConverter(){}

//COPY CONSTRUCTOR
ScalarConverter::ScalarConverter(const ScalarConverter &src) {}

//ASSIGNMENT OPERATOR
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &src) {
	return *this;
}

//DESTRUCTOR
ScalarConverter::~ScalarConverter() {}

//CHECK DATA TYPE

bool	isInteger(std::string toConvert) { //arrumar quando ha mais de um sinal

	int i = 0;
	if (toConvert[0] == '-' || toConvert[0] == '+')
		i++;
	for (i = i; i < toConvert.length(); i++) {
		if (!isdigit(toConvert[i]))
			return false;
	}
	return true;
}

bool	isFloat(std::string toConvert) {

	int	dotsCount = 0;
	int	floatCount = 0;

	for (int i = 0; i < toConvert.length(); i++) {
		if (isdigit(toConvert[i]) || toConvert[i] == '-' || toConvert[i] == '+')
			continue;
		else if (toConvert[i] == '.')
			dotsCount++;
		else if (toConvert[i] == 'f')
			floatCount++;
		else
			return false;
	}
	if (toConvert.length() > 2 && dotsCount == 1 && floatCount == 1)
		return true;
	else
		return false;
}

bool	isDouble(std::string toConvert) {

	int dotsCount = 0;

	for(int i = 0; i < toConvert.length(); i++) {
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

bool	isSpecial(std::string toConvert) {

	std::string possibleStrings[6] = {"-inff", "+inff", "nanff", "-inf", "+inf", "nan"};

	for (int i = 0; i < 6; i++) {
		if (toConvert.compare(possibleStrings[i]) == 0)
			return true;
	}
	return false;
}

e_data_type	identifyDataType(std::string toConvert) {

	if (toConvert.find("++") != std::string::npos || toConvert.find("--") != std::string::npos ||
			toConvert.find("+-") != std::string::npos || toConvert.find("-+") != std::string::npos)
		return INVALID;
	else if (toConvert.empty())
		return IS_NULL;
	else if (toConvert.length() == 1 && isprint(toConvert[0]))
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

void	convertChar(std::string &toConvert) {

	char c = toConvert[0];
	int	i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	std::cout << "char --> " << c << std::endl;
	std::cout << "int --> " << i << std::endl;
	std::cout << "float --> " << f << ".0f" << std::endl;
	std::cout << "double --> " << d << ".0" << std::endl;
}

void	convertInt(std::string &toConvert) {
	
	try {
		int i = std::stoi(toConvert);

		char c = static_cast<char>(i);
		float f = static_cast<float>(i);
		double d = static_cast<double>(i);

		std::cout << "char --> ";
		if (c >= 33 && c <= 126)
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "non displayable" << std::endl; 
		std::cout << "int --> " << i << std::endl;
		std::cout << "float --> " << std::fixed << std::setprecision(1) << f  << "f" << std::endl;
		std::cout << "double --> " << d << std::endl;
	}
	catch(std::out_of_range &e) {
		printImpossible();
		return ;
	}
}

void	convertFloat(std::string &toConvert) {
	
	try {
		float f = std::stof(toConvert);

		char c = static_cast<char>(f);
		int i = static_cast<int>(f);
		double d = static_cast<double>(f);

		std::cout << "char --> ";
		if (c >= 33 && c <= 126)
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "non displayable" << std::endl; 
		std::cout << "int --> " << i << std::endl;
		std::cout << "float --> " << std::fixed << std::setprecision(1) << f  << "f" << std::endl;
		std::cout << "double --> " << d << std::endl;
	}
	catch(std::out_of_range &e) {
		printImpossible();
		return ;
	}
}

void	convertDouble(std::string &toConvert) {
	
	try {
		double d = std::stod(toConvert);

		char c = static_cast<char>(d);
		int i = static_cast<int>(d);
		float f = static_cast<float>(d);

		std::cout << "char --> ";
		if (c >= 33 && c <= 126)
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "non displayable" << std::endl; 
		std::cout << "int --> " << i << std::endl;
		std::cout << "float --> " << std::fixed << std::setprecision(1) << f  << "f" << std::endl;
		std::cout << "double --> " << d << std::endl;
	}
	catch(std::out_of_range &e) {
		printImpossible();
		return ;
	}
}

void	printImpossible(void) {

		std::cout << "char --> impossible" << std::endl;
		std::cout << "int --> impossible" << std::endl;
		std::cout << "float --> impossible" << std::endl;
		std::cout << "double --> impossible" << std::endl;
}

void	ScalarConverter::convert(const char* param) {

	std::string toConvert = param;
	e_data_type dataType = identifyDataType(toConvert);

	switch (dataType) {
		case CHAR:
			std::cout << "IS CHAR!" << std::endl;
			convertChar(toConvert);
			break;
		case INT:
			std::cout << "IS INT!" << std::endl;
			convertInt(toConvert);
			break;
		case FLOAT:
			std::cout << "IS FLOAT!" << std::endl;
			convertFloat(toConvert);
			break;
		case DOUBLE:
			std::cout << "IS DOUBLE!" << std::endl;
			convertDouble(toConvert);
			break;
		case IS_NULL:
			std::cout << "IS NULL!" << std::endl;
			break;
		case SPECIAL:
			std::cout << "IS SPECIAL!" << std::endl;
			break;
		default:
			printImpossible();
	}
	//DETECT DATA TYPE
/* 	convertToChar(toConvert);
	convertToInt(toConvert);
 */
}