#ifndef		BRAIN_HPP
# define	BRAIN_HPP

// Includes:
# include <iostream>
# include <string>

class Brain
{
	private:

	protected:
		std::string	_ideas[100];
	public:
		Brain(); // Default Constructor
		Brain(const Brain &copy); // Copy Constructor
		Brain &operator=(const Brain &copy); // Copy Assignment Constructor
		~Brain(); // Destructor

		void		setIdea(int index, const std::string &idea);
		std::string	getIdea(int index) const;

};

#endif