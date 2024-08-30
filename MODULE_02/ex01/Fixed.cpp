#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPoint = i * (1 << Fixed::_fractionalBits);
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPoint = roundf(f * (1 << Fixed::_fractionalBits));
}

Fixed::Fixed(const Fixed &f) {
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed& Fixed::operator=(const Fixed &f) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPoint = f.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const {
	return ((float) this->_fixedPoint / (float)(1 << Fixed::_fractionalBits));
}

int Fixed::toInt(void) const {
	return ((int) this->_fixedPoint / (1 << Fixed::_fractionalBits));
}

int Fixed::getRawBits(void) const {
	return (this->_fixedPoint);
}

void Fixed::setRawBits(int const raw) {
	this->_fixedPoint = raw;
}

std::ostream &operator<<(std::ostream &output, const Fixed &f) {
	output << f.toFloat();
	return output;
}
