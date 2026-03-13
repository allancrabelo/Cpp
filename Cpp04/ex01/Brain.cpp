#include "Brain.hpp"

Brain::Brain(void) : _ideas()
{
	std::cout << "Brain Default Constructor called." << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = "default";
	}
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain Copy Constructor called." << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = copy._ideas[i];
	}
}

Brain &Brain::operator=(const Brain &copy)
{
	std::cout << "Brain Copy Assignment Constructor called." << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
		{
			this->_ideas[i] = copy._ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain Destructor called." << std::endl;
}

void	Brain::setIdea(int index, const std::string &idea)
{
	if (index < 0 || index >= 100)
		return ;
	this->_ideas[index] = idea;
}

std::string	Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
		return ("");
	return (this->_ideas[index]);
}