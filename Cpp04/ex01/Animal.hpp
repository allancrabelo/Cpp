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
		virtual ~Animal(); // Destructor

		std::string	getType(void) const;

		virtual void	makeSound(void) const;
};

#endif