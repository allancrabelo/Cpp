#ifndef	ZOMBIE_HPP
# define ZOMBIE_HPP

// Includes:
# include <iostream>
# include <string>
# include <cstdlib>

// Defines:
# define EXIT_SUCCESS			0
# define EXIT_FAILURE			1

# define ERR_NUMBER_ARGUMENTS	"[ERROR 100] Usage Error: ./MoarBrainz <number of zombies>"

# define ERR_NUMBER_ZOMBIES		"[ERROR 200] Input Error: Zombies number negative or NULL."
# define ERR_INPUT_NOT_NUMBER	"[ERROR 201] Input Error: Input is not a number."
# define ERR_INPUT_NEGATIVE		"[ERROR 202] Input Error: Input is negative number."

// Classes:
class	Zombie
{
	private:
		std::string	_name;
	public:
		Zombie(std::string	name);
		Zombie();
		~Zombie();

		void	announce(void);
		void	nameSetter(std::string	name);
};

// Functions:
Zombie* zombieHorde( int N, std::string name );

#endif
