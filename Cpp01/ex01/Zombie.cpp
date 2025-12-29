#include "Zombie.hpp"

Zombie::Zombie(std::string	name)
{
	_name = name;
}

Zombie::Zombie(void) {}

Zombie::~Zombie(void)
{
	std::cout << _name << " has been killed! 💀" << std::endl;

}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::nameSetter(std::string	name)
{
	this->_name = name;
}
