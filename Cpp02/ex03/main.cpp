#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	// Triangle with vertices A, B, C
	Point	a(2.02f, 0.83f);
	Point	b(2.66f, 1.68f);
	Point	c(1.24f, 1.91f);

	// Point inside the triangle
	Point	p(2.07f, 1.46f);

	std::cout << "=== [ Test 1 ]: Point inside the triangle ===" << std::endl;
	if (bsp(a, b, c, p) == true)
		std::cout << "Point p is inside the triangle." << std::endl;
	else
		std::cout << "Point p is not inside the triangle." << std::endl;

	// Point outside the triangle (far to the right)
	Point	p2(5.0f, 5.0f);

	std::cout << "\n=== [ Test 2 ]: Point outside the triangle ===" << std::endl;
	if (bsp(a, b, c, p2) == true)
		std::cout << "Point p2 is inside the triangle." << std::endl;
	else
		std::cout << "Point p2 is not inside the triangle." << std::endl;

	// Point outside the triangle (below)
	Point	p3(2.0f, 0.0f);

	std::cout << "\n=== [ Test 3 ]: Point outside (below) ===" << std::endl;
	if (bsp(a, b, c, p3) == true)
		std::cout << "Point p3 is inside the triangle." << std::endl;
	else
		std::cout << "Point p3 is not inside the triangle." << std::endl;

	return (0);
}
