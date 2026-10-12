#include "iter.hpp"

void printInt(const int &n)
{
	std::cout << n << " ";
}

void duplicate(int &n)
{
	n *= 2;
}

template <typename T>
void print(const T &x)
{
	std::cout << x << " ";
}

int main()
{
	int numbers[] = {1, 2, 3, 4, 5};
	std::cout << "int:        ";
	iter(numbers, 5, printInt);
	std::cout << std::endl;

	iter(numbers, 5, duplicate);
	std::cout << "duplicated:    ";
	iter(numbers, 5, printInt);
	std::cout << std::endl;

	const int fix[] = {10, 20, 30};
	std::cout << "const int:  ";
	iter(fix, 3, printInt);
	std::cout << std::endl;

	std::string names[] = {"42", "School", "Porto"};
	std::cout << "string:     ";
	iter(names, 3, print<std::string>);
	std::cout << std::endl;


	double doubles[] = {1.5, 2.5, 3.5};
	std::cout << "double:     ";
	iter(doubles, 3, print<double>);
	std::cout << std::endl;

	return (0);
}