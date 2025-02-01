#include "conversions.hpp"

void	convertChar(std::string &toConvert) {

	char c = toConvert[0];
	int	i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	std::cout << "char --> '" << c << "'" << std::endl;
	std::cout << "int --> " << i << std::endl;
	std::cout << "float --> " << f << ".0f" << std::endl;
	std::cout << "double --> " << d << ".0" << std::endl;
}

void	convertInt(std::string &toConvert) {
	
	try {
		long l = std::atol(toConvert.c_str());

		if (l < std::numeric_limits<int>::min() || l > std::numeric_limits<int>::max())
			throw std::out_of_range("out of range");

		int i = static_cast<int>(l);
		char c = static_cast<char>(i);
		float f = static_cast<float>(i);
		double d = static_cast<double>(i);

		std::cout << "char --> ";
		if (i >= 33 && i <= 126)
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "non displayable" << std::endl; 
		std::cout << "int --> " << i << std::endl;
		std::cout << "float --> " << std::fixed << std::setprecision(1) << f  << "f" << std::endl;
		std::cout << "double --> " << d << std::endl;
	}
	catch(std::out_of_range &e) {
		printImpossibleCases();
		return ;
	}
}

void	convertFloat(std::string &toConvert) {
	
	try {
		double df = std::atof(toConvert.c_str());
		
		if (df < std::numeric_limits<float>::min() || df > std::numeric_limits<float>::max())
			throw std::out_of_range("out of range");

		float f = static_cast<float>(df);
		char c = static_cast<char>(f);
		int i = static_cast<int>(f);
		double d = static_cast<double>(f);

		std::cout << "char --> ";
		if (i >= 33 && i <= 126)
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "non displayable" << std::endl; 
		std::cout << "int --> " << i << std::endl;
		std::cout << "float --> " << std::fixed << std::setprecision(1) << f  << "f" << std::endl;
		std::cout << "double --> " << d << std::endl;
	}
	catch(std::out_of_range &e) {
		printImpossibleCases();
		return ;
	}
}

void	convertDouble(std::string &toConvert) {
	
	try {
		long double ld = std::strtold(toConvert.c_str(), NULL);

		if (ld < std::numeric_limits<double>::min() || ld > std::numeric_limits<double>::max())
			throw std::out_of_range("out of range");

		double d = static_cast<double>(ld);
		char c = static_cast<char>(d);
		int i = static_cast<int>(d);
		float f = static_cast<float>(d);

		std::cout << "char --> ";
		if (i >= 33 && i <= 126)
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "non displayable" << std::endl;
		std::cout << "int --> " << i << std::endl;
		std::cout << "float --> " << std::fixed << std::setprecision(1) << f  << "f" << std::endl;
		std::cout << "double --> " << d << std::endl;
	}
	catch(std::out_of_range &e) {
		printImpossibleCases();
		return ;
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
		std::cout << "float --> " << 0.0f/0.0f << "f" << std::endl; // NotANumber (undefined result)
		std::cout << "double --> "<< 0.0/0.0 << std::endl;
	}
}

void	printImpossibleCases(void) {

		std::cout << "char --> impossible" << std::endl;
		std::cout << "int --> impossible" << std::endl;
		std::cout << "float --> impossible" << std::endl;
		std::cout << "double --> impossible" << std::endl;
}
