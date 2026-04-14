#ifndef		ROBOTOMY_REQUEST_FORM_HPP
# define	ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"
# include <cstdlib>
 #include <ctime>

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;
	public:
		RobotomyRequestForm(); // Default constructor
		RobotomyRequestForm(const std::string& target); // Target constructor
		RobotomyRequestForm(const RobotomyRequestForm &copy); // Copy constructor
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy); // Copy Assignment Constructor
		~RobotomyRequestForm(); // Destructor
	
	virtual void executeAction() const;
};

#endif