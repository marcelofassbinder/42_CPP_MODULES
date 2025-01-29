#include "ScalarConverter.hpp"

void	convertToChar(std::string &str) {

	std::cout << "char --> ";
	if (str.length() == 1 && isalpha(str[0])) 
		std::cout << static_cast<char>(str[0]) << std::endl;
	else if (str.length() == 1)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void	convertToInt(std::string &str) {
	std::cout << "int --> ";
	try {
		//int i = std::stoi(str);
		std::cout << static_cast<int>(str) << std::endl;
	}
	catch(std::exception &e) {
		std::cerr << "impossible" << std::endl;
	}
}

void	ScalarConverter::convert(const char* toConvert) {

	std::string str = toConvert;
	//DETECT DATA TYPE
	convertToChar(str);
	convertToInt(str);

}