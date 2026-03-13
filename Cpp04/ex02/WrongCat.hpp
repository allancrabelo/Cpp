#ifndef		WRONGCAT_HPP
# define	WRONGCAT_HPP

// Includes:
# include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
	protected:

	private:

	public:
		WrongCat(); // Default Constructor
		WrongCat(const WrongCat &copy); // Copy Constructor
		WrongCat &operator=(const WrongCat &copy); // Copy Assignment Constructor
		~WrongCat(); // Destructor

	void	makeSound(void) const;
};

#endif