#ifndef HUMANB_HPP
# define HUMANB_HPP

// Includes:
# include "Weapon.hpp"
# include <string>
# include <iostream>

// Class:
class	HumanB
{
	private:
		Weapon *_weapon;
		std::string	_name;	
	public:
		HumanB(std::string Name);
		HumanB(std::string Name, Weapon &NewWeapon);	
		~HumanB();

		void	attack(void);
		void	weaponSetter(Weapon &NewWeapon);
};

#endif
