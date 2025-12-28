#include "Zombie.hpp"

/**
 * @brief function to allocates to stack. Simple memory, but 
 * had a limited size (search: Stackoverflow).
 *
 * @param name
 * @return void
 */
void	randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.announce();
}
