#include "Fixed.hpp"
#include "Point.hpp"

/*
* @attention Cross Product Formula -> (point - b) × (a - b)
*/
Fixed	crossProductCalculator(Point const i, Point const j, Point const point)
{
	float	fistPoint;
	float	secondPoint;

	fistPoint = ((point.getX().toFloat() - j.getX().toFloat()) * (i.getY().toFloat() - j.getY().toFloat()));
	secondPoint = ((i.getX().toFloat() - j.getX().toFloat()) * (point.getY().toFloat() - j.getY().toFloat()));

	return (Fixed(fistPoint - secondPoint));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	vertexAB = crossProductCalculator(a, b, point);
	Fixed	vertexBC = crossProductCalculator(b, c, point);
	Fixed	vertexCA = crossProductCalculator(c, a, point);

	if (vertexAB > 0  && vertexBC > 0 && vertexCA > 0)
		return (true);
	if (vertexAB < 0  && vertexBC < 0 && vertexCA < 0)
		return (true);
	return (false);
}
