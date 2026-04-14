#ifndef		PRESIDENTIAL_PARDON_FORM_HPP
# define	PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;
	public:
		PresidentialPardonForm(); // Default constructor
		PresidentialPardonForm(const std::string &target); // Target Constructor
		PresidentialPardonForm(const PresidentialPardonForm &copy); // Copy Constructor
		PresidentialPardonForm &operator=(const PresidentialPardonForm &copy); // Copy Assingment Constructor
		~PresidentialPardonForm(); // Destructor

	virtual void executeAction() const;
};

#endif