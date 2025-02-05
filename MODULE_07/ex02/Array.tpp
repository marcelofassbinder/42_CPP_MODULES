#include "Array.hpp"

template<typename T>
Array<T>::Array() : _elements(new T[0]){}

template<typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]){}

template<typename T>
Array<T>::Array(const Array &src) {

	this->_elements = new T[src.size()];
	for(int i = 0; i < src.size(); i++) {
		this->_elements[i] = src._elements[i];
	}
}

template<typename T>
Array<T>& Array<T>::operator=(const Array &src) {
	if (this != &src) {
		delete this->_elements;
		this->elements = new T[src.size()];
		for(int i = 0; i < src.size(); i++) {
			this->_elements[i] = src._elements[i];
		}
	}
	return *this;
}

template<typename T>
Array<T>::~Array() {
	delete this->_elements;
}

template<typename T>
const char *Array<T>::NoExistantElement::what(void) const throw() {
	return "No Existant Element";
}

template<typename T>
int	Array<T>::size(void) const{

	int count = 0;

	while(this->_elements[count]) {
		count++;
	}
	return count;
}

template<typename T>
T& Array<T>::getElement(int index) const { //arrumar
	try {
		if (!this->_elements[index])
			throw NoExistantElement();
	}
	catch(NoExistantElement &e) {
		std::cout << "EXCEPTION CAUGHT: " << e.what() << std::endl;
		
	}
	return this->_elements[index];
}

template<typename T>
T& Array<T>::operator[](unsigned int index) const {
	return (getElement(index));

}
