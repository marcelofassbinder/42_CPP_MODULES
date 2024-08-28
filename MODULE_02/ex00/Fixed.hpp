#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

	private:
		int fixedPoint;
		static const int fractionalBits;
	
	public:
		//ORTHODOX CANONICAL FORM
		Fixed();
		Fixed(const Fixed&);
		Fixed &operator=(const Fixed&);
		~Fixed();

		//METHODS
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
