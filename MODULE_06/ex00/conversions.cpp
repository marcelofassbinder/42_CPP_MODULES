/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcelo <marcelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:22:52 by marcelo           #+#    #+#             */
/*   Updated: 2025/02/01 22:33:20 by marcelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.hpp"

void	convertChar(std::string &toConvert) {

	// - * - * - * - * - * - * - CHAR CONVERSION  - * - * - * - * - * - * -  
	char c = toConvert[0];
	std::cout << "char --> '" << c << "'" << std::endl;
	
	// - * - * - * - * - * - * - INTEGER CONVERSION  - * - * - * - * - * - * -  
	int	i = static_cast<int>(c);
	std::cout << "int --> " << i << std::endl;
	
	// - * - * - * - * - * - * - FLOAT CONVERSION  - * - * - * - * - * - * -  
	float f = static_cast<float>(c);
	std::cout << "float --> " << f << ".0f" << std::endl;
	
	// - * - * - * - * - * - * - DOUBLE CONVERSION  - * - * - * - * - * - * -  
	double d = static_cast<double>(c);
	std::cout << "double --> " << d << ".0" << std::endl;
}

void	convertInt(std::string &toConvert) {
	
	try {
		long l = std::atol(toConvert.c_str());

		if (l < INT_MIN || l > INT_MAX)
			throw std::out_of_range("impossible");
		
		int i = static_cast<int>(l);

		// - * - * - * - * - * - * - CHAR CONVERSION  - * - * - * - * - * - * -  
		char c = static_cast<char>(i);
		std::cout << "char --> ";
		if (l >= 33 && l <= 126)
			std::cout << "'" << c << "'" << std::endl;
		else if (l < 32 || l == 127)
			std::cout << "non displayable" << std::endl;
		else
			std::cout << "impossible" << std::endl;

		// - * - * - * - * - * - * - INTEGER CONVERSION  - * - * - * - * - * - * -  
		std::cout << "int --> " << i << std::endl;
		
		// - * - * - * - * - * - * - FLOAT CONVERSION  - * - * - * - * - * - * -  
		float f = static_cast<float>(i);
		std::cout << "float --> " << std::fixed << std::setprecision(1) << f  << "f" << std::endl;
		
		// - * - * - * - * - * - * - DOUBLE CONVERSION  - * - * - * - * - * - * -  
		double d = static_cast<double>(i);
		std::cout << "double --> " << d << std::endl;
	}
	catch(std::out_of_range &e) {
		printImpossibleCases();
	}
}

void	convertFloat(std::string &toConvert) {
	
	try {
		double df = std::atof(toConvert.c_str());

		if (df < FLOAT_MIN || df > FLOAT_MAX)
			throw std::out_of_range("impossible");
		
		float f = static_cast<float>(df);

		double d = static_cast<double>(f);

		// - * - * - * - * - * - * - CHAR CONVERSION  - * - * - * - * - * - * -  
		char c = static_cast<char>(f);
		std::cout << "char --> ";
		if (df >= 33 && df <= 126)
			std::cout << "'" << c << "'" << std::endl;
		else if (df < 32 || df == 127)
			std::cout << "non displayable" << std::endl;
		else
			std::cout << "impossible" << std::endl;
		
		// - * - * - * - * - * - * - INTEGER CONVERSION  - * - * - * - * - * - * -  
		std::cout << "int --> ";
		if (f >= INT_MIN && f <= INT_MAX) {
			int i = static_cast<int>(f);
			std::cout << i << std::endl;
		}
		else
			std::cout << "impossible" << std::endl;

		// - * - * - * - * - * - * - FLOAT CONVERSION  - * - * - * - * - * - * -  
		std::cout << "float --> " << std::fixed << std::setprecision(1) << f  << "f" << std::endl;

		// - * - * - * - * - * - * - DOUBLE CONVERSION  - * - * - * - * - * - * -  
		std::cout << "double --> " << d << std::endl;
	}
	catch(std::out_of_range &e) {
		printImpossibleCases();
	}
}

void	convertDouble(std::string &toConvert) {
	
	try {
		long double ld = std::strtold(toConvert.c_str(), NULL);

		if (ld < DOUBLE_MIN || ld > DOUBLE_MAX)
			throw std::out_of_range("impossible");

		double d = static_cast<double>(ld);

		// - * - * - * - * - * - * - CHAR CONVERSION  - * - * - * - * - * - * -  
		char c = static_cast<char>(d);
		std::cout << "char --> ";
		if (ld >= 33 && ld <= 126)
			std::cout << "'" << c << "'" << std::endl;
		else if (ld < 32 || ld == 127)
			std::cout << "non displayable" << std::endl;
		else
			std::cout << "impossible" << std::endl;
		
		// - * - * - * - * - * - * - INTEGER CONVERSION  - * - * - * - * - * - * -  
		std::cout << "int --> ";
		if (ld >= INT_MIN && ld <= INT_MAX) {
			int i = static_cast<int>(d);
			std::cout << i << std::endl;
		}
		else
			std::cout << "impossible" << std::endl;
		
		// - * - * - * - * - * - * - FLOAT CONVERSION  - * - * - * - * - * - * -  
		std::cout << "float --> ";
		if (ld >= FLOAT_MIN && ld <= FLOAT_MAX) {
			float f = static_cast<float>(d);
			std::cout << std::fixed << std::setprecision(1) << f  << "f" << std::endl;
		}
		else
			std::cout << "impossible" << std::endl;

		// - * - * - * - * - * - * - DOUBLE CONVERSION  - * - * - * - * - * - * -  
		std::cout << "double --> " << d << std::endl;
	}
	catch(std::out_of_range &e) {
		printImpossibleCases();
	}
}

void	convertSpecial(std::string &toConvert) {
		
	std::string possibleStrings[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

	std::cout << "char --> impossible" << std::endl;
	std::cout << "int --> impossible" << std::endl;

	if (toConvert == possibleStrings[0] || toConvert == possibleStrings[3]) {
		std::cout << "float --> " << -10.0f/0.0f << "f" << std::endl; //- infinite
		std::cout << "double --> " << -10.0/0.0 << std::endl;
	}
	else if (toConvert == possibleStrings[1] || toConvert == possibleStrings[4]) {
		std::cout << "float --> " << 10.0f/0.0f << "f" << std::endl;// +infinite
		std::cout << "double --> " << 10.0/0.0 << std::endl;
	}
	else {
		std::cout << "float --> " << "nanf" << std::endl; // NotANumber (undefined result)
		std::cout << "double --> "<< "nan"<< std::endl;
	}
}

void	printImpossibleCases(void) {

		std::cout << "char --> impossible" << std::endl;
		std::cout << "int --> impossible" << std::endl;
		std::cout << "float --> impossible" << std::endl;
		std::cout << "double --> impossible" << std::endl;
}
