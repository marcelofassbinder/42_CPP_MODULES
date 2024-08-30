#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {

	private:
		const Fixed _x;
		const Fixed _y;

	public:
		//CANONICAL FORM
		Point();
		Point(const float, const float);
		Point(const Point&);
		Point &operator=(const Point&);
		~Point();

		//OPERATOR "==" OVERLOAD
		bool operator==(const Point&) const;
		
		//MEMBER FUNCTIONS
		Fixed getX() const;
		Fixed getY() const;
		Fixed getArea(Point, Point) const;
};

std::ostream& operator<<(std::ostream&, const Point&);
bool bsp( Point const a, Point const b, Point const c, Point const point);


#endif