#ifndef		SCAVTRAP_HPP
# define	SCAVTRAP_HPP

// Includes:
# include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap
{
	protected:
		bool	_guardState;
		static const unsigned int	defaultHitPoints = 100;
		static const unsigned int	defaultEnergyPoints = 50;
		static const unsigned int	defaultAttackDamage = 20;
	public:
		ScavTrap(); // Default Constructor
		ScavTrap(std::string name); // Name constructor
		ScavTrap(const ScavTrap &copy); // Copy Constructor
		ScavTrap &operator=(const ScavTrap &copy); // Copy Assignment constructor
		~ScavTrap(); // Destructor

	void	guardGate(void);
	void	attack(const std::string &target);
};

#endif