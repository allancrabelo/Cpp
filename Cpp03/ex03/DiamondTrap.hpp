#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

// Includes:
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class	DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	_name;
	public:
		DiamondTrap(); // Default Constructor
		DiamondTrap(std::string name); // Name Constructor
		DiamondTrap(const DiamondTrap &copy); // Copy Constructor
		DiamondTrap &operator=(const DiamondTrap &copy); // Copy Assignment Constructor
		~DiamondTrap(); // Destructor

		void	attack(const std::string& target);
		void	whoAmI(void);
};

#endif