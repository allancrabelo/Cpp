#ifndef		BUREAUCRAT_HPP
# define	BUREAUCRAT_HPP

// Includes:
# include <iostream>
# include <string>

class		Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;// [1 - Highest ~ 150 - Lowest]
	public:
		Bureaucrat(); // Default Constructor
		Bureaucrat(const std::strig name, int grade); // Named Constructor
		Bureaucrat(const Bureaucrat &copy); // Copy Constructor
		Bureaucrat &operator=(const Bureaucrat &copy); // Copy Assignment Constructor
		~Bureaucrat(); // Destructor

		
};
