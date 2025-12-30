#include "HumanB.hpp"

HumanB::HumanB(std::string Name)
{
	_name = Name;
	_weapon = NULL;
}

HumanB::HumanB(std::string Name, Weapon &NewWeapon)
{
	_name = Name;
	_weapon = &NewWeapon;
}

HumanB::~HumanB(void)
{
}

void HumanB::weaponSetter(Weapon &NewWeapon)
{
	_weapon = &NewWeapon;
}

void	HumanB::attack(void)
{
	if (_weapon == NULL)
		std::cout << _name << " has no weapon " << std::endl;
	else
		std::cout << _name << " atacks with their " << _weapon->getType() << std::endl;
}
