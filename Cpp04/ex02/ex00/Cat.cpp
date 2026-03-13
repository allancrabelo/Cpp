#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat Default Constructor called." << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat Copy Constructor called." << std::endl;
	_type = copy._type;
}

Cat	&Cat::operator=(const Cat &copy)
{
	std::cout << "Cat Copy Assignment Constructor called." << std::endl;
	if (this != &copy)
	{
		_type = copy._type;
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called." << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow Meow!" << std::endl;
}
