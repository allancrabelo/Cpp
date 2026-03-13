#ifndef		DOG_HPP
# define	DOG_HPP

// Include:
# include "Animal.hpp"

class	Dog : public Animal
{
	private:

	protected:

	public:
		Dog(); // Default Constructor
		Dog(const Dog &copy); // Copy Constructor
		Dog &operator=(const Dog &copy); // Copy Assignment Constructor
		~Dog(); // Destructor

	void	makeSound(void) const;
};

#endif