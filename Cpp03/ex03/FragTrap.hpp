#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

// Includes: 
# include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
	protected:
		static const unsigned int	defaultHitPoints = 100;
		static const unsigned int	defaultEnergyPoints = 100;
		static const unsigned int	defaultAttackDamage = 30;
	public:
		FragTrap(void); // Default constructor
		FragTrap(std::string name); // Name constructor
		FragTrap(const FragTrap &copy); // Copy constructor
		FragTrap &operator=(const FragTrap &copy); // Copy Assignment constructor
		~FragTrap(); // Destructor

		void	highFivesGuys(void);
};

#endif