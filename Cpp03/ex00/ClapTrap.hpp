#ifndef	CLAPTRAP_HPP
# define CLAPTRAP_HPP

// Includes;
# include <iostream>
# include <string>

class	ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_healhPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamagePoints;
	public:
		ClapTrap(); // Default Constructor
		ClapTrap(std::string	name); // Constructor with name
		ClapTrap(const ClapTrap &copy); // Copy Constructor
		ClapTrap &operator=(const ClapTrap &copy); // Copy Assignement operator overload
		~ClapTrap(); // Destructor

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		// [Getters]:
		std::string		getName(void);
		unsigned int	getHealth(void);
		unsigned int	getEnergy(void);
		unsigned int	getDamage(void);
};

#endif