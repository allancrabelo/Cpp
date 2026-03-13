#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog Default Constructor called." << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog Copy Constructor called." << std::endl;
	_type = copy._type;
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "Dog Copy Assignment Constructor called." << std::endl;
	if (this != &copy)
	{
		_type = copy._type;
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor called." << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof Woof!" << std::endl;
}
