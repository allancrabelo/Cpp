#include "Point.hpp"

Point::Point(void) : _x(0.0f), _y(0.0f)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point::Point(const Point &copy) : _x(copy._x), _y(copy._y)
{
}

Point &Point::operator=(const Point &copy)
{
	(void)copy;
	return (*this);
}

Point::~Point(void)
{
}

Fixed const Point::getX() const
{
	return (this->_x);
}

Fixed const Point::getY() const
{
	return (this->_y);
}
