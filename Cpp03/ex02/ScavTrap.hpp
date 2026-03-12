#ifndef		SCAVTRAP_HPP
# define	SCAVTRAP_HPP

// Includes:
# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	private:
		bool	_guardState;
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