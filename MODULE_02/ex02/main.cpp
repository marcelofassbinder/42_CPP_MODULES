#include "Fixed.hpp"

int main(void) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	/* Fixed a(5);
	Fixed b(5.01f);
	Fixed c;

	std::cout << "a = " << a <<std::endl;
	std::cout << "b = " << b <<std::endl;
	bool c = a > b;
	std::cout << "a is greater than b: " << c << std::endl;
	c = a >= b;
	std::cout << "a is greater or equal to b: " << c << std::endl;
	c = a < b;
	std::cout << "a is smaller than b: " << c << std::endl;
	c = a <= b;
	std::cout << "a is smaller or equal to b: " << c << std::endl;
	c = a == b;
	std::cout << "a is equal to b: " << c << std::endl;
	c = a != b;
	std::cout << "a is different from b: " << c << std::endl;

	std::cout << "c = " << c << std::endl;
	std::cout << "c = " << ++c << std::endl;
	std::cout << "c = " << c++ << std::endl;
	std::cout << "c = " << c << std::endl; */

}