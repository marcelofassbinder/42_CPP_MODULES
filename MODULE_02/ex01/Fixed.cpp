#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : fixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) {
	std::cout << "Int constructor called" << std::endl;
	this->fixedPoint = i * (1 << Fixed::fractionalBits);
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	this->fixedPoint = roundf(f * (1 << Fixed::fractionalBits));
}

Fixed::Fixed(const Fixed &f) {
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed& Fixed::operator=(const Fixed &f) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedPoint = f.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const {
	return ((float) this->fixedPoint / (float)(1 << Fixed::fractionalBits));
}

int Fixed::toInt(void) const {
	return ((int) this->fixedPoint / (1 << Fixed::fractionalBits));
}

int Fixed::getRawBits(void) const {
	return (this->fixedPoint);
}

void Fixed::setRawBits(int const raw) {
	this->fixedPoint = raw << Fixed::fractionalBits;
}

std::ostream &operator<<(std::ostream &o, const Fixed &f) {
	o << f.toFloat();
	return o;
}


