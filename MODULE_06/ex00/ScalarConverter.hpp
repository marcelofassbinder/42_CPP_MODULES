#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "conversions.hpp"

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

#endif