#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

#define RED "\e[31m"
#define BLUE "\e[34m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BOLD "\e[1m"
#define RESET "\e[0m"

template <typename T>

class Array {

	private:
		T 				*_elements;
		unsigned int	_size;

	public:
	//ORTHODOX CANONICAL FORM
		Array();
		Array(unsigned int n);
		Array(const Array&);
		Array& operator=(const Array&);
		~Array();

	//METHODS
		unsigned int	size(void) const;
		T& 				getElement(unsigned int index) const;
		void			printArray(void) const;

	//OPERATOR OVERLOAD
		T& 				operator[](unsigned int index) const;

	//EXCEPTION
		class NonexistentElement : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#include "Array.tpp"

#endif