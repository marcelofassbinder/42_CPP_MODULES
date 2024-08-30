#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
	//std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float f1, const float f2) : _x(f1), _y(f2){
	//std::cout << "Parametrized constructor called" << std::endl;
}

Point::Point(const Point &src) : _x(src._x), _y(src._y) {
	//std::cout << "Copy constructor called" << std::endl;
}

Point& Point::operator=(const Point &src) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if(this != &src) {
		(Fixed)this->_x = src._x;
		(Fixed)this->_y = src._y;
	} 
	return (*this);
}

Point::~Point() {
	//std::cout << "Destructor called" << std::endl;
}

bool Point::operator==(const Point &src) const {
	return (this->getX() == src.getX() && this->getY() == src.getY());
}

Fixed Point::getX() const {
	return (this->_x);
}

Fixed Point::getY() const {
	return (this->_y);	
}

Fixed Point::getArea(Point a, Point b) const {
	Fixed area;

	//area = 1/2 * |(x1 * (y2 - y3) + x2 (y3 -y1) + x3 * (y1 -y2))|
	area = (this->getX() * (a.getY() - b.getY())) + (a.getX() * (b.getY() - this->getY())) + (b.getX() * (this->getY() - a.getY()));
	area = area / 2;
	if (area < 0)
		return area * (-1);
	return area;
}

std::ostream& operator<<(std::ostream &output, const Point &point) {
	output << "(" << point.getX() << ", " << point.getY() << ")";
	return output;
}
