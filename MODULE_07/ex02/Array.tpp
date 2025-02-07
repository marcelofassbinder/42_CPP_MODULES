#include "Array.hpp"


//DEFAULT CONSTRUCTOR
template<typename T>
Array<T>::Array() : _elements(new T[0]), _size(0){}

//PARAMETRIZED CONSTRUCTOR
//By default, all the elements are initialized with 42
template<typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]), _size(n){
	for (unsigned int i = 0; i < n; i++) {
		this->_elements[i] = 42;
	}
}

//COPY CONSTRUCTOR
template<typename T>
Array<T>::Array(const Array &src) {

	this->_size = src.size();
	this->_elements = new T[this->_size];
	for(int i = 0; i < this->_size; i++) {
		this->_elements[i] = src.getElement(i);
	}
}

//ASSIGNMENT OPERATOR
template<typename T>
Array<T>& Array<T>::operator=(const Array &src) {
	if (this != &src) {
		delete[] this->_elements;
		this->_size = src.size();
		this->elements = new T[this->_size];
		for(int i = 0; i < this->_size; i++) {
			this->_elements[i] = src.getElement(i);
		}
	}
	return *this;
}

//DESTRUCTOR
template<typename T>
Array<T>::~Array() {
	delete[] this->_elements;
}

//EXCEPTION
template<typename T>
const char *Array<T>::NonexistentElement::what(void) const throw() {
	return "Tried to access nonexistent element";
}

//METHODS
template<typename T>
unsigned int	Array<T>::size(void) const{
	return this->_size;
}

template<typename T>
T& Array<T>::getElement(unsigned int index) const { 
	if (index >= this->size())
		throw NonexistentElement();
	return this->_elements[index];
}

template<typename T>
void	Array<T>::printArray(void) const {
	std::cout << "Array = {";
	for (unsigned int i = 0; i < this->size(); i++) {
		std::cout << GREEN BOLD << getElement(i) << RESET;
		if (i != this->size() - 1)
			std::cout << ", ";
	}
	std::cout << "}" << std::endl;
}

//OPERATOR OVERLOAD	
template<typename T>
T& Array<T>::operator[](unsigned int index) const {
		return getElement(index);
}
