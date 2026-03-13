#ifndef		DOG_HPP
# define	DOG_HPP

// Include:
# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal
{
	private:
		Brain	*_brain;

	protected:

	public:
		Dog(); // Default Constructor
		Dog(const Dog &copy); // Copy Constructor
		Dog &operator=(const Dog &copy); // Copy Assignment Constructor
		~Dog(); // Destructor

		void		makeSound(void) const;
		void		setIdea(int index, const std::string &idea);
		std::string	getIdea(int index) const;
		const Brain	*getBrain(void) const;
};

#endif