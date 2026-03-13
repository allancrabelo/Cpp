#ifndef		CAT_HPP
# define	CAT_HPP

// Includes:
# include "Animal.hpp"

class Cat : public Animal
{
	private:
	
	protected:

	public:
		Cat(); // Default Constructor
		Cat(const Cat &copy); // Copy Constructor
		Cat &operator=(const Cat &copy); // Copy Constuctor
		~Cat(); // Destructor
	
	void	makeSound(void) const;
};

#endif