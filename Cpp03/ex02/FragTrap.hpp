#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

// Includes: 
# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	private:

	public:
		FragTrap(void); // Default constructor
		FragTrap(std::string name); // Name constructor
		FragTrap(const FragTrap &copy); // Copy constructor
		FragTrap &operator=(const FragTrap &copy); // Copy Assignment constructor
		~FragTrap(); // Destructor

		void	highFivesGuys(void);
};

#endif