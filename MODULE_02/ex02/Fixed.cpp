#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

// - - - - - - CANONICAL FORM - - - - - -
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

// - - - - - - MEMBER FUNCTIONS - - - - -
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

// - - - - - OPERATOR "<<" OVERLOAD - - - - - -
std::ostream &operator<<(std::ostream &o, const Fixed &f) {
	o << f.toFloat();
	return o;
}

// - - - - - COMPARISON OPERATORS - - - - - 
bool Fixed::operator>(const Fixed &src) {
	return (this->getRawBits() > src.getRawBits());
}

bool Fixed::operator>=(const Fixed &src) {
	return (this->getRawBits() >= src.getRawBits());
}

bool Fixed::operator<(const Fixed &src) {
	return (this->getRawBits() < src.getRawBits());
}

bool Fixed::operator<=(const Fixed &src) {
	return (this->getRawBits() <= src.getRawBits());
}

bool Fixed::operator==(const Fixed &src) {
	return (this->getRawBits() == src.getRawBits());
}

bool Fixed::operator!=(const Fixed &src) {
	return (this->getRawBits() != src.getRawBits());
}

// - - - - - ARITHMETIC OPERATORS - - - - - 
Fixed Fixed::operator+(const Fixed &src) {
	return(this->toFloat() + src.toFloat());
}

Fixed Fixed::operator-(const Fixed &src) {
	return(this->toFloat() - src.toFloat());
}

Fixed Fixed::operator*(const Fixed &src) {
	return(this->toFloat() * src.toFloat());
}

Fixed Fixed::operator/(const Fixed &src) {
	return(this->toFloat() / src.toFloat());
}

// - - - - - INCREMENT/DECREMENT OPERATORS - - - - - 
// Pre-increment, returning the reference of the instance
Fixed& Fixed::operator++() {
	this->_fixedPoint += 1;
	return (*this);
}

/*  Post-increment, incrementing and returning a copy of the instance(which 
has not been incremented yet) */
Fixed Fixed::operator++(int i) {
	(void) i;
	Fixed temp = *this;
	this->_fixedPoint += 1;
	return (temp);
}

Fixed& Fixed::operator--() {
	this->_fixedPoint -= 1;
	return (*this);
}

Fixed Fixed::operator--(int i) {
	(void) i;
	Fixed temp = *this;
	this->_fixedPoint -= 1;
	return (temp);
}

// - - - - - STATIC MEMBER FUNCTIONS - - - - - 
Fixed& Fixed::min(Fixed &instance1, Fixed &instance2) {
	if (instance1.getRawBits() <= instance2.getRawBits())
		return (instance1);
	return (instance2);
}

Fixed& Fixed::max(Fixed &instance1, Fixed &instance2) {
	if (instance1.getRawBits() >= instance2.getRawBits())
		return (instance1);
	return (instance2);
}

const Fixed& Fixed::min(const Fixed &instance1, const Fixed &instance2) {
	if (instance1.getRawBits() <= instance2.getRawBits())
		return (instance1);
	return (instance2);
}

const Fixed& Fixed::max(const Fixed &instance1, const Fixed &instance2) {
	if (instance1.getRawBits() >= instance2.getRawBits())
		return (instance1);
	return (instance2);
}