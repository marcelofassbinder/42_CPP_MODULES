#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <ctype.h>
#include <limits>
#include <iomanip>

class ScalarConverter {

	private:
	//ORTHODOX CANONICAL FORM
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter& operator=(const ScalarConverter&);
		~ScalarConverter();

	public:
		static void	convert(const char *param);
};

enum e_data_type {

	CHAR = 1,
	INT,
	FLOAT,
	DOUBLE,
	IS_NULL,
	SPECIAL,
	INVALID

};

void	printImpossible(void);


#endif