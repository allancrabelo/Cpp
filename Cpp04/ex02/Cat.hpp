#ifndef		CAT_HPP
# define	CAT_HPP

// Includes:
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*_brain;
	protected:

	public:
		Cat(); // Default Constructor
		Cat(const Cat &copy); // Copy Constructor
		Cat &operator=(const Cat &copy); // Copy Constuctor
		~Cat(); // Destructor
	
		void		makeSound(void) const;
		void		setIdea(int index, const std::string &idea);
		std::string	getIdea(int index) const;
		const Brain	*getBrain(void) const;
};

#endif