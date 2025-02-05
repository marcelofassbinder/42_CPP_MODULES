#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>

class Array {

	private:
		T *_elements;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array&);
		Array& operator=(const Array&);
		~Array();

		int	size(void) const;
		T& getElement(int index) const;

		class NoExistantElement : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		
		T& operator[](unsigned int index) const;
};

#include "Array.tpp"

#endif