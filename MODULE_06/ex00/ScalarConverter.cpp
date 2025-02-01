#include "ScalarConverter.hpp"

//CONSTRUCTOR
ScalarConverter::ScalarConverter(){}

//COPY CONSTRUCTOR
ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	(void) src;
}

//ASSIGNMENT OPERATOR
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &src) {
	(void) src;
	return *this;
}

//DESTRUCTOR
ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(const char* param) {

	std::string toConvert = param;
	e_data_type dataType = identifyDataType(toConvert);

	switch (dataType) {
		case CHAR:
			convertChar(toConvert);
			break;
		case INT:
			convertInt(toConvert);
			break;
		case FLOAT:
			convertFloat(toConvert);
			break;
		case DOUBLE:
			convertDouble(toConvert);
			break;
		case SPECIAL:
			convertSpecial(toConvert);
			break;
		case IS_NULL:
			std::cerr << "The parameter is NULL, please insert a valid string" << std::endl;
			break;
		default:
			printImpossibleCases();
	}
}