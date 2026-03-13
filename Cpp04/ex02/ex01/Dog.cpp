#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog Default Constructor called." << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog Copy Constructor called." << std::endl;
	_type = copy._type;
	_brain = new Brain(*copy._brain);
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "Dog Copy Assignment Constructor called." << std::endl;
	if (this != &copy)
	{
		_type = copy._type;
		*this->_brain = *copy._brain;
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor called." << std::endl;
	delete _brain;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof Woof!" << std::endl;
}

void	Dog::setIdea(int index, const std::string &idea)
{
	this->_brain->setIdea(index, idea);
}

std::string	Dog::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}

const Brain	*Dog::getBrain(void) const
{
	return (this->_brain);
}
