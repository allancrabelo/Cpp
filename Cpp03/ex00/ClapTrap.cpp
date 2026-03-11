#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "Default constructor called" << std::endl;
	_name = "default";
	_healhPoints = 10;
	_energyPoints = 10;
	_attackDamagePoints = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Name constructor called" << std::endl;
	_name = name;
	_healhPoints = 10;
	_energyPoints = 10;
	_attackDamagePoints = 0;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_name = copy._name;
	this->_healhPoints = copy._healhPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamagePoints = copy._attackDamagePoints;
}

ClapTrap::ClapTrap &operator=(const ClapTrap &copy)
{
	std::cout << "Copy Assignement operator called" << std::endl;
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_healhPoints = copy._healhPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamagePoints = copy._attackDamagePoints;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

// [Getters]:
std::string	getName(void)
{
	return (this->_name);
}

unsigned int	getHealth(void)
{
	return(this->_healhPoints);
}

unsigned int	getEnergy(void)
{
	return (this->_energyPoints);
}

unsigned int	getDamage(void)
{
	return (this->_attackDamagePoints);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_attackDamagePoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks" << target << ", causing" << this->_attackDamagePoints << "of damage" << std::endl;
		this->_energyPoints--;
	}
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " can't attack" << target << " [NO Energy Points] " << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " can't attack" << target << " [NOT ENOUGH Energy Points] " << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_healhPoints > amount)
		this->_healhPoints -= amount;
	else if (this->_healhPoints > 0)
		this->_healhPoints = 0;
	else
	{
		std::cout << "ClapTrap " << this->_name << "already dead" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << "was attacked and lost " << amount << " health points. [ TOTAL: " << this->_healhPoints << " ]." << std::endl; 
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_healhPoints > 0 && this->_healhPoints + amount <= 10)
	{
		this->_healhPoints += amount;
		std::cout << "ClapTrap " << this->_name << "repair yourself and gain " << amount << " [ TOTAL: " << this->_healhPoints << " ].";
		_energyPoints--;
	}
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " don't have energy points." << std::endl;
	else if (this-> _healhPoints == 0)
		std::cout << "ClapTrap " << this->_name << " don't have health points." << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << "can't repair [ MAX HEALTH ]." << std::endl;
}
