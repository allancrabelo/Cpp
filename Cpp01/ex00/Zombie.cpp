#include "Zombie.hpp"

/**
 * @brief This is a implementaton archive, in
 * OOP it's important implement every declared class.
 */
Zombie::Zombie(std::string name)
{
	_name = name;
}

Zombie::~Zombie()
{
	std::cout << _name << " has been killed! 🧟" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

