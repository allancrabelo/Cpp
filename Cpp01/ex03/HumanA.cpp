#include "HumanA.hpp"

HumanA::HumanA(std::string Name, Weapon &NewWeapon):_weapon(NewWeapon)
{
	_name = Name;
}

HumanA::~HumanA(void)
{
}

void	HumanA::attack(void)
{
	std::cout << _name << "  attacks with their " << _weapon.getType() << std::endl;
}
