#ifndef WEAPON_HPP
# define WEAPON_HPP

// Includes:
# include <string>

// Defines:
# define EXIT_SUCCESS	0
# define EXIT_FAILURE	1

//Class:
class	Weapon {
	private:
		std::string	_type;

	public:
		Weapon(const std::string& type);

		const std::string&	getType(void)const;
		void				setType(const std::string& newtype);
};

#endif
