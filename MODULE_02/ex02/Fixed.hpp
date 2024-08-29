#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

	private:
		int _fixedPoint;
		static const int _fractionalBits;
	
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

		//COMPARISON OPERATOR OVERLOADS
		bool operator>(const Fixed &);
		bool operator>=(const Fixed &);
		bool operator<(const Fixed &);
		bool operator<=(const Fixed &);
		bool operator==(const Fixed &);
		bool operator!=(const Fixed &);
		
		//ARITHMETIC OPERATOR OVERLOADS
		Fixed operator+(const Fixed &);
		Fixed operator-(const Fixed &);
		Fixed operator*(const Fixed &);
		Fixed operator/(const Fixed &);

		//INCREMENT/DECREMENT OPERATOR OVERLOADS
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

		//STATIC MEMBER FUNCTIONS
		static Fixed &min(Fixed&, Fixed&);
		static Fixed &max(Fixed&, Fixed&);
		static const Fixed &min(const Fixed&, const Fixed&);
		static const Fixed &max(const Fixed&, const Fixed&);
};

std::ostream &operator<<(std::ostream &o, const Fixed &f);

#endif
