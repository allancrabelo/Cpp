#ifndef		SHRUBBERY_CREATION_FORM_HPP
# define	SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
	public:
		ShrubberyCreationForm(); // Constructor
		ShrubberyCreationForm(const std::string &target); // Target Constructor
		ShrubberyCreationForm(const	ShrubberyCreationForm &copy); // Copy constructor
		ShrubberyCreationForm &operator=(const	ShrubberyCreationForm &copy); // Copy Assignment constructor
		~ShrubberyCreationForm();

		virtual void	executeAction() const;
};

#endif