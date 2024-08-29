#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {

	private:
		Fixed _x;
		Fixed _y;

	public:
		//CANONICAL FORM
		Point();
		Point(const float, const float);
		Point(const Point&);
		Point &operator=(const Point&);
		~Point();

		bool operator==(const Point&) const;
		Fixed getX() const;
		Fixed getY() const;
		Fixed getArea(Point, Point) const;
};

std::ostream& operator<<(std::ostream&, const Point&);
bool bsp( Point const a, Point const b, Point const c, Point const point);


#endif