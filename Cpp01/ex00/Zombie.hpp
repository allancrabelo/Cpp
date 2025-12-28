#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

// Includes:
# include <iostream>
# include <string>

// Defines:
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

class Zombie
{
	private:
		std::string	_name;
	public:
		Zombie(std::string	name);
		~Zombie();

	void	announce(void);
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);
#endif
