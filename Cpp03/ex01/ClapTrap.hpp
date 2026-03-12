#ifndef	CLAPTRAP_HPP
# define CLAPTRAP_HPP

// Includes;
# include <iostream>
# include <string>

class	ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
	public:
		ClapTrap(); // Default Constructor
		ClapTrap(std::string	name); // Constructor with name
		ClapTrap(const ClapTrap &copy); // Copy Constructor
		ClapTrap &operator=(const ClapTrap &copy); // Copy Assignment operator overload
		~ClapTrap(); // Destructor

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		// [Getters]:
		std::string		getName(void) const;
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;
};

#endif