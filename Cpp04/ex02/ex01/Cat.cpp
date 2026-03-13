#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat Default Constructor called." << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat Copy Constructor called." << std::endl;
	_type = copy._type;
	_brain = new Brain(*copy._brain);
}

Cat	&Cat::operator=(const Cat &copy)
{
	std::cout << "Cat Copy Assignment Constructor called." << std::endl;
	if (this != &copy)
	{
		_type = copy._type;
		*this->_brain = *copy._brain;
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called." << std::endl;
	delete _brain;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow Meow!" << std::endl;
}

void	Cat::setIdea(int index, const std::string &idea)
{
	this->_brain->setIdea(index, idea);
}

std::string	Cat::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}

const Brain	*Cat::getBrain(void) const
{
	return (this->_brain);
}
