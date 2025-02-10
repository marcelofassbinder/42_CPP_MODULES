#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>

#define RED "\e[31m"
#define BLUE "\e[34m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BOLD "\e[1m"
#define RESET "\e[0m"

class Span {

	private:
		std::vector<int>	_vector;
		unsigned int		_limit;

	public:
		//ORTHODOX CANONICAL FORM
		Span();
		Span(unsigned int N);
		Span(const Span&);
		Span& operator=(const Span&);
		~Span();

		//METHODS SUBJECT
		void			addNumber(int newNumber);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
		void			fill(std::vector<int>::iterator beg, std::vector<int>::iterator end);

		//GETTER
		std::vector<int> &getVector(void);

		//PRINT
		void	print(void);
		

};

#endif