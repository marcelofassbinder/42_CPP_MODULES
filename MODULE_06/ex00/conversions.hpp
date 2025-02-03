#ifndef CONVERSIONS_HPP
#define CONVERSIONS_HPP

#include <iostream>
#include <ctype.h>
#include <limits>
#include <cstdlib>
#include <iomanip>

#define INT_MIN std::numeric_limits<int>::min()
#define INT_MAX std::numeric_limits<int>::max()
#define FLOAT_MIN -(std::numeric_limits<float>::max())
#define FLOAT_MAX std::numeric_limits<float>::max()
#define DOUBLE_MIN -(std::numeric_limits<double>::max())
#define DOUBLE_MAX std::numeric_limits<double>::max()

enum e_data_type {

	CHAR = 1,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL,
	IS_NULL,
	INVALID

};

//CHECK DATA TYPE
e_data_type	identifyDataType(std::string &toConvert);
bool		isChar(std::string &toConvert);
bool		isInteger(std::string &toConvert);
bool		isFloat(std::string &toConvert);
bool		isDouble(std::string &toConvert);
bool		isSpecial(std::string &toConvert);

//CONVERSIONS
void		convertChar(std::string &toConvert);
void		convertInt(std::string &toConvert);
void		convertFloat(std::string &toConvert);
void		convertDouble(std::string &toConvert);
void		convertSpecial(std::string &toConvert);

void		printImpossibleCases(void);

#endif