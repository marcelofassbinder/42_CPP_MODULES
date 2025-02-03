#include "Data.hpp"

//CONSTRUCTOR
Data::Data() : _content(0) {}

//COPY CONSTRUCTOR
Data::Data(const Data &src) : _content(src._content) {}

//PARAMETRIZED CONSTRUCTOR
Data::Data(void *content) : _content(content){}

//ASSIGNMENT OPERATOR
Data& Data::operator=(const Data &src) {
	if (this != &src) {
		this->_content = src._content;
	}
	return *this;
}

//DESTRUCTOR
Data::~Data() {}

