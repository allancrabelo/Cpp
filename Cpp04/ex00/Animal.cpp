#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal Default Constructor called." << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal Copy Constructor called." << std::endl;
	_type = copy._type;
}

Animal &Animal::operator=(const Animal &copy)
{
	std::cout << "Animal Copy Assignment Constructor called." << std::endl;
	if (this != &copy)
	{
		_type = copy._type;
	}
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal Destructor called." << std::endl;
}

