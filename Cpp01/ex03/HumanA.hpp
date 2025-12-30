#ifndef HUMANA_HPP
# define HUMANA_HPP

// Includes:
# include "Weapon.hpp"
# include <string>
# include <iostream>

// Class:
class HumanA
{
	private:
		Weapon	&_weapon;
		std::string	_name;

	public:
		HumanA(std::string Name, Weapon &NewWeapon);
		~HumanA(void);

		void	attack(void);
};

#endif
