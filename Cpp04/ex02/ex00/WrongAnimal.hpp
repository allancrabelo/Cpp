#ifndef		WRONGANIMAL_HPP
# define	WRONGANIMAL_HPP

// Includes:
# include <iostream>
# include <string>

class	WrongAnimal
{
	private:

	protected:
		std::string	_type;
	public:
		WrongAnimal(); // Default Constructor
		WrongAnimal(const WrongAnimal &copy); // Copy Constructor
		WrongAnimal	&operator=(const WrongAnimal &copy); // Copy Assignment Constructor
		virtual ~WrongAnimal(); // Destructor

		std::string	getType(void) const;
		
		void	makeSound(void) const;
};

#endif