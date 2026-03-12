#ifndef		ANIMAL_HPP
# define	ANIMAL_HPP

// Includes:
# include <iostream>
# include <string>

class	Animal
{
	private:

	protected:
		std::string	_type;
	public:
		Animal(); // Default Constructor;
		Animal(const Animal &copy); // Copy Constructor;
		Animal &operator=(const Animal &copy); // Copy Assignment Constructor
		~Animal(); // Destructor
};

#endif