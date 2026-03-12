#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap Name constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	std::cout << "FragTrap Copy Assignment operator called" << std::endl;
	if (this != &copy)
		ClapTrap::operator=(copy);
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_hitPoints <= 0)
		std::cout << "FragTrap " << this->_name << " is dead [High five Forbidden]!" << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " requests a positive high five!" << std::endl;
}