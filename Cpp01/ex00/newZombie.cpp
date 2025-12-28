#include "Zombie.hpp"

/**
 * @brief newZobie function do:
 *  
 *  1 - Create a new Zobie
 *  2 - Name it
 * 
 * Using 'new' a operator usually used to allocate new
 * block of memory. Basically creating a new object. Allocted
 * at HEAP  more flexible but the memory needs to be managed
 * manually)
 * @return a new zombie out of scope
 */
Zombie* newZombie(std::string name)
{
	Zombie* zombie;

	zombie = new Zombie(name);
	return (zombie);
}
