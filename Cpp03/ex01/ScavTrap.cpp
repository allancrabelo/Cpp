#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_guardState = false;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Name constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_guardState = false;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	_guardState = copy._guardState;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	std::cout << "ScavTrap Copy Assignment operator called" << std::endl;
	if (this != &copy)
	{
		ClapTrap::operator=(copy);
		_guardState = copy._guardState;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints == 0)
		std::cout << "ScavTrap " << this->_name << " can't attack, it has no hit points left!" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ScavTrap " << this->_name << " can't attack, it has no energy points left!" << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void	ScavTrap::guardGate(void)
{
	if (this->_guardState == false)
	{
		this->_guardState = true;
		std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_name << " is already in Gate keeper mode." << std::endl;
}