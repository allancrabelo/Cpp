#include "Zombie.hpp"

/**
 * @brief Main funciton of program
 *  
 * 
 * Using 'delete' a operator to delete the allocated memory
 * ceated with new.
 * @return EXIT_SUCCESS
 */
int	main(void)
{
	Zombie	*zombie;

	zombie = newZombie("Dancer Zombie");
	zombie->announce();

	randomChump("Singer Zombie");
	delete	zombie;
	return (EXIT_SUCCESS);
}
