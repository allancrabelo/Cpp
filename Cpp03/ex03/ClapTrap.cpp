#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
	_name = "default";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap Name constructor called" << std::endl;
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "ClapTrap Copy Assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

// [Getters]:
std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " can't attack, it has no hit points left!" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " can't attack, it has no energy points left!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
		return ;
	}
	if (this->_hitPoints > amount)
		this->_hitPoints -= amount;
	else
		this->_hitPoints = 0;
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage! [" << this->_hitPoints << " hit points left]" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " can't be repaired, it has no hit points left!" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " can't be repaired, it has no energy points left!" << std::endl;
	else
	{
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " repairs itself and regains " << amount << " hit points! [" << this->_hitPoints << " hit points now]" << std::endl;
		this->_energyPoints--;
	}
}
