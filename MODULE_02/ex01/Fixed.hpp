#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

	private:
		int fixedPoint;
		static const int fractionalBits;
	
	public:
		//ORTHODOX CANONICAL FORM
		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed&);
		Fixed &operator=(const Fixed&);
		~Fixed();

		//METHODS
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &o, const Fixed &f);

#endif
