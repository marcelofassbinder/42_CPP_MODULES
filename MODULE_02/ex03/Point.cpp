#include "Point.hpp"

Point::Point() : _x(0), _y(0){
	//std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float f1, const float f2) {
	//std::cout << "Parametrized constructor called" << std::endl;
	this->_x = f1;
	this->_y = f2;
}

Point::Point(const Point &src) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Point& Point::operator=(const Point &src) {
	//std::cout << "Copy assignment operator called" << std::endl;
	this->_x = src._x;
	this->_y = src._y;
	return (*this);
}

Point::~Point() {
	//std::cout << "Destructor called" << std::endl;
}

bool Point::operator==(const Point &src) const{
	return (this->getX() == src.getX() && this->getY() == src.getY());
}

Fixed Point::getX() const {
	return (this->_x);
}

Fixed Point::getY() const {
	return (this->_y);
}

Fixed Point::getArea(Point a, Point b) const{
	Fixed area;

	//area = 1/2 * |(x1 * (y2 - y3) + x2 (y3 -y1) + x3 * (y1 -y2))|
	area = (this->getX() * (a.getY() - b.getY())) + (a.getX() * (b.getY() - this->getY())) + (b.getX() * (this->getY() - a.getY()));
	area = area / 2;
	if (area < 0)
		return area * (-1);
	return area;
}

std::ostream& operator<<(std::ostream &o, const Point &point) {
	o << "(" << point.getX() << ", " << point.getY() << ")";
	return o;
}
