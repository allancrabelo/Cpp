#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << "WrongCat Default Constructor called." << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat Copy Constructor called." << std::endl;
	_type = copy._type;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	std::cout << "WrongCat Copy Assignment Constructor called." << std::endl;
	if (this != &copy)
	{
		_type = copy._type;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called." << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat noises." << std::endl;
}
