#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	_name = "default";
	ClapTrap::_name = _name + "_clap_name";
	_hitPoints = FragTrap::defaultHitPoints;
	_energyPoints = ScavTrap::defaultEnergyPoints;
	_attackDamage = FragTrap::defaultAttackDamage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	std::cout << "DiamondTrap Name constructor called" << std::endl;
	_name = name;
	_hitPoints = FragTrap::defaultHitPoints;
	_energyPoints = ScavTrap::defaultEnergyPoints;
	_attackDamage = FragTrap::defaultAttackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	_name = copy._name;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
	std::cout << "DiamondTrap Copy Assignment operator called" << std::endl;
	if (this != &copy)
	{
		ClapTrap::operator=(copy);
		_name = copy._name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "I am DiamondTrap " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}