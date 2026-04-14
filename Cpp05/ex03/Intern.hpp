#ifndef		INTERN_HPP
# define	INTERN_HPP

// Includes:
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		AForm	*createShrubbery(const std::string &target) const;
		AForm	*createRobotomy(const std::string &target) const;
		AForm	*createPresidential(const std::string &target) const;

	public:
		Intern(); // Default Constructor
		Intern(const Intern &copy); // Copy Constructor
		Intern &operator=(const Intern &copy); // Copy Assignment Constructor
		~Intern(); // Destructor

		AForm	*makeForm(const std::string &name, const std::string &target) const;
	
	class InternException : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return "Intern could not find the requested form name.";
		}
	};
};
#endif