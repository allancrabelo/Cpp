#ifndef		POINT_HPP
# define	POINT_HPP

//Includes:
# include "Fixed.hpp"
# include <iostream>

class	Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &copy);
		Point &operator=(const Point &copy);
		~Point();

	Fixed const	getX(void) const;
	Fixed const	getY(void) const;
};
	
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
